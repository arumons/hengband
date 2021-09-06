﻿#include "spell-realm/spells-hex.h"
#include "core/asking-player.h"
#include "core/player-redraw-types.h"
#include "core/player-update-types.h"
#include "core/window-redrawer.h"
#include "monster-race/monster-race.h"
#include "player/attack-defense-types.h"
#include "player/player-skill.h"
#include "realm/realm-hex-numbers.h"
#include "spell-realm/spells-song.h"
#include "spell/spell-info.h"
#include "spell/spells-execution.h"
#include "spell/technic-info-table.h"
#include "status/action-setter.h"
#include "system/floor-type-definition.h"
#include "system/monster-race-definition.h"
#include "system/monster-type-definition.h"
#include "system/player-type-definition.h"
#include "term/screen-processor.h"
#include "util/int-char-converter.h"
#include "view/display-messages.h"

#define MAX_KEEP 4 /*!<呪術の最大詠唱数 */

RealmHex::RealmHex(player_type *caster_ptr)
    : caster_ptr(caster_ptr)
{
}

/*!
 * @brief プレイヤーが詠唱中の全呪術を停止する
 */
bool RealmHex::stop_hex_spell_all()
{
    for (auto i = 0; i < 32; i++) {
        if (hex_spelling(this->caster_ptr, i)) {
            exe_spell(this->caster_ptr, REALM_HEX, i, SPELL_STOP);
        }
    }

    casting_hex_flags(this->caster_ptr) = 0;
    casting_hex_num(this->caster_ptr) = 0;
    if (this->caster_ptr->action == ACTION_SPELL) {
        set_action(this->caster_ptr, ACTION_NONE);
    }

    this->caster_ptr->update |= PU_BONUS | PU_HP | PU_MANA | PU_SPELLS;
    this->caster_ptr->redraw |= PR_EXTRA | PR_HP | PR_MANA;
    return true;
}

/*!
 * @brief プレイヤーが詠唱中の呪術から一つを選んで停止する
 */
bool RealmHex::stop_hex_spell()
{
    if (!hex_spelling_any(this->caster_ptr)) {
        msg_print(_("呪文を詠唱していません。", "You are not casting a spell."));
        return false;
    }

    if ((casting_hex_num(this->caster_ptr) == 1) || (this->caster_ptr->lev < 35)) {
        return this->stop_hex_spell_all();
    }

    char out_val[160];
    strnfmt(out_val, 78, _("どの呪文の詠唱を中断しますか？(呪文 %c-%c, 'l'全て, ESC)", "Which spell do you stop casting? (Spell %c-%c, 'l' to all, ESC)"),
        I2A(0), I2A(casting_hex_num(this->caster_ptr) - 1));
    screen_save();
    int sp[MAX_KEEP]{};
    char choice = 0;
    auto flag = select_spell_stopping(sp, out_val, &choice);
    screen_load();
    if (flag) {
        auto n = sp[A2I(choice)];
        exe_spell(this->caster_ptr, REALM_HEX, n, SPELL_STOP);
        casting_hex_flags(this->caster_ptr) &= ~(1UL << n);
        casting_hex_num(this->caster_ptr)--;
    }

    this->caster_ptr->update |= PU_BONUS | PU_HP | PU_MANA | PU_SPELLS;
    this->caster_ptr->redraw |= PR_EXTRA | PR_HP | PR_MANA;
    return flag;
}

/*!
 * @brief 中断する呪術を選択する
 * @param sp 詠唱中の呪術リスト
 * @param out_val 呪文名
 * @param choice 選択した呪文
 * @return 選択が完了したらtrue、キャンセルならばfalse
 */
bool RealmHex::select_spell_stopping(int *sp, char *out_val, char *choice)
{
    while (true) {
        this->display_spells_list(sp);
        if (!get_com(out_val, choice, true)) {
            return false;
        }

        if (isupper(*choice)) {
            *choice = static_cast<char>(tolower(*choice));
        }

        /* All */
        if (*choice == 'l') {
            screen_load();
            return this->stop_hex_spell_all();
        }

        if ((*choice < I2A(0)) || (*choice > I2A(casting_hex_num(this->caster_ptr) - 1))) {
            continue;
        }

        return true;
    }
}

void RealmHex::display_spells_list(int *sp)
{
    constexpr auto y = 1;
    constexpr auto x = 20;
    auto n = 0;
    term_erase(x, y, 255);
    prt(_("     名前", "     Name"), y, x + 5);
    for (auto spell = 0; spell < 32; spell++) {
        if (hex_spelling(this->caster_ptr, spell)) {
            term_erase(x, y + n + 1, 255);
            put_str(format("%c)  %s", I2A(n), exe_spell(this->caster_ptr, REALM_HEX, spell, SPELL_NAME)), y + n + 1, x + 2);
            sp[n++] = spell;
        }
    }
}

