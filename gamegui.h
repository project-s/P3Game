///
///     \file   gamegui.h
///     \brief  class for the game user interface
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <irrlicht.h>
#include <iostream>

#include "enums.h"
#include "statistics.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class GameGUI
{
    public:
        ///
        ///     \fn         GameGUI(IGUIEnvironment *guienv)
        ///     \brief      constructor of the game graphical user interface
        ///     \param      pointer for the gui environment
        ///
        GameGUI(IGUIEnvironment *guienv);
        ///
        ///     \fn         ~GameGUI()
        ///     \brief      destructor of the game graphical user interface
        ///
        virtual ~GameGUI();

        //Var
        IGUIEnvironment *guienv;

        //M/F
        ///
        ///     \fn         removeHPBarMonster()
        ///     \brief      remove monster HP bar
        ///
        void removeHPBarMonster();
        ///
        ///     \fn         removeHpBarHero()
        ///     \brief      remove hero HP bar
        ///
        void removeHpBarHero();
        ///
        ///     \fn         FightHPBars()
        ///     \brief      display both HP bars at the beginning of a fight
        ///
        void FightHPBars();
        ///
        ///     \fn         drawHpBarHero(float modifPosition)
        ///     \brief      display modified hero HP bar based on the modifPosition
        ///     \param      HP bars height defined by modifPosition as float
        ///
        void drawHpBarHero(float modifPosition);
        ///
        ///     \fn         drawHpMonster(float modifPosition)
        ///     \brief      display modified monster HP bar based on the modifPosition
        ///     \param      HP bars height defined by modifPosition as float
        ///
        void drawHpMonster(float modifPosition);

        ///
        ///     \fn         CheckSuccess(statistics *P3Stats, int legacyNumber)
        ///     \brief      display colors on success
        ///     \param      P3Stats pointer to game stats
        ///     \param      legacyNumber as the number of legacy from the hero
        ///
        void CheckSuccess(statistics *P3Stats, int legacyNumber);

        //Set window visible
        ///
        ///     \fn         setWelcomeWindowVisible(bool status)
        ///     \brief      Hide/show the welcome Window
        ///     \param      status true to show, false to hide
        ///
        void setWelcomeWindowVisible(bool status);
        ///
        ///     \fn         setgameWindowVisible(bool status)
        ///     \brief      Hide/show the game Window
        ///     \param      status true to show, false to hide
        ///
        void setgameWindowVisible(bool status);
        ///
        ///     \fn         setresetWindowVisible(bool status)
        ///     \brief      Hide/show the reset Window
        ///     \param      status true to show, false to hide
        ///
        void setresetWindowVisible(bool status);
        ///
        ///     \fn         setheroWindowVisible(bool status)
        ///     \brief      Hide/show the hero Window
        ///     \param      status true to show, false to hide
        ///
        void setheroWindowVisible(bool status);
        ///
        ///     \fn         setStatsWindowVisible(bool status)
        ///     \brief      Hide/show the stats Window
        ///     \param      status true to show, false to hide
        ///
        void setStatsWindowVisible(bool status);
        ///
        ///     \fn         setbtnLoadGameVisible(bool status)
        ///     \brief      Hide/show the Load game button
        ///     \param      status true to show, false to hide
        ///
        void setbtnLoadGameVisible(bool status);
        ///
        ///     \fn         setimgMonsterVisible(bool status)
        ///     \brief      Hide/show the Monster image
        ///     \param      status true to show, false to hide
        ///
        void setimgMonsterVisible(bool status);
        //Set Textures / images
        ///
        ///     \fn         setimgBackGroundImage(ITexture *texBackground)
        ///     \brief      Set imgBackGround Image;
        ///     \param      texBackground pointer to the background texture
        ///
        void setimgBackGroundImage(ITexture *texBackground);
        ///
        ///     \fn         setimgBackGroundInvImage(ITexture *texBackgroundInv)
        ///     \brief      Set imgBackGroundInv Image;
        ///     \param      texBackgroundInv pointer to the backgroundinv texture
        ///
        void setimgBackGroundInvImage(ITexture *texBackgroundInv);
        ///
        ///     \fn         setimgTitleImage(ITexture *textureTitle)
        ///     \brief      Set imgTitle Image;
        ///     \param      textureTitle pointer to the imgTitle texture
        ///
        void setimgTitleImage(ITexture *textureTitle);
        ///
        ///     \fn         setimgNotAClickerImage(ITexture *textureNotAClicker)
        ///     \brief      Set imgNotAClicker Image;
        ///     \param      textureNotAClicker pointer to the imgNotAClicker texture
        ///
        void setimgNotAClickerImage(ITexture *textureNotAClicker);
        ///
        ///     \fn         setbtnNewGameImage(ITexture *textureBtnNewGAme)
        ///     \brief      Set btnNewGame Image;
        ///     \param      textureBtnNewGAme pointer to the btnNewGame texture
        ///
        void setbtnNewGameImage(ITexture *textureBtnNewGAme);
        ///
        ///     \fn         setbtnLoadGameImage(ITexture *textureBtnLoadGame)
        ///     \brief      Set btnLoadGame Image;
        ///     \param      textureBtnLoadGame pointer to the btnLoadGame texture
        ///
        void setbtnLoadGameImage(ITexture *textureBtnLoadGame);
        ///
        ///     \fn         setDefaultBtnImage(ITexture *textureBtnOthers)
        ///     \brief      Set textureBtnOthers Image to default button;
        ///     \param      textureBtnOthers pointer to the textureBtnOthers texture
        ///
        void setDefaultBtnImage(ITexture *textureBtnOthers);
        ///
        ///     \fn         setimgHeroImage(ITexture *textureHero)
        ///     \brief      Set textureHero Image to imgHero
        ///     \param      textureHero pointer to the imgHero texture
        ///
        void setimgHeroImage(ITexture *textureHero);
        ///
        ///     \fn         setimgMonsterImage(ITexture *textureMonster)
        ///     \brief      Set textureMonster Image to imgMonster
        ///     \param      textureMonster pointer to the imgMonster texture
        ///
        void setimgMonsterImage(ITexture *textureMonster);
        //Moving/positionning
        ///
        ///     \fn         setbtnNewGameRelativePosition(core::rect<s32> position)
        ///     \brief      Set btnNewGame Image to relative position;
        ///     \param      position to where to display the btnNewGame
        ///
        void setbtnNewGameRelativePosition(core::rect<s32> position);
        ///
        ///     \fn         setimgBackGroundRelativePosition(core::rect<s32> position, int imagePos)
        ///     \brief      Set imgBackGround Image to relative position;
        ///     \param      position to where to display the imgBackGround
        ///     \param      imagePos to define what image to move
        ///
        void setimgBackGroundRelativePosition(core::rect<s32> position, int imagePos);
        ///
        ///     \fn         setimgBackGroundInvRelativePosition(core::rect<s32> position)
        ///     \brief      Set imgBackGroundInv Image to relative position;
        ///     \param      position to where to display the imgBackGroundInv
        ///
        void setimgBackGroundInvRelativePosition(core::rect<s32> position);
        ///
        ///     \fn         setimgHeroRelativePosition(core::rect<s32> position)
        ///     \brief      Set imgHero Image to relative position;
        ///     \param      position to where to display the imgHero
        ///
        void setimgHeroRelativePosition(core::rect<s32> position);
        ///
        ///     \fn         setimgMonsterRelativePosition(core::rect<s32> position)
        ///     \brief      Set imgMonster Image to relative position;
        ///     \param      position to where to display the imgMonster
        ///
        void setimgMonsterRelativePosition(core::rect<s32> position);
        //set
        ///
        ///     \fn         settextLevel(const wchar_t *text)
        ///     \brief      Set textLevel text
        ///     \param      text to show in the textLevel label
        ///
        void settextLevel(const wchar_t *text);
        ///
        ///     \fn         setheroWindowNameText(const wchar_t *text)
        ///     \brief      Set heroWindowName text
        ///     \param      text to show in the heroWindowName label
        ///
        void setheroWindowNameText(const wchar_t *text);
        ///
        ///     \fn         setheroWindowInfoText(const wchar_t *text)
        ///     \brief      Set heroWindowInfo text
        ///     \param      text to show in the heroWindowInfo label
        ///
        void setheroWindowInfoText(const wchar_t *text);
        ///
        ///     \fn         setheroWindowEditNameText(const wchar_t *text)
        ///     \brief      Set heroWindowEditName text
        ///     \param      text to show in the heroWindowEditName label
        ///
        void setheroWindowEditNameText(const wchar_t *text);
        ///
        ///     \fn         setresetValueText(const wchar_t *text)
        ///     \brief      Set resetValue text
        ///     \param      text to show in the resetValue label
        ///
        void setresetValueText(const wchar_t *text);
        ///
        ///     \fn         setheroWindowValueText(const wchar_t *text, int stat)
        ///     \brief      Set heroWindowValue text
        ///     \param      text to show in the heroWindowStrValue label
        ///     \param      stat to select what stat to display
        ///
        void setheroWindowValueText(const wchar_t *text, int stat);
        ///
        ///     \fn         setStatsWindowValueText(const wchar_t *text, int stat)
        ///     \brief      Set statWindowValue text
        ///     \param      text to show in the statWindowValue label
        ///     \param      stat to select what stat to display
        ///
        void setStatsWindowValueText(const wchar_t *text, int stat);
        //get
        ///
        ///     \fn         getheroWindowEditNameText()
        ///     \brief      return heroWindowEditName text
        ///     \return     text to return from the heroWindowEditName label
        ///
        std::string getheroWindowEditNameText();

    protected:

    private:
        //Welcome Window
        IGUIStaticText  *welcomeWindow;
        IGUIStaticText  *textTitle;
        IGUIImage       *imgTitle;
        IGUIImage       *imgNotAClicker;
        IGUIStaticText  *textSubTitle;
        IGUIStaticText  *textFooter;
        IGUIButton      *btnNewGame;
        IGUIButton      *btnLoadGame;

        //Game Window
        IGUIStaticText  *gameWindow;
        IGUIStaticText  *textLevel;
        IGUIStaticText  *HpBarHero;
        IGUIStaticText  *HPBarMonster;
        IGUIStaticText  *gameFooter;
        IGUIImage       *imgBackGround;
        IGUIImage       *imgBackGroundInv;
        IGUIImage       *imgHero;
        IGUIImage       *imgMonster;
        IGUIButton      *btnChar;
        IGUIButton      *btnStats;
        ITexture        *tex;

        //Reset window
        IGUIStaticText  *resetWindow;
        IGUIStaticText  *textGameOver;
        IGUIStaticText  *resetValue;
        IGUIButton      *btnSPR;
        IGUIButton      *btnSTR;
        IGUIButton      *btnSPD;
        IGUIButton      *btnDEF;

        //Hero Window
        IGUIStaticText  *heroWindow;
        IGUIStaticText  *heroWindowTitle;
        IGUIStaticText  *heroWindowName;
        IGUIEditBox     *heroWindowEditName;
        IGUIStaticText  *heroWindowInfo;
        IGUIStaticText  *heroWindowStr;
        IGUIStaticText  *heroWindowDef;
        IGUIStaticText  *heroWindowSpr;
        IGUIStaticText  *heroWindowSpd;
        IGUIStaticText  *heroWindowMaxHP;
        IGUIStaticText  *heroWindowStrValue;
        IGUIStaticText  *heroWindowDefValue;
        IGUIStaticText  *heroWindowSprValue;
        IGUIStaticText  *heroWindowSpdValue;
        IGUIStaticText  *heroWindowMaxHPValue;
        IGUIButton      *btnHeroBack;

        //Stats Window
        IGUIStaticText  *StatsWindow;
        IGUIStaticText  *statsWindowTitle;
        IGUIStaticText  *StatsWindowmonsteKilled;
        IGUIStaticText  *StatsWindowmonsteKilledValue;
        IGUIStaticText  *StatsWindowtimePlayed;
        IGUIStaticText  *StatsWindowtimePlayedValue;
        IGUIStaticText  *StatsWindowdmgDone;
        IGUIStaticText  *StatsWindowdmgDoneValue;
        IGUIStaticText  *StatsWindowdmgTaken;
        IGUIStaticText  *StatsWindowdmgTakenValue;
        IGUIStaticText  *StatsWindowlegacyNumber;
        IGUIStaticText  *StatsWindowlegacyNumberValue;
        IGUIStaticText  *StatsWindowhighestWorld;
        IGUIStaticText  *StatsWindowhighestWorldValue;
        IGUIButton      *btnStatsBack;

                //Stats Window Success
        IGUIStaticText  *StatsWindowmonsteKilledSuccess1;
        IGUIStaticText  *StatsWindowmonsteKilledSuccess2;
        IGUIStaticText  *StatsWindowmonsteKilledSuccess3;
        IGUIStaticText  *StatsWindowmonsteKilledSuccess4;
        IGUIStaticText  *StatsWindowplayingTimeSuccess1;
        IGUIStaticText  *StatsWindowplayingTimeSuccess2;
        IGUIStaticText  *StatsWindowplayingTimeSuccess3;
        IGUIStaticText  *StatsWindowplayingTimeSuccess4;
        IGUIStaticText  *StatsWindowdmgDoneSuccess1;
        IGUIStaticText  *StatsWindowdmgDoneSuccess2;
        IGUIStaticText  *StatsWindowdmgDoneSuccess3;
        IGUIStaticText  *StatsWindowdmgDoneSuccess4;
        IGUIStaticText  *StatsWindowdmgTakenSuccess1;
        IGUIStaticText  *StatsWindowdmgTakenSuccess2;
        IGUIStaticText  *StatsWindowdmgTakenSuccess3;
        IGUIStaticText  *StatsWindowdmgTakenSuccess4;
        IGUIStaticText  *StatsWindowlegacyNumberSuccess1;
        IGUIStaticText  *StatsWindowlegacyNumberSuccess2;
        IGUIStaticText  *StatsWindowlegacyNumberSuccess3;
        IGUIStaticText  *StatsWindowlegacyNumberSuccess4;
        IGUIStaticText  *StatsWindowhighestWorldValueSuccess1;
        IGUIStaticText  *StatsWindowhighestWorldValueSuccess2;
        IGUIStaticText  *StatsWindowhighestWorldValueSuccess3;
        IGUIStaticText  *StatsWindowhighestWorldValueSuccess4;

};

#endif // GAMEGUI_H
