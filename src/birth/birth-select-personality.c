﻿#include "system/angband.h"
#include "birth/birth-select-personality.h"
#include "player/player-personality.h"
#include "term/gameterm.h"
#include "birth/birth-util.h"

/*!
 * @brief プレイヤーの性格選択を行う / Player Player seikaku
 * @return なし
 */
bool get_player_personality(player_type *creature_ptr)
{
    concptr str;
    clear_from(10);
    put_str(_("注意：《性格》によってキャラクターの能力やボーナスが変化します。", "Note: Your personality determines various intrinsic abilities and bonuses."), 23, 5);
    char sym[MAX_SEIKAKU];
    char buf[80];
    char p2 = ')';
    int n;
    for (n = 0; n < MAX_SEIKAKU; n++) {
        if (seikaku_info[n].sex && (seikaku_info[n].sex != (creature_ptr->psex + 1)))
            continue;

        ap_ptr = &seikaku_info[n];
        str = ap_ptr->title;
        if (n < 26)
            sym[n] = I2A(n);
        else
            sym[n] = ('A' + n - 26);

        sprintf(buf, "%c%c%s", I2A(n), p2, str);
        put_str(buf, 12 + (n / 4), 2 + 18 * (n % 4));
    }

    char cur[80];
    sprintf(cur, "%c%c%s", '*', p2, _("ランダム", "Random"));
    int k = -1;
    int cs = creature_ptr->pseikaku;
    int os = MAX_SEIKAKU;
    while (TRUE) {
        if (cs != os) {
            c_put_str(TERM_WHITE, cur, 12 + (os / 4), 2 + 18 * (os % 4));
            put_str("                                   ", 3, 40);
            if (cs == MAX_SEIKAKU) {
                sprintf(cur, "%c%c%s", '*', p2, _("ランダム", "Random"));
                put_str("                                   ", 4, 40);
                put_str("                                   ", 5, 40);
            } else {
                ap_ptr = &seikaku_info[cs];
                str = ap_ptr->title;
                sprintf(cur, "%c%c%s", sym[cs], p2, str);
                c_put_str(TERM_L_BLUE, ap_ptr->title, 3, 40);
                put_str(_("の性格修正", ": Personality modification"), 3, 40 + strlen(ap_ptr->title));
                put_str(_("腕力 知能 賢さ 器用 耐久 魅力      ", "Str  Int  Wis  Dex  Con  Chr       "), 4, 40);
                sprintf(buf, "%+3d  %+3d  %+3d  %+3d  %+3d  %+3d       ",
                    ap_ptr->a_adj[0], ap_ptr->a_adj[1], ap_ptr->a_adj[2], ap_ptr->a_adj[3],
                    ap_ptr->a_adj[4], ap_ptr->a_adj[5]);
                c_put_str(TERM_L_BLUE, buf, 5, 40);
            }
            c_put_str(TERM_YELLOW, cur, 12 + (cs / 4), 2 + 18 * (cs % 4));
            os = cs;
        }

        if (k >= 0)
            break;

        sprintf(buf, _("性格を選んで下さい (%c-%c) ('='初期オプション設定): ", "Choose a personality (%c-%c) ('=' for options): "), sym[0], sym[MAX_SEIKAKU - 1]);
        put_str(buf, 10, 10);
        char c = inkey();
        if (c == 'Q')
            birth_quit();
        if (c == 'S')
            return FALSE;
        if (c == ' ' || c == '\r' || c == '\n') {
            if (cs == MAX_SEIKAKU) {
                do {
                    k = randint0(MAX_SEIKAKU);
                } while (seikaku_info[k].sex && (seikaku_info[k].sex != (creature_ptr->psex + 1)));
                cs = k;
                continue;
            } else {
                k = cs;
                break;
            }
        }

        if (c == '*') {
            do {
                k = randint0(n);
            } while (seikaku_info[k].sex && (seikaku_info[k].sex != (creature_ptr->psex + 1)));
            cs = k;
            continue;
        }

        if (c == '8') {
            if (cs >= 4)
                cs -= 4;
            if (cs != MAX_SEIKAKU && seikaku_info[cs].sex && (seikaku_info[cs].sex != (creature_ptr->psex + 1))) {
                if ((cs - 4) > 0)
                    cs -= 4;
                else
                    cs += 4;
            }
        }

        if (c == '4') {
            if (cs > 0)
                cs--;
            if (cs != MAX_SEIKAKU && seikaku_info[cs].sex && (seikaku_info[cs].sex != (creature_ptr->psex + 1))) {
                if ((cs - 1) > 0)
                    cs--;
                else
                    cs++;
            }
        }

        if (c == '6') {
            if (cs < MAX_SEIKAKU)
                cs++;
            if (cs != MAX_SEIKAKU && seikaku_info[cs].sex && (seikaku_info[cs].sex != (creature_ptr->psex + 1))) {
                if ((cs + 1) <= MAX_SEIKAKU)
                    cs++;
                else
                    cs--;
            }
        }

        if (c == '2') {
            if ((cs + 4) <= MAX_SEIKAKU)
                cs += 4;
            if (cs != MAX_SEIKAKU && seikaku_info[cs].sex && (seikaku_info[cs].sex != (creature_ptr->psex + 1))) {
                if ((cs + 4) <= MAX_SEIKAKU)
                    cs += 4;
                else
                    cs -= 4;
            }
        }

        k = (islower(c) ? A2I(c) : -1);
        if ((k >= 0) && (k < MAX_SEIKAKU)) {
            if ((seikaku_info[k].sex == 0) || (seikaku_info[k].sex == (creature_ptr->psex + 1))) {
                cs = k;
                continue;
            }
        }

        k = (isupper(c) ? (26 + c - 'A') : -1);
        if ((k >= 26) && (k < MAX_SEIKAKU)) {
            if ((seikaku_info[k].sex == 0) || (seikaku_info[k].sex == (creature_ptr->psex + 1))) {
                cs = k;
                continue;
            }
        } else
            k = -1;

        if (c == '?') {
            show_help(creature_ptr, _("jraceclas.txt#ThePersonalities", "raceclas.txt#ThePersonalities"));
        } else if (c == '=') {
            screen_save();
            do_cmd_options_aux(OPT_PAGE_BIRTH, _("初期オプション((*)はスコアに影響)", "Birth Option((*)s effect score)"));
            screen_load();
        } else if (c != '2' && c != '4' && c != '6' && c != '8')
            bell();
    }

    creature_ptr->pseikaku = (CHARACTER_IDX)k;
    ap_ptr = &seikaku_info[creature_ptr->pseikaku];
    char tmp[64];
#ifdef JP
    strcpy(tmp, ap_ptr->title);
    if (ap_ptr->no == 1)
        strcat(tmp, "の");
#else
    strcpy(tmp, ap_ptr->title);
    strcat(tmp, " ");
#endif
    strcat(tmp, creature_ptr->name);
    c_put_str(TERM_L_BLUE, tmp, 1, 34);
    return TRUE;
}