/*!
 * @brief 一定時間毎に呪術で消費するMPを処理する
 */
void RealmHex::check_hex()
{
    /* Spells spelled by player */
    if (this->caster_ptr->realm1 != REALM_HEX) {
        return;
    }

    if (!casting_hex_flags(this->caster_ptr) && !this->caster_ptr->magic_num1[1]) {
        return;
    }

    auto need_restart = this->check_restart();
    if (this->caster_ptr->anti_magic) {
        this->stop_hex_spell_all();
        return;
    }

    this->process_mana_cost(need_restart);
    this->gain_exp_from_hex();        

    /* Do any effects of continual spells */
    for (auto spell = 0; spell < 32; spell++) {
        if (hex_spelling(this->caster_ptr, spell)) {
            exe_spell(this->caster_ptr, REALM_HEX, spell, SPELL_CONT);
        }
    }
}

void RealmHex::process_mana_cost(const bool need_restart)
{
    auto need_mana = this->calc_need_mana();
    uint need_mana_frac = 0;
    s64b_div(&need_mana, &need_mana_frac, 0, 3); /* Divide by 3 */
    need_mana += (casting_hex_num(this->caster_ptr) - 1);

    auto enough_mana = s64b_cmp(this->caster_ptr->csp, this->caster_ptr->csp_frac, need_mana, need_mana_frac) < 0;
    if (!enough_mana) {
        this->stop_hex_spell_all();
        return;
    }

    s64b_sub(&(this->caster_ptr->csp), &(this->caster_ptr->csp_frac), need_mana, need_mana_frac);
    this->caster_ptr->redraw |= PR_MANA;
    if (!need_restart) {
        return;
    }

    msg_print(_("詠唱を再開した。", "You restart casting."));
    this->caster_ptr->action = ACTION_SPELL;
    this->caster_ptr->update |= PU_BONUS | PU_HP;
    this->caster_ptr->redraw |= PR_MAP | PR_STATUS | PR_STATE;
    this->caster_ptr->update |= PU_MONSTERS;
    this->caster_ptr->window_flags |= PW_OVERHEAD | PW_DUNGEON;
}

bool RealmHex::check_restart()
{
    if (this->caster_ptr->magic_num1[1] == 0) {
        return false;
    }

    this->caster_ptr->magic_num1[0] = this->caster_ptr->magic_num1[1];
    this->caster_ptr->magic_num1[1] = 0;
    return true;
}

int RealmHex::calc_need_mana()
{
    auto need_mana = 0;
    for (auto spell = 0; spell < 32; spell++) {
        if (hex_spelling(this->caster_ptr, spell)) {
            const auto *s_ptr = &technic_info[REALM_HEX - MIN_TECHNIC][spell];
            need_mana += mod_need_mana(this->caster_ptr, s_ptr->smana, spell, REALM_HEX);
        }
    }

    return need_mana;
}

void RealmHex::gain_exp_from_hex()
{
    for (auto spell = 0; spell < 32; spell++) {
        if (!hex_spelling(this->caster_ptr, spell)) {
            continue;
        }

        if (this->caster_ptr->spell_exp[spell] < SPELL_EXP_BEGINNER) {
            this->caster_ptr->spell_exp[spell] += 5;
            continue;
        }

        if (this->gain_exp_skilled(spell)) {
            continue;
        }

        if (this->gain_exp_expert(spell)) {
            continue;
        }

        this->gain_exp_master(spell);
    }
}

bool RealmHex::gain_exp_skilled(const int spell)
{
    if (this->caster_ptr->spell_exp[spell] >= SPELL_EXP_SKILLED) {
        return false;
    }

    auto *floor_ptr = this->caster_ptr->current_floor_ptr;
    auto gain_condition = one_in_(2);
    gain_condition &= floor_ptr->dun_level > 4;
    gain_condition &= (floor_ptr->dun_level + 10) > this->caster_ptr->lev;
    if (gain_condition) {
        this->caster_ptr->spell_exp[spell]++;
    }
    
    return true;
}

bool RealmHex::gain_exp_expert(const int spell)
{
    if (this->caster_ptr->spell_exp[spell] >= SPELL_EXP_EXPERT) {
        return false;
    }

    const auto *s_ptr = &technic_info[REALM_HEX - MIN_TECHNIC][spell];
    auto *floor_ptr = this->caster_ptr->current_floor_ptr;
    auto gain_condition = one_in_(5);
    gain_condition &= (floor_ptr->dun_level + 5) > this->caster_ptr->lev;
    gain_condition &= (floor_ptr->dun_level + 5) > s_ptr->slevel;
    if (gain_condition) {
        this->caster_ptr->spell_exp[spell]++;
    }

    return true;
}

