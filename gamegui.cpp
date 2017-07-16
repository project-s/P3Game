#include "GameGUI.h"

GameGUI::GameGUI(IGUIEnvironment *guienv)
{
    //ctor
    this->guienv = guienv;

    //*********************************************************************************************
    //Hscreen : 564. HALF = 282.  quarter = 141
    //Vscreen : 480. background: 423. footer: 57
    //*********************************************************************************************

    //*********************************************************************************************
    //Welcome Window
    //*********************************************************************************************
    welcomeWindow = guienv->addStaticText(L"", rect<int>(0,0,564,480));
    welcomeWindow->setBackgroundColor(video::SColor (180,255,67,00));
    //Labels
    textFooter = guienv->addStaticText(L"N E R D C R E D Z D E S E R V E D -> T H A N K S T O P A S C A L", rect<int>(282-200,400,282+200,400+40), false, false, welcomeWindow);
    textFooter->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    textFooter->setBackgroundColor(video::SColor (255,255,165,0));
    //Images
    imgTitle = guienv->addImage(core::rect<s32>(282-200,20,282+200,20+60), welcomeWindow, GUI_ID_IMG_TITLE, L"");
    imgNotAClicker = guienv->addImage(core::rect<s32>(282-100,100,282+100,100+40), welcomeWindow, GUI_ID_IMG_NOT_A_CLICKER, L"");
    //buttons
    btnNewGame = guienv->addButton(rect<int>(282-150,200,282-50,200+100), welcomeWindow, GUI_ID_BTN_NEWGAME, L"");
    btnLoadGame = guienv->addButton(rect<int>(282+50,200,282+150,200+100), welcomeWindow, GUI_ID_BTN_LOADGAME, L"");
    btnLoadGame->setVisible(false);
    //*********************************************************************************************

    //*********************************************************************************************
    //Game Window
    //*********************************************************************************************
    gameWindow = guienv->addStaticText(L"", rect<int>(0,0,564,480));
    gameWindow->setBackgroundColor(video::SColor (0,0,0,0));
    gameWindow->setVisible(false);
    //Images
    imgBackGround = guienv->addImage(core::rect<s32>(0,0, 564,423), gameWindow, GUI_ID_IMG_BACK, L"");
    imgBackGround->setScaleImage(true);
    imgBackGroundInv = guienv->addImage(core::rect<s32>(0+564,0,564+564,423), gameWindow, GUI_ID_IMG_BACKINV, L"");
    imgBackGroundInv->setScaleImage(true);
    imgHero = guienv->addImage(core::rect<s32>(282-130,150+100,282-30,150+200), gameWindow, GUI_ID_IMG_HERO, L"");
    imgHero->setScaleImage(true);
    imgMonster = guienv->addImage(core::rect<s32>(282+2,150+72,282+130,150+200), gameWindow, GUI_ID_IMG_HERO, L"");
    imgMonster->setScaleImage(true);
    imgMonster->setVisible(false);
    //Labels
    textLevel = guienv->addStaticText(L"", rect<int>(282-100,70,282+100,70+40), false, false, gameWindow);
    textLevel->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    gameFooter = guienv->addStaticText(L"", rect<int>(0,480-57,564,480), false, false, gameWindow);;
    gameFooter->setBackgroundColor(video::SColor (100,0,0,0));
    //Buttons
    btnChar = guienv->addButton(rect<int>(141-40,480-50,141+40,480-10), gameWindow, GUI_ID_BTN_CHAR, L"CHAR");
    btnStats = guienv->addButton(rect<int>(282+141-40,480-50,282+141+40,480-10), gameWindow, GUI_ID_BTN_STATS, L"STATS");
    //*********************************************************************************************

    //*********************************************************************************************
    //Reset Window
    //*********************************************************************************************
    resetWindow = guienv->addStaticText(L"", rect<int>(0,0,564,480));
    resetWindow->setBackgroundColor(video::SColor (255,101,0,0));
    resetWindow->setVisible(false);
    //Labels
    textGameOver = guienv->addStaticText(L"G A M E   O V E R", rect<int>(282-200,20,282+200,20+60), false, false, resetWindow);
    textGameOver->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    textGameOver->setBackgroundColor(video::SColor (255,255,215,0));
    resetValue = guienv->addStaticText(L"+", rect<int>(282-20,240-20,282+20,240+20), false, false, resetWindow);
    resetValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    //Buttons
    btnSPR = guienv->addButton(rect<int>(282-50,240-100,282+50,240-60), resetWindow, GUI_ID_BTN_SPR, L"+ SPR");     //TOP
    btnSTR = guienv->addButton(rect<int>(282-200,240-20,282-100,240+20), resetWindow, GUI_ID_BTN_STR, L"+ STR");    //LEFT OK
    btnDEF = guienv->addButton(rect<int>(282-50,240+60,282+50,240+100), resetWindow, GUI_ID_BTN_DEF, L"+ DEF");     //BOTTOM OK
    btnSPD = guienv->addButton(rect<int>(282+100,240-20,282+200,240+20), resetWindow, GUI_ID_BTN_SPD, L"+ SPD");    //RIGHT
    //*********************************************************************************************

    //*********************************************************************************************
    //Hero Window
    //*********************************************************************************************
    heroWindow = guienv->addStaticText(L"", rect<int>(0,0,564,480));
    heroWindow->setBackgroundColor(video::SColor (255,101,0,0));
    heroWindow->setVisible(false);
    //Labels
    heroWindowTitle = guienv->addStaticText(L"H E R O   S T A T S", rect<int>(282-200,10,282+200,10+60), false, false, heroWindow);
    heroWindowTitle->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowTitle->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowName = guienv->addStaticText(L" H E R O N A M E", rect<int>(282-200,240-160,282-50,240-120), false, false, heroWindow);
    heroWindowName->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowName->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowInfo = guienv->addStaticText(L"You can change the hero's name up here. \n 25 letters maximum", rect<int>(282+50,240-110,282+200,240-90), false, false, heroWindow);
    heroWindowInfo->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowInfo->setBackgroundColor(video::SColor (255,150,0,0));
    heroWindowStr = guienv->addStaticText(L" S T R ", rect<int>(282-200,240-60,282-50,240-20), false, false, heroWindow);
    heroWindowStr->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowStr->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowStrValue = guienv->addStaticText(L"", rect<int>(282+50,240-60,282+200,240-20), false, false, heroWindow);
    heroWindowStrValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowStrValue->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowDef = guienv->addStaticText(L" D E F ", rect<int>(282-200,240-10,282-50,240+30), false, false, heroWindow);
    heroWindowDef->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowDef->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowDefValue = guienv->addStaticText(L"", rect<int>(282+50,240-10,282+200,240+30), false, false, heroWindow);
    heroWindowDefValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowDefValue->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowSpr = guienv->addStaticText(L" S P R ", rect<int>(282-200,240+40,282-50,240+80), false, false, heroWindow);
    heroWindowSpr->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowSpr->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowSprValue = guienv->addStaticText(L"", rect<int>(282+50,240+40,282+200,240+80), false, false, heroWindow);
    heroWindowSprValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowSprValue->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowSpd = guienv->addStaticText(L" S P D ", rect<int>(282-200,240+90,282-50,240+130), false, false, heroWindow);
    heroWindowSpd->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowSpd->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowSpdValue = guienv->addStaticText(L"", rect<int>(282+50,240+90,282+200,240+130), false, false, heroWindow);
    heroWindowSpdValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowSpdValue->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowMaxHP = guienv->addStaticText(L" M A X   H P ", rect<int>(282-200,240+140,282-50,240+180), false, false, heroWindow);
    heroWindowMaxHP->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowMaxHP->setBackgroundColor(video::SColor (255,255,215,0));
    heroWindowMaxHPValue = guienv->addStaticText(L"", rect<int>(282+50,240+140,282+200,240+180), false, false, heroWindow);
    heroWindowMaxHPValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowMaxHPValue->setBackgroundColor(video::SColor (255,255,215,0));
    //EditBox
    heroWindowEditName = guienv->addEditBox(L"", rect<int>(282+50,240-160,282+200,240-120), true, heroWindow, GUI_ID_EDIT_NAME);
    heroWindowEditName->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    heroWindowEditName->setOverrideColor(video::SColor (255,255,99,71));
    heroWindowEditName->setMax(25); //limit the entry to 25 char
    //Button
    btnHeroBack = guienv->addButton(rect<int>(80*3,480-50,80*4,480-10), heroWindow, GUI_ID_BTN_HERO_BACK, L"BackToGame");
    //*********************************************************************************************

    //*********************************************************************************************
    //Statistics Window
    //*********************************************************************************************
    StatsWindow = guienv->addStaticText(L"", rect<int>(0,0,564,480));
    StatsWindow->setBackgroundColor(video::SColor (255,101,0,0));
    StatsWindow->setVisible(false);
    //Labels
    statsWindowTitle = guienv->addStaticText(L"S T A T I S T I C S", rect<int>(282-200,10,282+200,10+60), false, false, StatsWindow);
    statsWindowTitle->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    statsWindowTitle->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowmonsteKilled = guienv->addStaticText(L"Monsters Killed", rect<int>(282-200,240-160,282-120,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilled->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilled->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowmonsteKilledValue = guienv->addStaticText(L"", rect<int>(282-100,240-160,282-20,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilledValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilledValue->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowmonsteKilled = guienv->addStaticText(L"Monsters Killed", rect<int>(282-200,240-160,282-120,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilled->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilled->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowmonsteKilledValue = guienv->addStaticText(L"monsters Killed Value", rect<int>(282-100,240-160,282-20,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilledValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilledValue->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowtimePlayed = guienv->addStaticText(L"Time Played", rect<int>(282-200,240-120,282-120,240-90), false, false, StatsWindow);
    StatsWindowtimePlayed->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowtimePlayed->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowtimePlayedValue = guienv->addStaticText(L"Time Played Value", rect<int>(282-100,240-120,282-20,240-90), false, false, StatsWindow);
    StatsWindowtimePlayedValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowtimePlayedValue->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowdmgDone = guienv->addStaticText(L"Damage Done", rect<int>(282-200,240-80,282-120,240-50), false, false, StatsWindow);
    StatsWindowdmgDone->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgDone->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowdmgDoneValue = guienv->addStaticText(L"Damage Done Value", rect<int>(282-100,240-80,282-20,240-50), false, false, StatsWindow);
    StatsWindowdmgDoneValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgDoneValue->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowdmgTaken = guienv->addStaticText(L"Damage Taken", rect<int>(282-200,240-40,282-120,240-10), false, false, StatsWindow);
    StatsWindowdmgTaken->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgTaken->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowdmgTakenValue = guienv->addStaticText(L"Damage Taken Value", rect<int>(282-100,240-40,282-20,240-10), false, false, StatsWindow);
    StatsWindowdmgTakenValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgTakenValue->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowlegacyNumber = guienv->addStaticText(L"Legacies", rect<int>(282-200,240+0,282-120,240+30), false, false, StatsWindow);
    StatsWindowlegacyNumber->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowlegacyNumber->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowlegacyNumberValue = guienv->addStaticText(L"Legacies Value", rect<int>(282-100,240+0,282-20,240+30), false, false, StatsWindow);
    StatsWindowlegacyNumberValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowlegacyNumberValue->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowhighestWorld = guienv->addStaticText(L"Highest World", rect<int>(282-200,240+40,282-120,240+70), false, false, StatsWindow);
    StatsWindowhighestWorld->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowhighestWorld->setBackgroundColor(video::SColor (255,255,215,0));
    StatsWindowhighestWorldValue = guienv->addStaticText(L"Highest World Value", rect<int>(282-100,240+40,282-20,240+70), false, false, StatsWindow);
    StatsWindowhighestWorldValue->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowhighestWorldValue->setBackgroundColor(video::SColor (255,255,215,0));
    //Labels for success
    StatsWindowmonsteKilledSuccess1 = guienv->addStaticText(L"25", rect<int>(282+10,240-160,282+40,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilledSuccess1->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilledSuccess1->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowmonsteKilledSuccess2 = guienv->addStaticText(L"100", rect<int>(282+50,240-160,282+80,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilledSuccess2->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilledSuccess2->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowmonsteKilledSuccess3 = guienv->addStaticText(L"500", rect<int>(282+90,240-160,282+120,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilledSuccess3->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilledSuccess3->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowmonsteKilledSuccess4 = guienv->addStaticText(L"5000", rect<int>(282+130,240-160,282+170,240-130), false, false, StatsWindow);
    StatsWindowmonsteKilledSuccess4->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowmonsteKilledSuccess4->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowplayingTimeSuccess1 = guienv->addStaticText(L"600", rect<int>(282+10,240-120,282+40,240-90), false, false, StatsWindow);
    StatsWindowplayingTimeSuccess1->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowplayingTimeSuccess1->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowplayingTimeSuccess2 = guienv->addStaticText(L"6000", rect<int>(282+50,240-120,282+80,240-90), false, false, StatsWindow);
    StatsWindowplayingTimeSuccess2->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowplayingTimeSuccess2->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowplayingTimeSuccess3 = guienv->addStaticText(L"50000", rect<int>(282+90,240-120,282+120,240-90), false, false, StatsWindow);
    StatsWindowplayingTimeSuccess3->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowplayingTimeSuccess3->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowplayingTimeSuccess4 = guienv->addStaticText(L"300000", rect<int>(282+130,240-120,282+170,240-90), false, false, StatsWindow);
    StatsWindowplayingTimeSuccess4->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowplayingTimeSuccess4->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgDoneSuccess1 = guienv->addStaticText(L"25000", rect<int>(282+10,240-80,282+40,240-50), false, false, StatsWindow);
    StatsWindowdmgDoneSuccess1->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgDoneSuccess1->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgDoneSuccess2 = guienv->addStaticText(L"100000", rect<int>(282+50,240-80,282+80,240-50), false, false, StatsWindow);
    StatsWindowdmgDoneSuccess2->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgDoneSuccess2->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgDoneSuccess3 = guienv->addStaticText(L"750000", rect<int>(282+90,240-80,282+120,240-50), false, false, StatsWindow);
    StatsWindowdmgDoneSuccess3->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgDoneSuccess3->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgDoneSuccess4 = guienv->addStaticText(L"7500000", rect<int>(282+130,240-80,282+170,240-50), false, false, StatsWindow);
    StatsWindowdmgDoneSuccess4->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgDoneSuccess4->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgTakenSuccess1 = guienv->addStaticText(L"25000", rect<int>(282+10,240-40,282+40,240-10), false, false, StatsWindow);
    StatsWindowdmgTakenSuccess1->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgTakenSuccess1->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgTakenSuccess2 = guienv->addStaticText(L"100000", rect<int>(282+50,240-40,282+80,240-10), false, false, StatsWindow);
    StatsWindowdmgTakenSuccess2->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgTakenSuccess2->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgTakenSuccess3 = guienv->addStaticText(L"750000", rect<int>(282+90,240-40,282+120,240-10), false, false, StatsWindow);
    StatsWindowdmgTakenSuccess3->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgTakenSuccess3->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowdmgTakenSuccess4 = guienv->addStaticText(L"7500000", rect<int>(282+130,240-40,282+170,240-10), false, false, StatsWindow);
    StatsWindowdmgTakenSuccess4->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowdmgTakenSuccess4->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowlegacyNumberSuccess1 = guienv->addStaticText(L"25", rect<int>(282+10,240,282+40,240+30), false, false, StatsWindow);
    StatsWindowlegacyNumberSuccess1->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowlegacyNumberSuccess1->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowlegacyNumberSuccess2 = guienv->addStaticText(L"100", rect<int>(282+50,240,282+80,240+30), false, false, StatsWindow);
    StatsWindowlegacyNumberSuccess2->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowlegacyNumberSuccess2->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowlegacyNumberSuccess3 = guienv->addStaticText(L"500", rect<int>(282+90,240,282+120,240+30), false, false, StatsWindow);
    StatsWindowlegacyNumberSuccess3->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowlegacyNumberSuccess3->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowlegacyNumberSuccess4 = guienv->addStaticText(L"5000", rect<int>(282+130,240,282+170,240+30), false, false, StatsWindow);
    StatsWindowlegacyNumberSuccess4->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowlegacyNumberSuccess4->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowhighestWorldValueSuccess1 = guienv->addStaticText(L"10", rect<int>(282+10,240+40,282+40,240+70), false, false, StatsWindow);
    StatsWindowhighestWorldValueSuccess1->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowhighestWorldValueSuccess1->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowhighestWorldValueSuccess2 = guienv->addStaticText(L"50", rect<int>(282+50,240+40,282+80,240+70), false, false, StatsWindow);
    StatsWindowhighestWorldValueSuccess2->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowhighestWorldValueSuccess2->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowhighestWorldValueSuccess3 = guienv->addStaticText(L"300", rect<int>(282+90,240+40,282+120,240+70), false, false, StatsWindow);
    StatsWindowhighestWorldValueSuccess3->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowhighestWorldValueSuccess3->setBackgroundColor(video::SColor (255,255,0,0));
    StatsWindowhighestWorldValueSuccess4 = guienv->addStaticText(L"5000", rect<int>(282+130,240+40,282+170,240+70), false, false, StatsWindow);
    StatsWindowhighestWorldValueSuccess4->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
    StatsWindowhighestWorldValueSuccess4->setBackgroundColor(video::SColor (255,255,0,0));
    //Button
    btnStatsBack = guienv->addButton(rect<int>(80*3,480-50,80*4,480-10), StatsWindow, GUI_ID_BTN_STATS_BACK, L"BackToGame");
    //*********************************************************************************************
}

GameGUI::~GameGUI()
{
    //dtor
}

//remove monster HP bar
void GameGUI::removeHPBarMonster()
{
    this->HPBarMonster->remove();
}

//remove hero HP bar
void GameGUI::removeHpBarHero()
{
    this->HpBarHero->remove();
}

//display both HP bars at the beginning of a fight
void GameGUI::FightHPBars()
{
    HpBarHero = guienv->addStaticText(L"HP", rect<int>(282-240,150,282-140,150+200), false, false, gameWindow);;
    HpBarHero->setBackgroundColor(video::SColor (100,0,255,0));
    HpBarHero->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);

    HPBarMonster = guienv->addStaticText(L"HP", rect<int>(282+150,150,282+240,150+200), false, false, gameWindow);;
    HPBarMonster->setBackgroundColor(video::SColor (100,0,255,0));
    HPBarMonster->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER);
}

//remove HPBar and redraw it with new hp value
void GameGUI::drawHpBarHero(float modifPosition)
{
    HpBarHero->remove();
    HpBarHero = guienv->addStaticText(L"HP", rect<int>(282-240,350-((modifPosition*100)*2),282-140,150+200), false, false, gameWindow);
    HpBarHero->setBackgroundColor(video::SColor (180,(255 * (100-(modifPosition*100))) / 100,(255 * (100 - (100-(modifPosition*100)))) / 100,0));
    HpBarHero->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
}

//remove HPBar and redraw it with new hp value
void GameGUI::drawHpMonster(float modifPosition)
{
    HPBarMonster->remove();
    HPBarMonster = guienv->addStaticText(L"HP", rect<int>(282+150,350-((modifPosition*100)*2),282+240,150+200), false, false, gameWindow);
    HPBarMonster->setBackgroundColor(video::SColor (180,(255 * (100-(modifPosition*100))) / 100,(255 * (100 - (100-(modifPosition*100)))) / 100,0));
    HPBarMonster->setTextAlignment(EGUIA_CENTER, EGUIA_CENTER );
}

//Hide/show the welcome Window
void GameGUI::setWelcomeWindowVisible(bool status)
{
    this->welcomeWindow->setVisible(status);
}

//Hide/show the game Window
void GameGUI::setgameWindowVisible(bool status)
{
    this->gameWindow->setVisible(status);
}

//Hide/show the game Window
void GameGUI::setresetWindowVisible(bool status)
{
    this->resetWindow->setVisible(status);
}

//Hide/show the game Window
void GameGUI::setheroWindowVisible(bool status)
{
    this->heroWindow->setVisible(status);
}

//Hide/show the game Window
void GameGUI::setStatsWindowVisible(bool status)
{
    this->StatsWindow->setVisible(status);
}

//Hide/show the Load game button
void GameGUI::setbtnLoadGameVisible(bool status)
{
    this->btnLoadGame->setVisible(status);
}

//Hide/show the Monster Image
void GameGUI::setimgMonsterVisible(bool status)
{
    this->imgMonster->setVisible(status);
}

//set Background Image
void GameGUI::setimgBackGroundImage(ITexture *texBackground)
{
    this->imgBackGround->setImage(texBackground);
}

//set BackgroundInv Image
void GameGUI::setimgBackGroundInvImage(ITexture *texBackgroundInv)
{
    this->imgBackGroundInv->setImage(texBackgroundInv);
}

//set main title Image
void GameGUI::setimgTitleImage(ITexture *textureTitle)
{
    this->imgTitle->setImage(textureTitle);
}

//set sub title Image
void GameGUI::setimgNotAClickerImage(ITexture *textureNotAClicker)
{
    this->imgNotAClicker->setImage(textureNotAClicker);
}

//set new game button Image
void GameGUI::setbtnNewGameImage(ITexture *textureBtnNewGAme)
{
    this->btnNewGame->setImage(textureBtnNewGAme);
}

//set load game button Image
void GameGUI::setbtnLoadGameImage(ITexture *textureBtnLoadGame)
{
    this->btnLoadGame->setImage(textureBtnLoadGame);
}

//set default button image
void GameGUI::setDefaultBtnImage(ITexture *textureBtnOthers)
{
    this->btnStatsBack->setImage(textureBtnOthers);
    this->btnHeroBack->setImage(textureBtnOthers);
    this->btnChar->setImage(textureBtnOthers);
    this->btnStats->setImage(textureBtnOthers);
}

//set hero Image
void GameGUI::setimgHeroImage(ITexture *textureHero)
{
    this->imgHero->setImage(textureHero);
}

//set monster Image
void GameGUI::setimgMonsterImage(ITexture *textureMonster)
{
    this->imgMonster->setImage(textureMonster);
}

//set new game button position
void GameGUI::setbtnNewGameRelativePosition(core::rect<s32> position)
{
    this->btnNewGame->setRelativePosition(position);
}

//set background image position
void GameGUI::setimgBackGroundRelativePosition(core::rect<s32> position, int imagePos)
{
    if (imagePos==1)
    {
        this->imgBackGround->setRelativePosition(position);
    }
    else if (imagePos == 2)
    {
        this->imgBackGroundInv->setRelativePosition(position);
    }
}

//Set imgHero Image to relative position
void GameGUI::setimgHeroRelativePosition(core::rect<s32> position)
{
    this->imgHero->setRelativePosition(position);
}

//Set imgMonster Image to relative position
void GameGUI::setimgMonsterRelativePosition(core::rect<s32> position)
{
    this->imgMonster->setRelativePosition(position);
}

//Set textLevel text
void GameGUI::settextLevel(const wchar_t *text)
{
    this->textLevel->setText(text);
}

//Set resetValue text
void GameGUI::setresetValueText(const wchar_t *text)
{
    this->resetValue->setText(text);
}

//Set heroWindowName text
void GameGUI::setheroWindowNameText(const wchar_t *text)
{
    this->heroWindowName->setText(text);
}

//Set heroWindowInfo text
void GameGUI::setheroWindowInfoText(const wchar_t *text)
{
    this->heroWindowInfo->setText(text);
}

//Set heroWindowEditName text
void GameGUI::setheroWindowEditNameText(const wchar_t *text)
{
    this->heroWindowEditName->setText(text);
}

//Set heroWindowValue text
void GameGUI::setheroWindowValueText(const wchar_t *text, int stat)
{
    switch(stat)
    {
    case HERO_INC_STR:
        this->heroWindowStrValue->setText(text);
        break;
    case HERO_INC_SPR:
        this->heroWindowDefValue->setText(text);
        break;
    case HERO_INC_SPD:
        this->heroWindowSprValue->setText(text);
        break;
    case HERO_INC_DEF:
        this->heroWindowSpdValue->setText(text);
        break;
    case HERO_INC_MAXHP:
        this->heroWindowMaxHPValue->setText(text);
        break;
    }
}

//Set statWindowValue text
void GameGUI::setStatsWindowValueText(const wchar_t *text, int stat)
{
    switch(stat)
    {
    case STAT_MONSTERS_KILLED:
        this->StatsWindowmonsteKilledValue->setText(text);
        break;
    case STAT_TIME_PLAYED:
        this->StatsWindowtimePlayedValue->setText(text);
        break;
    case STAT_DMG_DONE:
        this->StatsWindowdmgDoneValue->setText(text);
        break;
    case STAT_DMG_TAKEN:
        this->StatsWindowdmgTakenValue->setText(text);
        break;
    case STAT_LEGACY:
        this->StatsWindowlegacyNumberValue->setText(text);
        break;
    case STAT_HIGHEST_WORLD:
        this->StatsWindowhighestWorldValue->setText(text);
        break;
    }
}

//return heroWindowEditName text
std::string GameGUI::getheroWindowEditNameText()
{
    std::string tempString = core::stringc( this->heroWindowEditName->getText() ).c_str();
    return tempString;
}


//display colors on success
void GameGUI::CheckSuccess(statistics *P3Stats, int legacyNumber)
{
    //MonsterKilled
    if (P3Stats->getMonsterKilled()>=5000)
    {
        this->StatsWindowmonsteKilledSuccess4->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowmonsteKilledSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowmonsteKilledSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowmonsteKilledSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getMonsterKilled()>=500)
    {
        this->StatsWindowmonsteKilledSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowmonsteKilledSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowmonsteKilledSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getMonsterKilled()>=100)
    {
        this->StatsWindowmonsteKilledSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowmonsteKilledSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getMonsterKilled()>=25)
    {
        this->StatsWindowmonsteKilledSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }

    //TimePlayed
    if (P3Stats->getTimePlayed()>=300000)
    {
        this->StatsWindowplayingTimeSuccess4->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowplayingTimeSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowplayingTimeSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowplayingTimeSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getTimePlayed()>=50000)
    {
        this->StatsWindowplayingTimeSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowplayingTimeSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowplayingTimeSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getTimePlayed()>=6000)
    {
        this->StatsWindowplayingTimeSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowplayingTimeSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getTimePlayed()>=600)
    {
        this->StatsWindowplayingTimeSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }

    //DamageDone
    if (P3Stats->getDmgDone()>=7500000)
    {
        this->StatsWindowdmgDoneSuccess4->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgDoneSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgDoneSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgDoneSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getDmgDone()>=750000)
    {
        this->StatsWindowdmgDoneSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgDoneSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgDoneSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getDmgDone()>=100000)
    {
        this->StatsWindowdmgDoneSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgDoneSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getDmgDone()>=25000)
    {
        this->StatsWindowdmgDoneSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }

    //DamageTaken
    if (P3Stats->getDmgTaken()>=7500000)
    {
        this->StatsWindowdmgTakenSuccess4->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgTakenSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgTakenSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgTakenSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getDmgTaken()>=750000)
    {
        this->StatsWindowdmgTakenSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgTakenSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgTakenSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getDmgTaken()>=100000)
    {
        this->StatsWindowdmgTakenSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowdmgTakenSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getDmgTaken()>=25000)
    {
        this->StatsWindowdmgTakenSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }

    //Legacy
    if (legacyNumber>=5000)
    {
        this->StatsWindowlegacyNumberSuccess4->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowlegacyNumberSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowlegacyNumberSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowlegacyNumberSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (legacyNumber>=500)
    {
        this->StatsWindowlegacyNumberSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowlegacyNumberSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowlegacyNumberSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (legacyNumber>=100)
    {
        this->StatsWindowlegacyNumberSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowlegacyNumberSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (legacyNumber>=25)
    {
        this->StatsWindowlegacyNumberSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }

    //Highest World
    if (P3Stats->getHighestWorld()>=5000)
    {
        this->StatsWindowhighestWorldValueSuccess4->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowhighestWorldValueSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowhighestWorldValueSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowhighestWorldValueSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getHighestWorld()>=300)
    {
        this->StatsWindowhighestWorldValueSuccess3->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowhighestWorldValueSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowhighestWorldValueSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getHighestWorld()>=50)
    {
        this->StatsWindowhighestWorldValueSuccess2->setBackgroundColor(video::SColor (255,0,255,0));
        this->StatsWindowhighestWorldValueSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
    else if (P3Stats->getHighestWorld()>=10)
    {
        this->StatsWindowhighestWorldValueSuccess1->setBackgroundColor(video::SColor (255,0,255,0));
    }
}


