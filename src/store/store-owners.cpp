﻿#include "store/store-owners.h"
#include "player-info/race-types.h"
#include "store/store-util.h"

/*!
 * @todo _() でまとめる
 */
const std::unordered_map<StoreSaleType, std::vector<owner_type>> owners = {
    /* General store - 32 unique names */
    /*
  Raistlin は dragonlance の powerful wizard 。
  Rincewind the Chicken は Terry Pratchett の Discworld の登場人物 上記のパロディ？、
  { "憶病者ラストリン",  200, 108, PlayerRaceType::HUMAN},
  { "Raistlin the Chicken", 200, 108, PlayerRaceType::HUMAN},
*/
    {
        StoreSaleType::GENERAL,
        {
            { _("フレンドリーなビルボ", "Bilbo the Friendly"), 30000, 108, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { _("憶病者リンスウィンド", "Rincewind the Chicken"), 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("背の低いサルタン", "Sultan the Midget"), 30000, 107, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { _("ハンサムなライア=エル", "Lyar-el the Comely"), 30000, 107, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { _("親切なファリルマウエン", "Falilmawen the Friendly"), 30000, 108, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { _("臆病者ヴォワラン", "Voirin the Cowardly"), 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("チビのエラシュナク", "Erashnak the Midget"), 30000, 107, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { _("ハンサムなグラッグ", "Grug the Comely"), 30000, 107, PlayerRaceType::HALF_TITAN, STORE_OBJ_STD_LEVEL },
            { _("ケチなフォロビア", "Forovir the Cheap"), 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("馬鹿のエリス", "Ellis the Fool"), 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("腹ペコのフィルバート", "Filbert the Hungry"), 30000, 107, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { _("スナーグル・サシグア", "Fthnargl Psathiggua"), 30000, 107, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { _("長死きエロワーズ", "Eloise the Long-Dead"), 30000, 108, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
            { _("ノロマのフンディ", "Fundi the Slow"), 30000, 108, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { _("グランサス", "Granthus"), 30000, 107, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { _("丁寧なロラックス", "Lorax the Suave"), 30000, 107, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { _("ブッチ", "Butch"), 30000, 108, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { _("美しきエルベレス", "Elbereth the Beautiful"), 30000, 108, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { _("こそこそサーレス", "Sarleth the Sneaky"), 30000, 107, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { _("ナーロック", "Narlock"), 30000, 107, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { _("チビのヘイネッカ", "Haneka the Small"), 30000, 108, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { _("きちがいロワラン", "Loirin the Mad"), 30000, 108, PlayerRaceType::HALF_GIANT, STORE_OBJ_STD_LEVEL },
            { _("毒息のウート", "Wuto the Poisonbreath"), 30000, 107, PlayerRaceType::DRACONIAN, STORE_OBJ_STD_LEVEL },
            { _("でぶっちょアラァカ", "Araaka the Rotund"), 30000, 107, PlayerRaceType::DRACONIAN, STORE_OBJ_STD_LEVEL },
            { _("低能なプーゴー", "Poogor the Dumb"), 30000, 108, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { _("フェロールフィリアン", "Felorfiliand"), 30000, 108, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { _("年寄りマロカ", "Maroka the Aged"), 30000, 107, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { _("勇敢なサシン", "Sasin the Bold"), 30000, 107, PlayerRaceType::HALF_GIANT, STORE_OBJ_STD_LEVEL },
            { _("田舎者アビエマール", "Abiemar the Peasant"), 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("貧乏なハーク", "Hurk the Poor"), 30000, 108, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { _("みじめなソアリン", "Soalin the Wretched"), 30000, 107, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { _("質素なメルラ", "Merulla the Humble"), 30000, 107, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
        } },
    { StoreSaleType::ARMOURY,
        {
            { _("醜悪コン=ダー", "Kon-Dar the Ugly"), 30000, 115, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { _("頑固者ダーグ=ロウ", "Darg-Low the Grim"), 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("賢者デカド", "Decado the Handsome"), 30000, 112, PlayerRaceType::DUNADAN, STORE_OBJ_STD_LEVEL },
            { _("鍛冶屋のウィーランド", "Wieland the Smith"), 30000, 112, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { _("醜悪コン=ダー", "Kon-Dar the Ugly"), 30000, 115, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL }, // @todo 重複.
            { _("頑固者ダーグ=ロウ", "Darg-Low the Grim"), 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("ハンサムなデカド", "Decado the Handsome"), 30000, 112, PlayerRaceType::AMBERITE, STORE_OBJ_STD_LEVEL },
            { _("エロー・ドラゴンスケイル", "Elo Dragonscale"), 30000, 112, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { _("デリカトス", "Delicatus"), 30000, 115, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { _("巨大なグルース", "Gruce the Huge"), 30000, 111, PlayerRaceType::HALF_GIANT, STORE_OBJ_STD_LEVEL },
            { _("アニムス", "Animus"), 30000, 112, PlayerRaceType::GOLEM, STORE_OBJ_STD_LEVEL },
            { _("マルヴァス", "Malvus"), 30000, 112, PlayerRaceType::HALF_TITAN, STORE_OBJ_STD_LEVEL },
            { _("セラクシス", "Selaxis"), 30000, 115, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { _("デス・チル", "Deathchill"), 30000, 111, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
            { _("微かなドリオス", "Drios the Faint"), 30000, 112, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
            { _("冷たいバスリック", "Bathric the Cold"), 30000, 112, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { _("冷酷ヴェンジェラ", "Vengella the Cruel"), 30000, 115, PlayerRaceType::HALF_TROLL, STORE_OBJ_STD_LEVEL },
            { _("強者ウィラナ", "Wyrana the Mighty"), 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("ヨジョ二世", "Yojo II"), 30000, 112, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { _("優しいラナラー", "Ranalar the Sweet"), 30000, 112, PlayerRaceType::AMBERITE, STORE_OBJ_STD_LEVEL },
            { _("不浄のホルバグ", "Horbag the Unclean"), 30000, 115, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { _("テレパスのエレレン", "Elelen the Telepath"), 30000, 111, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { _("イスドリリアス", "Isedrelias"), 30000, 112, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { _("一つ目ヴェグナー", "Vegnar One-eye"), 30000, 112, PlayerRaceType::CYCLOPS, STORE_OBJ_STD_LEVEL },
            { _("混沌のロディッシュ", "Rodish the Chaotic"), 30000, 115, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { _("剣豪ヘジン", "Hesin Swordmaster"), 30000, 111, PlayerRaceType::NIBELUNG, STORE_OBJ_STD_LEVEL },
            { _("ずる屋のエルベレリス", "Elvererith the Cheat"), 30000, 112, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { _("インプのザサス", "Zzathath the Imp"), 30000, 112, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
        } },
    { StoreSaleType::WEAPON,
        {
            { _("残忍なるアーノルド", "Arnold the Beastly"), 30000, 115, PlayerRaceType::HALF_TROLL, STORE_OBJ_STD_LEVEL },
            { _("獣殺しのアーンダル", "Arndal the Beast-Slayer"), 30000, 110, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { _("獣マスターのエディー", "Eddie the Beast-Master"), 30000, 115, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { _("竜殺しのオグライン", "Oglign the Dragon-Slayer"), 30000, 112, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { _("熟練者ドリュー", "Drew the Skilled"), 30000, 115, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("龍の子オラックス", "Orrax the Dragonson"), 30000, 110, PlayerRaceType::DRACONIAN, STORE_OBJ_STD_LEVEL },
            { _("病気持ちのアンスラックス", "Anthrax the Disease-Carrier"), 30000, 115, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { _("頑丈者アルコス", "Arkhoth the Stout"), 30000, 112, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { _("腐れ者のサリアス", "Sarlyas the Rotten"), 30000, 115, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { _("晒し骨のトゥエシク", "Tuethic the Bare-Bones"), 30000, 110, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { _("ビリオス", "Bilious"), 30000, 115, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { _("ファスガル", "Fasgul"), 30000, 112, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { _("パラディンのエレフリス", "Ellefris the Paladin"), 30000, 115, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { _("キ'トリッ'ク", "K'trrik'k"), 30000, 110, PlayerRaceType::KLACKON, STORE_OBJ_STD_LEVEL },
            { _("蜘蛛の友ドゥロカス", "Drocus the Spiderfriend"), 30000, 115, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { _("巨人殺しのフングス", "Fungus the Giant-Slayer"), 30000, 112, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { _("デランサ", "Delantha"), 30000, 115, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { _("レンジャーのソルビスタニ", "Solvistani the Ranger"), 30000, 110, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { _("ノロマのゾリル", "Xoril the Slow"), 30000, 115, PlayerRaceType::GOLEM, STORE_OBJ_STD_LEVEL },
            { _("イーオン・フラックス", "Aeon Flux"), 30000, 112, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { _("強者ナドック", "Nadoc the Strong"), 30000, 115, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { _("弱虫エラモグ", "Eramog the Weak"), 30000, 110, PlayerRaceType::KOBOLD, STORE_OBJ_STD_LEVEL },
            { _("公正なエオウィリス", "Eowilith the Fair"), 30000, 115, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { _("バルログ殺しのヒュイモグ", "Huimog the Balrog-Slayer"), 30000, 112, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { _("冷酷ピーダス", "Peadus the Cruel"), 30000, 115, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { _("殺し屋ヴァモグ", "Vamog the Slayer"), 30000, 110, PlayerRaceType::HALF_OGRE, STORE_OBJ_STD_LEVEL },
            { _("性悪フーシュナク", "Hooshnak the Vicious"), 30000, 115, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { _("舞闘家バレン", "Balenn the War-Dancer"), 30000, 112, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
        } },
    /* Temple - 22 unique names */
    {
        StoreSaleType::TEMPLE,
        {
#ifdef JP
            { "質素なルードヴィヒ", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "パラディンのガンナー", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "選ばれしトリン", 30000, 107, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "賢明なるサラストロ", 30000, 109, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "パーシヴァル卿", 30000, 107, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "神聖なるアセナス", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "マッキノン", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "謹み婦人", 30000, 110, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "ドルイドのハシュニック", 30000, 107, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "フィナク", 30000, 109, PlayerRaceType::YEEK, STORE_OBJ_STD_LEVEL },
            { "クリキック", 30000, 109, PlayerRaceType::KLACKON, STORE_OBJ_STD_LEVEL },
            { "荒くれ者モリヴァル", 30000, 110, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "暗きホシャック", 30000, 107, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "賢者アタール", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "清きイベニッド", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "エリディシュ", 30000, 110, PlayerRaceType::HALF_TROLL, STORE_OBJ_STD_LEVEL },
            { "呪術師ヴルドゥシュ", 30000, 107, PlayerRaceType::HALF_OGRE, STORE_OBJ_STD_LEVEL },
            { "狂戦士ハオブ", 30000, 109, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "若きプルーグディシュ", 30000, 109, PlayerRaceType::HALF_OGRE, STORE_OBJ_STD_LEVEL },
            { "きちがいラムワイズ", 30000, 110, PlayerRaceType::YEEK, STORE_OBJ_STD_LEVEL },
            { "有徳者ムワート", 30000, 107, PlayerRaceType::KOBOLD, STORE_OBJ_STD_LEVEL },
            { "弱虫ダードバード", 30000, 109, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
#else
            { "Ludwig the Humble", 30000, 109, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "Gunnar the Paladin", 30000, 110, PlayerRaceType::HALF_TROLL, STORE_OBJ_STD_LEVEL },
            { "Torin the Chosen", 30000, 107, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Sarastro the Wise", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Sir Parsival the Pure", 30000, 107, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Asenath the Holy", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "McKinnon", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Mistress Chastity", 30000, 110, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Hashnik the Druid", 30000, 107, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "Finak", 30000, 109, PlayerRaceType::YEEK, STORE_OBJ_STD_LEVEL },
            { "Krikkik", 30000, 109, PlayerRaceType::KLACKON, STORE_OBJ_STD_LEVEL },
            { "Morival the Wild", 30000, 110, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "Hoshak the Dark", 30000, 107, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "Atal the Wise", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Ibenidd the Chaste", 30000, 109, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Eridish", 30000, 110, PlayerRaceType::HALF_TROLL, STORE_OBJ_STD_LEVEL },
            { "Vrudush the Shaman", 30000, 107, PlayerRaceType::HALF_OGRE, STORE_OBJ_STD_LEVEL },
            { "Haob the Berserker", 30000, 109, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "Proogdish the Youthfull", 30000, 109, PlayerRaceType::HALF_OGRE, STORE_OBJ_STD_LEVEL },
            { "Lumwise the Mad", 30000, 110, PlayerRaceType::YEEK, STORE_OBJ_STD_LEVEL },
            { "Muirt the Virtuous", 30000, 107, PlayerRaceType::KOBOLD, STORE_OBJ_STD_LEVEL },
            { "Dardobard the Weak", 30000, 109, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
#endif
        } },
    /* Alchemist - 26 unique names */
    {
        StoreSaleType::ALCHEMIST,
        {
#ifdef JP
            { "化学者マウザー", 30000, 111, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { "カオスのウィズル", 30000, 110, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "強欲ミダス", 30000, 116, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "貧弱ジャ=ファー", 30000, 111, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL }, /*FIRST*/
            { "カカルラカカル", 30000, 116, PlayerRaceType::KLACKON, STORE_OBJ_STD_LEVEL },
            { "錬金術師ジャル=エス", 30000, 111, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "用心深いファネラス", 30000, 111, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "キチガイのルンシー", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "グランブルワース", 30000, 116, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "フリッター", 30000, 111, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { "ザリルス", 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "古きエグバート", 30000, 110, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "誇り高きヴァリンドラ", 30000, 116, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "錬金術師タエン", 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "巧言カイド", 30000, 111, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "暗きフリア", 30000, 110, PlayerRaceType::NIBELUNG, STORE_OBJ_STD_LEVEL },
            { "質素なドムリ", 30000, 116, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "魔の子ヤァジュッカ", 30000, 111, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "薬草師ジェララルドール", 30000, 111, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "賢者オレラルダン", 30000, 110, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "デモニシストのフゾグロ", 30000, 116, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "錬金術師ドゥリアシュ", 30000, 111, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "強者ネリア", 30000, 111, PlayerRaceType::CYCLOPS, STORE_OBJ_STD_LEVEL },
            { "辛口リグナス", 30000, 110, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "ティルバ", 30000, 116, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "金持ちミリルドリック", 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
#else
            { "Mauser the Chemist", 30000, 111, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { "Wizzle the Chaotic", 30000, 110, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "Midas the Greedy", 30000, 116, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "Ja-Far the Alchemist", 30000, 111, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "Kakalrakakal", 30000, 116, PlayerRaceType::KLACKON, STORE_OBJ_STD_LEVEL },
            { "Jal-Eth the Alchemist", 30000, 111, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "Fanelath the Cautious", 30000, 111, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "Runcie the Insane", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Grumbleworth", 30000, 116, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "Flitter", 30000, 111, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { "Xarillus", 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Egbert the Old", 30000, 110, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "Valindra the Proud", 30000, 116, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Taen the Alchemist", 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Cayd the Sweet", 30000, 111, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "Fulir the Dark", 30000, 110, PlayerRaceType::NIBELUNG, STORE_OBJ_STD_LEVEL },
            { "Domli the Humble", 30000, 116, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "Yaarjukka Demonspawn", 30000, 111, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "Gelaraldor the Herbmaster", 30000, 111, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Olelaldan the Wise", 30000, 110, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "Fthoglo the Demonicist", 30000, 116, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "Dridash the Alchemist", 30000, 111, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "Nelir the Strong", 30000, 111, PlayerRaceType::CYCLOPS, STORE_OBJ_STD_LEVEL },
            { "Lignus the Pungent", 30000, 110, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "Tilba", 30000, 116, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "Myrildric the Wealthy", 30000, 111, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
#endif
        } },
    /* Magic Shop - 23 unique names */
    {
        StoreSaleType::MAGIC,
        {
#ifdef JP
            { "ソーサラーのロ=パン", 30000, 110, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { "偉大なるブガービイ", 30000, 113, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "イェンダーの魔法使い", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "死霊使いリャク", 30000, 110, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "魔術師スキドゥニー", 30000, 110, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { "幻術師キリア", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "死霊術師ニッキ", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "ソロストラン", 30000, 110, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { "烏賊口アチシェ", 30000, 113, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "貴族のカザ", 30000, 110, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "暗きファジル", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "偉大なるケルドーン", 30000, 110, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "フィランスロプス", 30000, 113, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "魔女のアグナー", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "死霊術師ビュリアンス", 30000, 110, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "ハイメイジのヴイラク", 30000, 110, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "知恵者マディッシュ", 30000, 113, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "ファレブリンボール", 30000, 110, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "陰険フェリル=ガンド", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "呪術師サレゴード", 30000, 110, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "神秘家クトゥアロス", 30000, 113, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "幻術師イベリ", 30000, 110, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "死霊術師ヘトー", 30000, 110, PlayerRaceType::YEEK, STORE_OBJ_STD_LEVEL },
#else
            { "Lo Pan the Sorcerer", 30000, 110, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { "Buggerby the Great", 30000, 113, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "The Wizard of Yendor", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Rjak the Necromancer", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "Skidney the Sorcerer", 30000, 110, PlayerRaceType::HALF_ELF, STORE_OBJ_STD_LEVEL },
            { "Kyria the Illusionist", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Nikki the Necromancer", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "Solostoran", 30000, 110, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { "Achshe the Tentacled", 30000, 113, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "Kaza the Noble", 30000, 110, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Fazzil the Dark", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "Keldorn the Grand", 30000, 110, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "Philanthropus", 30000, 113, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "Agnar the Enchantress", 30000, 110, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Buliance the Necromancer", 30000, 110, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "Vuirak the High-Mage", 30000, 110, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "Madish the Smart", 30000, 113, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "Falebrimbor", 30000, 110, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Felil-Gand the Subtle", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "Thalegord the Shaman", 30000, 110, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "Cthoaloth the Mystic", 30000, 113, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "Ibeli the Illusionist", 30000, 110, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "Heto the Necromancer", 30000, 110, PlayerRaceType::YEEK, STORE_OBJ_STD_LEVEL },
#endif
        } },
    { StoreSaleType::BLACK,
        {
/* Black Market - 32 unique names */
#ifdef JP
            { "ガリー=ギガズ", 60000, 150, PlayerRaceType::HALF_TROLL, STORE_OBJ_STD_LEVEL },
            { "ゴブリンのヒストーア", 60000, 150, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "フェレンギ人クアーク", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "公正なる(?)トッピ", 60000, 150, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "死人ヴァッサ", 60000, 150, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "裏切り者カイン", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "ブボニカス", 60000, 150, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "コープスライト", 60000, 150, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
            { "血に飢えしパリッシュ", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "ヴァイル", 60000, 150, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "信頼のプレンティス", 60000, 150, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "人間殺しのグリエラ", 60000, 150, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "エンジェル", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "水膨れフロツァム", 60000, 150, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "ニーヴァル", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "明るいアナスタシア", 60000, 150, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
            { "死霊術師チャリティー", 60000, 150, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "ボクサーのプグナシオス", 60000, 150, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "幸運なフットソア", 60000, 150, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "光指のシドリア", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "手品師リアソー", 60000, 150, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "やりくり上手のジャナッカ", 60000, 150, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "悪党シーナ", 60000, 150, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "大爪アルニッキ", 60000, 150, PlayerRaceType::DRACONIAN, STORE_OBJ_STD_LEVEL },
            { "貧乏チャエアンド", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "山賊アファードーフ", 60000, 150, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "強欲ラザクスル", 60000, 150, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "ファラレウィン", 60000, 150, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { "しわしわヴォスール", 60000, 150, PlayerRaceType::NIBELUNG, STORE_OBJ_STD_LEVEL },
            { "ハンサムなアラオード", 60000, 150, PlayerRaceType::AMBERITE, STORE_OBJ_STD_LEVEL },
            { "負け犬セラドフリド", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "片足のエルーロ", 60000, 150, PlayerRaceType::HALF_OGRE, STORE_OBJ_STD_LEVEL },
#else
            { "Gary Gygaz", 60000, 150, PlayerRaceType::HALF_TROLL, STORE_OBJ_STD_LEVEL },
            { "Histor the Goblin", 60000, 150, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "Quark the Ferengi", 60000, 150, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "Topi the Fair(?)", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Vhassa the Dead", 60000, 150, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "Kyn the Treacherous", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "Bubonicus", 60000, 150, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "Corpselight", 60000, 150, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
            { "Parrish the Bloodthirsty", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "Vile", 60000, 150, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "Prentice the Trusted", 60000, 150, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "Griella Humanslayer", 60000, 150, PlayerRaceType::IMP, STORE_OBJ_STD_LEVEL },
            { "Angel", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "Flotsam the Bloated", 60000, 150, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "Nieval", 60000, 150, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "Anastasia the Luminous", 60000, 150, PlayerRaceType::SPECTRE, STORE_OBJ_STD_LEVEL },
            { "Charity the Necromancer", 60000, 150, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "Pugnacious the Pugilist", 60000, 150, PlayerRaceType::HALF_ORC, STORE_OBJ_STD_LEVEL },
            { "Footsore the Lucky", 60000, 150, PlayerRaceType::BEASTMAN, STORE_OBJ_STD_LEVEL },
            { "Sidria Lighfingered", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Riatho the Juggler", 60000, 150, PlayerRaceType::HOBBIT, STORE_OBJ_STD_LEVEL },
            { "Janaaka the Shifty", 60000, 150, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "Cina the Rogue", 60000, 150, PlayerRaceType::GNOME, STORE_OBJ_STD_LEVEL },
            { "Arunikki Greatclaw", 60000, 150, PlayerRaceType::DRACONIAN, STORE_OBJ_STD_LEVEL },
            { "Chaeand the Poor", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Afardorf the Brigand", 60000, 150, PlayerRaceType::BARBARIAN, STORE_OBJ_STD_LEVEL },
            { "Lathaxl the Greedy", 60000, 150, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "Falarewyn", 60000, 150, PlayerRaceType::SPRITE, STORE_OBJ_STD_LEVEL },
            { "Vosur the Wrinkled", 60000, 150, PlayerRaceType::NIBELUNG, STORE_OBJ_STD_LEVEL },
            { "Araord the Handsome", 60000, 150, PlayerRaceType::AMBERITE, STORE_OBJ_STD_LEVEL },
            { "Theradfrid the Loser", 60000, 150, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "One-Legged Eroolo", 60000, 150, PlayerRaceType::HALF_OGRE, STORE_OBJ_STD_LEVEL },
#endif
        } },
    /* Home */
    {
        StoreSaleType::HOME,
        {
            { _("我が家", "Your home"), 0, 100, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
        } },
    /* Bookstore - 21 unique names */
    {
        StoreSaleType::BOOK,
        {
#ifdef JP
            { "強欲ドラフ", 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "賢者オドナー", 30000, 105, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "中立のガンダー", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "忍耐の人ロ=シャ", 30000, 105, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "ランドルフ・カーター", 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "隼のサライ", 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "千里眼ボドリル", 30000, 105, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "沈黙のヴェオロイン", 30000, 110, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "学者のヴァンシラス", 30000, 105, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "物書きオセイン", 30000, 108, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "本の虫オルヴァー", 30000, 105, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "浅井墓男", 30000, 110, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "デスマスク", 30000, 105, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "学者のアスーヌ", 30000, 108, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "死人のプリランド", 30000, 105, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "鉄のロナール", 30000, 110, PlayerRaceType::GOLEM, STORE_OBJ_STD_LEVEL },
            { "ガリル=ガミル", 30000, 105, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "本食いローバグ", 30000, 108, PlayerRaceType::KOBOLD, STORE_OBJ_STD_LEVEL },
            { "キリアリキーク", 30000, 105, PlayerRaceType::KLACKON, STORE_OBJ_STD_LEVEL },
            { "静かなるリリン", 30000, 110, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "王者イサング", 30000, 105, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
#else
            { "Dolaf the Greedy", 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Odnar the Sage", 30000, 105, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Gandar the Neutral", 30000, 110, PlayerRaceType::DARK_ELF, STORE_OBJ_STD_LEVEL },
            { "Ro-sha the Patient", 30000, 105, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "Randolph Carter", 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Sarai the Swift", 30000, 108, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
            { "Bodril the Seer", 30000, 105, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
            { "Veloin the Quiet", 30000, 110, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "Vanthylas the Learned", 30000, 105, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "Ossein the Literate", 30000, 108, PlayerRaceType::SKELETON, STORE_OBJ_STD_LEVEL },
            { "Olvar Bookworm", 30000, 105, PlayerRaceType::VAMPIRE, STORE_OBJ_STD_LEVEL },
            { "Shallowgrave", 30000, 110, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "Death Mask", 30000, 105, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "Asuunu the Learned", 30000, 108, PlayerRaceType::MIND_FLAYER, STORE_OBJ_STD_LEVEL },
            { "Prirand the Dead", 30000, 105, PlayerRaceType::ZOMBIE, STORE_OBJ_STD_LEVEL },
            { "Ronar the Iron", 30000, 110, PlayerRaceType::GOLEM, STORE_OBJ_STD_LEVEL },
            { "Galil-Gamir", 30000, 105, PlayerRaceType::ELF, STORE_OBJ_STD_LEVEL },
            { "Rorbag Book-Eater", 30000, 108, PlayerRaceType::KOBOLD, STORE_OBJ_STD_LEVEL },
            { "Kiriarikirk", 30000, 105, PlayerRaceType::KLACKON, STORE_OBJ_STD_LEVEL },
            { "Rilin the Quiet", 30000, 110, PlayerRaceType::DWARF, STORE_OBJ_STD_LEVEL },
            { "Isung the Lord", 30000, 105, PlayerRaceType::HIGH_ELF, STORE_OBJ_STD_LEVEL },
#endif
        } },
    /* Museum */
    {
        StoreSaleType::MUSEUM,
        {
            { _("博物館", "Museum"), 0, 100, PlayerRaceType::HUMAN, STORE_OBJ_STD_LEVEL },
        } }
};