void RealmHex::gain_exp_master(const int spell)
{
    if (this->caster_ptr->spell_exp[spell] >= SPELL_EXP_MASTER) {
        return;
    }

    const auto *s_ptr = &technic_info[REALM_HEX - MIN_TECHNIC][spell];
    auto *floor_ptr = this->caster_ptr->current_floor_ptr;
    auto gain_condition = one_in_(5);
    gain_condition &= (floor_ptr->dun_level + 5) > this->caster_ptr->lev;
    gain_condition &= floor_ptr->dun_level > s_ptr->slevel;
    if (gain_condition) {
        this->caster_ptr->spell_exp[spell]++;
    }
}

/*!
 * @brief プレイヤーの呪術詠唱枠がすでに最大かどうかを返す
 * @return すでに全枠を利用しているならTRUEを返す
 */
bool RealmHex::hex_spell_fully() const
{
    auto k_max = (this->caster_ptr->lev / 15) + 1;
    k_max = MIN(k_max, MAX_KEEP);
    return casting_hex_num(this->caster_ptr) >= k_max;
}

/*!
 * @brief 一定ゲームターン毎に復讐処理の残り期間の判定を行う
 */
void revenge_spell(player_type *caster_ptr)
{
    if (caster_ptr->realm1 != REALM_HEX)
        return;
    if (hex_revenge_turn(caster_ptr) <= 0)
        return;

    switch (hex_revenge_type(caster_ptr)) {
    case 1:
        exe_spell(caster_ptr, REALM_HEX, HEX_PATIENCE, SPELL_CONT);
        break;
    case 2:
        exe_spell(caster_ptr, REALM_HEX, HEX_REVENGE, SPELL_CONT);
        break;
    }
}

/*!
 * @brief 復讐ダメージの追加を行う
 * @param dam 蓄積されるダメージ量
 */
void revenge_store(player_type *caster_ptr, HIT_POINT dam)
{
    if (caster_ptr->realm1 != REALM_HEX)
        return;
    if (hex_revenge_turn(caster_ptr) <= 0)
        return;

    hex_revenge_power(caster_ptr) += dam;
}

/*!
 * @brief 反テレポート結界の判定
 * @param m_idx 判定の対象となるモンスターID
 * @return 反テレポートの効果が適用されるならTRUEを返す
 */
bool teleport_barrier(player_type *caster_ptr, MONSTER_IDX m_idx)
{
    monster_type *m_ptr = &caster_ptr->current_floor_ptr->m_list[m_idx];
    monster_race *r_ptr = &r_info[m_ptr->r_idx];

    if (!hex_spelling(caster_ptr, HEX_ANTI_TELE))
        return false;
    if ((caster_ptr->lev * 3 / 2) < randint1(r_ptr->level))
        return false;

    return true;
}

/*!
 * @brief 反魔法結界の判定
 * @param m_idx 判定の対象となるモンスターID
 * @return 反魔法の効果が適用されるならTRUEを返す
 */
bool magic_barrier(player_type *caster_ptr, MONSTER_IDX m_idx)
{
    monster_type *m_ptr = &caster_ptr->current_floor_ptr->m_list[m_idx];
    monster_race *r_ptr = &r_info[m_ptr->r_idx];

    if (!hex_spelling(caster_ptr, HEX_ANTI_MAGIC))
        return false;
    if ((caster_ptr->lev * 3 / 2) < randint1(r_ptr->level))
        return false;

    return true;
}

/*!
 * @brief 反増殖結界の判定
 * @param m_idx 判定の対象となるモンスターID
 * @return 反増殖の効果が適用されるならTRUEを返す
 */
bool multiply_barrier(player_type *caster_ptr, MONSTER_IDX m_idx)
{
    monster_type *m_ptr = &caster_ptr->current_floor_ptr->m_list[m_idx];
    monster_race *r_ptr = &r_info[m_ptr->r_idx];

    if (!hex_spelling(caster_ptr, HEX_ANTI_MULTI))
        return false;
    if ((caster_ptr->lev * 3 / 2) < randint1(r_ptr->level))
        return false;

    return true;
}

bool hex_spelling(player_type *caster_ptr, int hex)
{
    return (caster_ptr->realm1 == REALM_HEX) && (caster_ptr->magic_num1[0] & (1UL << (hex)));
}

bool hex_spelling_any(player_type *caster_ptr)
{
    return (caster_ptr->realm1 == REALM_HEX) && (caster_ptr->magic_num1[0] != 0);
}
