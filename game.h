///
///     \file   game.h
///     \brief  class for the game
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef GAME_H
#define GAME_H

#include <irrlicht.h>
#include <string>
#include <vector>

#include "GameGUI.h"
#include "MyEventReceiver.h"
#include "hero.h"
#include "monster.h"
#include "statistics.h"
#include "database.h"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Game
{
    public:
        ///
        ///     \fn         Game()
        ///     \brief      constructor of the game object
        ///
        Game();
        ///
        ///     \fn         ~Game()
        ///     \brief      constructor of the game object
        ///
        virtual ~Game();

        //Methods/functions
        ///
        ///     \fn         run()
        ///     \brief      main fn to run the game
        ///
        void run();
        ///
        ///     \fn         resetGame();
        ///     \brief      reset the game when the hero dies
        ///
        void resetGame();
        ///
        ///     \fn         incWorldNumber()
        ///     \brief      increase the world number when the hero kills a monster
        ///
        void incWorldNumber();
        ///
        ///     \fn         displayDebugHeroStats()
        ///     \brief      debug fn, display in console all hero/statistics/world data
        ///
        void displayDebugHeroStats();
        ///
        ///     \fn         IncHeroStat(int stat)
        ///     \brief      increase one of the hero stat based on the param
        ///     \param      stat: define what stat to increase (see enums.h)
        ///
        void IncHeroStat(int stat);
        ///
        ///     \fn         loadMonstersNameFromFile()
        ///     \brief      load the monsters textures from the file monsters.txt
        ///
        void loadMonstersNameFromFile();
        ///
        ///     \fn         displayHeroStats()
        ///     \brief      update the char window with hero's stats
        ///
        void displayHeroStats();
        ///
        ///     \fn         displayGameStats()
        ///     \brief      update the statistics window with game's stats
        ///
        void displayGameStats();
        ///
        ///     \fn         CheckSuccess()
        ///     \brief      update display of the success in the statistics window
        ///
        void CheckSuccess();
        ///
        ///     \fn         changeHeroStatus(int status)
        ///     \brief      update hero status depending on his next action
        ///     \param      status: define the hero's action (see enums.h)
        ///
        void changeHeroStatus(int status);
        ///
        ///     \fn         InitSaveGame()
        ///     \brief      prepare the database when starting a new game
        ///
        void InitSaveGame();
        ///
        ///     \fn         SaveGame()
        ///     \brief      save the game in the database
        ///
        void SaveGame();
        ///
        ///     \fn         loadGame()
        ///     \brief      load the saved game from the database
        ///
        void loadGame();
        ///
        ///     \fn         checkName()
        ///     \brief      check if the name entered in the edit box is valid
        ///
        void checkName();
        ///
        ///     \fn         heroWalk(int position)
        ///     \brief      display the walking animation
        ///     \param      position: to know what image to set for the animation
        ///
        void heroWalk(int position);
        ///
        ///     \fn         heroFight()
        ///     \brief      display the fighting animation
        ///
        void heroFight();
        ///
        ///     \fn         heroRegen()
        ///     \brief      display the regening animation
        ///
        void heroRegen();
        ///
        ///     \fn         displayMonster()
        ///     \brief      randomly chose a monster image to show
        ///
        void displayMonster();
        ///
        ///     \fn         monsterFight()
        ///     \brief      display the monster fighting animation
        ///
        void monsterFight();
        ///
        ///     \fn         int getDateTime()
        ///     \brief      generate the date as int
        ///     \return     return DateTimeReturn as int
        ///
        int getDateTime();
        ///
        ///     \fn         saveOldGame()
        ///     \brief      move and rename the saved game file if the player start a new game
        ///
        void saveOldGame();
        ///
        ///     \fn         loadTextures()
        ///     \brief      load textures for the game
        ///
        void loadTextures();


        //get
        ///
        ///     \fn         int getWorldNumber()
        ///     \brief      to get game's world number

        ///
        int getWorldNumber();


        //set
        ///
        ///     \fn         setWorldNumber(int number)
        ///     \brief      to set game's world number
        ///     \param      world number to set as float
        ///
        void setWorldNumber(int number);

        IGUIEnvironment *guienv;
        GameGUI *gui;
    protected:

    private:
        //Irrlicht
        IrrlichtDevice *device;
        IVideoDriver *driver;
        MyEventReceiver *receiver;
        //Game
        f32 frameDeltaTime;
        core::stringw levelstr;
        float walkingDistance;
        int BackgroundInc1;
        int BackgroundInc2;
        bool firstFightBool;
        bool fightTurnBool;
        Hero *LegacyBoy;
        Monster *enemyMonster;
        int worldNumber;
        int incHero;
        std::vector<std::string> vMonsters;
        statistics *P3Stats;
        //Database
        database *myDB;
        //texture
        ITexture* textureTitle;
        ITexture* textureNotAClicker;
        ITexture* textureBtnNewGAme;
        ITexture* textureBtnLoadGame;
        ITexture* textureBtnOthers;
        ITexture* textureMonster;
        ITexture* texBackground;
        ITexture* texBackgroundInv;
        ITexture* textureHeroWalk1;
        ITexture* textureHeroWalk2;
        ITexture* textureHeroWalk3;
        ITexture* textureHeroWalk4;
        ITexture* textureHeroFight;
        ITexture* textureHeroRegen1;
        ITexture* textureHeroRegen2;
        ITexture* textureHeroRegen3;


};

#endif // GAME_H
