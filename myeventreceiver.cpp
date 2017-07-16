#include "MyEventReceiver.h"
#include "game.h"

#include <iostream>

MyEventReceiver::MyEventReceiver(Game *P3Game)
{
    //ctor
    this->P3Game = P3Game;
}

MyEventReceiver::~MyEventReceiver()
{
    //dtor
}

bool MyEventReceiver::OnEvent(const SEvent& event)
{
    if (event.EventType == EET_GUI_EVENT)
    {
        s32 id = event.GUIEvent.Caller->getID();

        switch(event.GUIEvent.EventType)
        {
        case EGET_EDITBOX_ENTER:
            switch (id)
            {
                case GUI_ID_EDIT_NAME:
                P3Game->checkName();
                return true;
            default:
                return false;
            }
        case EGET_BUTTON_CLICKED:
            switch(id)
            {
            //*********************************************************************************************
            //Welcome Window
            //*********************************************************************************************
            case GUI_ID_BTN_NEWGAME:
                P3Game->saveOldGame();
                P3Game->gui->setWelcomeWindowVisible(false);
                P3Game->gui->setgameWindowVisible(true);
                P3Game->changeHeroStatus(HERO_STATUS_WALK);
                P3Game->InitSaveGame();
                return true;

            case GUI_ID_BTN_LOADGAME:
                P3Game->loadGame();
                P3Game->gui->setWelcomeWindowVisible(false);
                P3Game->gui->setgameWindowVisible(true);

                P3Game->changeHeroStatus(HERO_STATUS_WALK);
                P3Game->CheckSuccess();
                return true;
            //*********************************************************************************************
            //Game Window
            //*********************************************************************************************
            case GUI_ID_BTN_CHAR:
                P3Game->gui->setheroWindowVisible(true);
                P3Game->displayHeroStats();
                return true;
            case GUI_ID_BTN_STATS:
                P3Game->gui->setStatsWindowVisible(true);
                P3Game->displayGameStats();
                return true;
            //*********************************************************************************************
            //Reset Window
            //*********************************************************************************************
            case GUI_ID_BTN_SPR:
                //action inc SPR
                P3Game->IncHeroStat(HERO_INC_SPR);
                return true;
            case GUI_ID_BTN_STR:
                //action inc STR
                P3Game->IncHeroStat(HERO_INC_STR);
                return true;
            case GUI_ID_BTN_DEF:
                //action inc DEF
                P3Game->IncHeroStat(HERO_INC_DEF);
                return true;
            case GUI_ID_BTN_SPD:
                //action inc SPD
                P3Game->IncHeroStat(HERO_INC_SPD);
                return true;
            //*********************************************************************************************
            //Hero Window
            //*********************************************************************************************
            case GUI_ID_BTN_HERO_BACK:
                P3Game->gui->setheroWindowVisible(false);
                return true;
            //*********************************************************************************************
            //Statistics Window
            //*********************************************************************************************
            case GUI_ID_BTN_STATS_BACK:
                P3Game->gui->setStatsWindowVisible(false);
                return true;
            default:
                return false;
            }
        default:
            break;
        }
    }
    return false;
}
