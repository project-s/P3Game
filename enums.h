///
///     \file   enums.h
///     \brief  store all usable enums
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef ENUM_H
#define ENUM_H

enum
{
    HERO_STATUS_WALK=101,
    HERO_STATUS_FIGHT,
    HERO_STATUS_REGEN,
    HERO_STATUS_RESET,
    HERO_STATUS_NOP,
    //Welcome Window
    GUI_ID_BTN_NEWGAME,
    GUI_ID_BTN_LOADGAME,
    GUI_ID_IMG_TITLE,
    GUI_ID_IMG_NOT_A_CLICKER,
    //Game Window
    GUI_ID_BTN_CHAR,
    GUI_ID_BTN_STATS,
    GUI_ID_IMG_BACK,
    GUI_ID_IMG_BACKINV,
    GUI_ID_IMG_HERO,
    GUI_ID_IMG_MONSTER,
    //Reset Window
    GUI_ID_BTN_SPR,
    GUI_ID_BTN_STR,
    GUI_ID_BTN_DEF,
    GUI_ID_BTN_SPD,
    //incStat
    HERO_INC_STR,
    HERO_INC_SPR,
    HERO_INC_SPD,
    HERO_INC_DEF,
    HERO_INC_MAXHP,
    //stats value
    STAT_MONSTERS_KILLED,
    STAT_TIME_PLAYED,
    STAT_DMG_DONE,
    STAT_DMG_TAKEN,
    STAT_LEGACY,
    STAT_HIGHEST_WORLD,
    //Hero Window
    GUI_ID_BTN_HERO_BACK,
    GUI_ID_EDIT_NAME,
    //Statistics Window
    GUI_ID_BTN_STATS_BACK,
};

#endif
