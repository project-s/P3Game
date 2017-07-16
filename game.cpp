#include "Game.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>

Game::Game()
{
    //ctor
    //Creating device for Irrlicht
    device = createDevice(EDT_SOFTWARE, dimension2d<u32>(564, 480), 16,false, false, false, 0);
    driver = device->getVideoDriver();
    guienv = device->getGUIEnvironment();

    //Creating the GUI class
    gui = new GameGUI(guienv);

    //Event receiver
    receiver = new MyEventReceiver(this);

    //Link between the device and the envent receiver
    device->setEventReceiver(receiver);

    //construct hero
    LegacyBoy = new Hero();

    //construct stats
    P3Stats = new statistics();

    //textures
    loadTextures();

    //var
    walkingDistance = 100;
    BackgroundInc1=564;
    BackgroundInc2=0;
    firstFightBool = true;
    fightTurnBool = true;
    worldNumber = 1;
    levelstr = L"Level ";
    incHero = 0;

    //Load monsters
    loadMonstersNameFromFile();

    //Check if file DB already exists
    std::ifstream ifile(".\\LegacyGame.db");
    if (ifile)
    {
        //file exists, display load game button
        gui->setbtnLoadGameVisible(true);
    }
    else
    {
        //file doesnt exist, center the new game button
        gui->setbtnNewGameRelativePosition(core::rect<s32>(282-50,200,282+50,200+100));
    }
}

Game::~Game()
{
    //dtor
    device->drop();
    delete LegacyBoy;
}

void Game::run()
{
    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    u32 then = device->getTimer()->getTime();

    //initialize the clock
    std::clock_t start;
    start = std::clock();

    //initializing FPS
    int lastFPS = -1;

    //level display
    levelstr += this->worldNumber;
    gui->settextLevel(levelstr.c_str());

    //Main Loop
    while (device->run())
    {
        // Work out a frame delta time.
        const u32 now = device->getTimer()->getTime();
        frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
        then = now;

        //*********************************************************************************************
        //START : the 3 hero status check
        //*********************************************************************************************
        //Hero walk
        //*********************************************************************************************
        if(LegacyBoy->getHeroStatus()==HERO_STATUS_WALK)    //hero->getstatus()=HERO_STATUS_WALK
        {
            //maths! How long he'll walk before next fight / depends on his spd
            walkingDistance = walkingDistance - ( ( LegacyBoy->getSpd()/ 8.0f ) * frameDeltaTime );
            //moving background
            BackgroundInc1+=LegacyBoy->getSpd()/50;
            BackgroundInc2+=LegacyBoy->getSpd()/50;
            //hero walking animation : based on BackgroundInc1
            heroWalk((( BackgroundInc1 / 12) % 12 ) + 1 );
            gui->setimgBackGroundRelativePosition(core::rect<s32>(564-BackgroundInc1,0, 564,423), 1);
            gui->setimgBackGroundRelativePosition(core::rect<s32>(564-BackgroundInc2,0, 564,423), 2);
            //when out of the screen, reset the images position
            if (BackgroundInc1>=1128)
            {
                BackgroundInc1=0;
                gui->setimgBackGroundRelativePosition(core::rect<s32>(1128,0, 564,423), 1);

            }
            if (BackgroundInc2>=1128)
            {
                BackgroundInc2=0;
                gui->setimgBackGroundRelativePosition(core::rect<s32>(1128,0, 564,423), 2);

            }
            //Hero done walking, reset walkingDistance, change hero status
            if(walkingDistance <0)
            {
                walkingDistance=100;
                LegacyBoy->setHeroStatus(HERO_STATUS_FIGHT);
            }
        }
        //*********************************************************************************************
        //hero fight
        //*********************************************************************************************
        else if (LegacyBoy->getHeroStatus()==HERO_STATUS_FIGHT)
        {
            //first time in the loop, load monster image + HPbars
            if (firstFightBool)
            {
                gui->FightHPBars();
                enemyMonster = new Monster(powf(1.15, this->getWorldNumber()));
                gui->setimgMonsterVisible(true);
                displayMonster();
                firstFightBool=false;
            }
            //who's attacking
            if (fightTurnBool)
            {
                //hero fighting animation
                heroFight();
                //hero attacks + increase stats Dmg Done
                P3Stats->increaseDmgDone(LegacyBoy->fight(enemyMonster));
                //remove HPBar and redraw it with new hp value
                gui->drawHpMonster(enemyMonster->getHP()/enemyMonster->getMaxHP());
                //monster's turn to fight, change fightTurnBool
                fightTurnBool=false;
            }
            else
            {
                //monster fighting animation
                monsterFight();
                //Enemy attacks + increase stats Dmg Taken
                P3Stats->increaseDmgTaken(enemyMonster->fight(LegacyBoy));
                //remove HPBar and redraw it with new hp value
                gui->drawHpBarHero(LegacyBoy->getHP()/LegacyBoy->getMaxHP());
                //Hero's turn to fight, change fightTurnBool
                fightTurnBool=true;
            }

            //test if hero or monster is dead
            if (LegacyBoy->getHP()==0 || enemyMonster->getHP()==0)
            {
                //fight's OVER
                //hide monster
                gui->setimgMonsterVisible(false);
                //reset hero's img position
                gui->setimgHeroRelativePosition(core::rect<s32>(282-130,150+100,282-30,150+200));
                //reset Bools for next fight
                fightTurnBool=true;
                firstFightBool=true;
                //who died?
                if (LegacyBoy->getHP()==0)
                {
                    this->resetGame();
                }
                else
                {
                    //increase Stat Monster Killed
                    P3Stats->increaseMonsteKilled();
                    //increase world number
                    this->incWorldNumber();
                    //change hero status to REGEN
                    LegacyBoy->setHeroStatus(HERO_STATUS_REGEN);
                    //remove monster's HP bar
                    gui->removeHPBarMonster();
                }
                //update timePlayed
                P3Stats->incTimePlayed(( std::clock() - start ) / (double) CLOCKS_PER_SEC);
                start = std::clock();
                //Update stats page
                CheckSuccess();
                displayGameStats();
                //auto saving game
                SaveGame();
            }
        }
        //*********************************************************************************************
        //hero regen
        //*********************************************************************************************
        else if (LegacyBoy->getHeroStatus()==HERO_STATUS_REGEN)
        {
            //maths! How fast he'll regen / depending on his SPR
            LegacyBoy->regenHP(( LegacyBoy->getSPR()/ 4.0f ) * frameDeltaTime );
            //hero regen animation
            heroRegen();
            //test if hero is full health
            if (LegacyBoy->getHP()>=LegacyBoy->getMaxHP())
            {
                LegacyBoy->setHP(LegacyBoy->getMaxHP());
                LegacyBoy->setHeroStatus(HERO_STATUS_WALK);
                gui->removeHpBarHero();
                //change level displayed
                levelstr = L"Level ";
                levelstr += this->worldNumber;
                gui->settextLevel(levelstr.c_str());
            }
            else
            {
                //redraw the hp bar
                gui->drawHpBarHero(LegacyBoy->getHP()/LegacyBoy->getMaxHP());
            }
        }
        //*********************************************************************************************
        //END : the 3 hero status check
        //*********************************************************************************************

        //Render Loop
        driver->beginScene(true, true, SColor(0,200,200,200));
        guienv->drawAll();
        driver->endScene();

        //Display/update FPS from the windows' bar
        int fps = driver->getFPS();
        if (lastFPS != fps)
        {
            core::stringw tmp(L"That #Idle #Incremental #Legacy #Game | FPS: ");
            tmp += fps;
            device->setWindowCaption(tmp.c_str());
            lastFPS = fps;
        }

        //limiting fps with sleep
        device->sleep(5);
    }
}

//F/M
void Game::resetGame()
{
    //remove HP Bars
    gui->removeHPBarMonster();
    gui->removeHpBarHero();
    //display reset window
    gui->setresetWindowVisible(true);
    levelstr = L"World ";
    levelstr += this->worldNumber-1;
    gui->setresetValueText(levelstr.c_str());
    //change hero status to RESET
    LegacyBoy->setHeroStatus(HERO_STATUS_RESET);
    //increase MaxHP and set HP to Max
    LegacyBoy->incMaxHP(powf(1.1, this->getWorldNumber()));
    LegacyBoy->setHP(LegacyBoy->getMaxHP());
    LegacyBoy->incLegacyNumber();
    P3Stats->increaseLegacyNumber();
}

void Game::IncHeroStat(int stat)
{
    P3Stats->increaseHighestWorld(this->getWorldNumber());
    gui->settextLevel(L"Level 1");
    gui->setresetWindowVisible(false);

    LegacyBoy->setHeroStatus(HERO_STATUS_WALK);
    this->incHero=0;
    gui->setresetWindowVisible(false);

    switch(stat)
    {
    case HERO_INC_STR:
        this->LegacyBoy->incSTR(powf(1.1, this->getWorldNumber()));
        break;
    case HERO_INC_SPR:
        this->LegacyBoy->incSPR(powf(1.1, this->getWorldNumber()));
        break;
    case HERO_INC_SPD:
        this->LegacyBoy->incSPD(powf(1.1, this->getWorldNumber()));
        break;
    case HERO_INC_DEF:
        this->LegacyBoy->incDEF(powf(1.1, this->getWorldNumber()));
        break;
    }
    this->setWorldNumber(1);
}

void Game::displayDebugHeroStats()
{
    std::cout << "*********************************" << std::endl;
    std::cout << "*****HERO************************" << std::endl;
    std::cout << "* Legacy : \t\t" << LegacyBoy->getLegacyNumber()  << std::endl;
    std::cout << "* WorldNumber : \t" << getWorldNumber() << std::endl;
    std::cout << "* STR : \t\t" << LegacyBoy->getSTR() << std::endl;
    std::cout << "* SPD : \t\t" << LegacyBoy->getSpd() << std::endl;;
    std::cout << "* SPR : \t\t" << LegacyBoy->getSPR() << std::endl;
    std::cout << "* DEF : \t\t" << LegacyBoy->getDEF() << std::endl;
    std::cout << "* MaxHP : \t\t" << LegacyBoy->getMaxHP() << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "*****STATISTICS******************" << std::endl;
    std::cout << "* Monster killed : \t" << P3Stats->getMonsterKilled() << std::endl;
    std::cout << "* Dmg Done : \t\t" << P3Stats->getDmgDone() << std::endl;
    std::cout << "* Dmg Taken : \t\t" << P3Stats->getDmgTaken() << std::endl;
    std::cout << "* TimePlayed : \t\t" << P3Stats->getTimePlayed() << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "*****MONSTER******************" << std::endl;
    std::cout << "* STR : \t\t" << enemyMonster->getSTR() << std::endl;
    std::cout << "* DEF : \t\t" << enemyMonster->getDEF() << std::endl;
    std::cout << "* MaxHP : \t\t" << enemyMonster->getMaxHP() << std::endl;
    std::cout << "*********************************" << std::endl;
}

void Game::incWorldNumber()
{
    this->worldNumber++;
}

void Game::loadMonstersNameFromFile()
{
    std::ifstream file(".\\IMG\\MONSTERS\\monstersList.txt");
    std::string str;
    while (std::getline(file, str))
    {
        // Process str
        vMonsters.push_back(str.c_str());
    }
}
void Game::changeHeroStatus(int status)
{
    this->LegacyBoy->setHeroStatus(status);
}

void Game::displayHeroStats()
{
    levelstr = L"";
    levelstr += this->LegacyBoy->getSTR();
    gui->setheroWindowValueText(levelstr.c_str(), HERO_INC_STR);

    levelstr = L"";
    levelstr += this->LegacyBoy->getDEF();
    gui->setheroWindowValueText(levelstr.c_str(), HERO_INC_DEF);

    levelstr = L"";
    levelstr += this->LegacyBoy->getSPR();
    gui->setheroWindowValueText(levelstr.c_str(), HERO_INC_SPR);

    levelstr = L"";
    levelstr += this->LegacyBoy->getSpd();
    gui->setheroWindowValueText(levelstr.c_str(), HERO_INC_SPD);

    levelstr = L"";
    levelstr += this->LegacyBoy->getMaxHP();
    gui->setheroWindowValueText(levelstr.c_str(), HERO_INC_MAXHP);
}

void Game::displayGameStats()
{
    levelstr = L"";
    levelstr += this->P3Stats->getMonsterKilled();
    gui->setStatsWindowValueText(levelstr.c_str(), STAT_MONSTERS_KILLED);

    levelstr = L"";
    levelstr += this->P3Stats->getTimePlayed();
    gui->setStatsWindowValueText(levelstr.c_str(), STAT_TIME_PLAYED);

    levelstr = L"";
    levelstr += this->P3Stats->getDmgDone() ;
    gui->setStatsWindowValueText(levelstr.c_str(), STAT_DMG_DONE);

    levelstr = L"";
    levelstr += this->P3Stats->getDmgTaken();
    gui->setStatsWindowValueText(levelstr.c_str(), STAT_DMG_TAKEN);

    levelstr = L"";
    levelstr += this->LegacyBoy->getLegacyNumber();
    gui->setStatsWindowValueText(levelstr.c_str(), STAT_LEGACY);

    levelstr = L"";
    levelstr += this->P3Stats->getHighestWorld();
    gui->setStatsWindowValueText(levelstr.c_str(), STAT_HIGHEST_WORLD);

}

void Game::CheckSuccess()
{
    gui->CheckSuccess(P3Stats, LegacyBoy->getLegacyNumber());
}

void Game::InitSaveGame()
{
    myDB = new database(LegacyBoy, P3Stats);
    myDB->createTable();
    myDB->closeDatabase();
    myDB->openDatabase();
    myDB->initTable();
    delete myDB;
}

void Game::SaveGame()
{
    myDB = new database(LegacyBoy, P3Stats);
    myDB->updateTable(getWorldNumber());
    delete myDB;
}

void Game::loadGame()
{
    myDB = new database(LegacyBoy, P3Stats);
    setWorldNumber(myDB->loadGame());
    delete myDB;
    levelstr = L"World ";
    levelstr += this->worldNumber;
    gui->settextLevel(levelstr.c_str());
    levelstr = L"";
    levelstr += (LegacyBoy->getName()).c_str();
    //gui->heroWindowName->setText(levelstr.c_str());
    gui->setheroWindowNameText(levelstr.c_str());
    LegacyBoy->setHP(LegacyBoy->getMaxHP());

    std::cout << "*********************************" << std::endl;
    std::cout << "*********HERO********************" << std::endl;
    std::cout << "* Nom : \t\t" << LegacyBoy->getName()  << std::endl;
    std::cout << "* Legacy : \t\t" << LegacyBoy->getLegacyNumber()  << std::endl;
    std::cout << "* WorldNumber : \t" << getWorldNumber() << std::endl;
    std::cout << "* STR : \t\t" << LegacyBoy->getSTR() << std::endl;
    std::cout << "* SPD : \t\t" << LegacyBoy->getSpd() << std::endl;;
    std::cout << "* SPR : \t\t" << LegacyBoy->getSPR() << std::endl;
    std::cout << "* DEF : \t\t" << LegacyBoy->getDEF() << std::endl;
    std::cout << "* MaxHP : \t\t" << LegacyBoy->getMaxHP() << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "*****STATISTICS******************" << std::endl;
    std::cout << "* Monster killed : \t" << P3Stats->getMonsterKilled() << std::endl;
    std::cout << "* Dmg Done : \t\t" << P3Stats->getDmgDone() << std::endl;
    std::cout << "* Dmg Taken : \t\t" << P3Stats->getDmgTaken() << std::endl;
    std::cout << "* TimePlayed : \t\t" << P3Stats->getTimePlayed() << std::endl;
    std::cout << "*********************************" << std::endl;
}

void Game::checkName()
{
    unsigned int i=0;
    bool acceptedWord = true;
    std::string tempString = gui->getheroWindowEditNameText();
    if (tempString.size()>0)
    {
        std::string acceptedLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while (i<tempString.size() && acceptedWord)
        {
            std::size_t found = acceptedLetters.find(tempString[i]);
            if (found==std::string::npos)
            {
                //letters of the editBox word isn't valid
                gui->setheroWindowInfoText(L"Invalid character !");
                acceptedWord = false;
            }
            ++i;
        }
    }
    else
    {
        acceptedWord = false;
    }

    if(acceptedWord)
    {
        LegacyBoy->setName(tempString.c_str());
        core::stringw tmp = L"";
        tmp += tempString.c_str();
        gui->setheroWindowNameText(tmp.c_str());
        gui->setheroWindowInfoText(L"You can change the hero's name up here. \n 25 letters maximum");
    }
    gui->setheroWindowEditNameText(L"");
}

void Game::heroWalk(int position)
{
    switch(position)
    {
        case 1:
            gui->setimgHeroImage(textureHeroWalk1);
            break;
        case 4:
            gui->setimgHeroImage(textureHeroWalk2);
            break;
        case 7:
            gui->setimgHeroImage(textureHeroWalk3);
            break;
        case 10:
            gui->setimgHeroImage(textureHeroWalk4);
            break;
        default:
            break;
    }
}

void Game::heroFight()
{
    //move image to random position
    int vRand = +rand()%30;
    int hRand = +rand()%30;
    //gui->imgHero->setRelativePosition(core::rect<s32>(282-130+hRand,150+100+vRand,282-30+hRand,150+200+vRand));
    gui->setimgHeroRelativePosition(core::rect<s32>(282-130+hRand,150+100+vRand,282-30+hRand,150+200+vRand));
    gui->setimgHeroImage(textureHeroFight);
}

void Game::heroRegen()
{
    int pos = (LegacyBoy->getHP()/10);
    pos = ((pos*33) %8 )+1;
    switch(pos)
    {
        case 1:
        case 2:
        case 5:
        case 6:
            gui->setimgHeroImage(textureHeroRegen1);
            break;
        case 3:
        case 4:
            gui->setimgHeroImage(textureHeroRegen2);
            break;
        case 7:
        case 8:
            gui->setimgHeroImage(textureHeroRegen3);
            break;
        default:
            break;
    }
}

void Game::displayMonster()
{
    std::string monsterName = vMonsters[(rand()%vMonsters.size())];
    core::stringw tmp = L".\\IMG\\MONSTERS\\";
    tmp += monsterName.c_str();
    this->textureMonster = driver->getTexture(tmp);
    gui->setimgMonsterImage(textureMonster);
    driver->removeTexture(textureMonster);
}

void Game::monsterFight()
{
    //move image to random position
    int vRand = +rand()%30;
    int hRand = +rand()%30;
    gui->setimgMonsterRelativePosition(core::rect<s32>(282+2+hRand,150+72+vRand,282+130+hRand,150+200+vRand));
}

int Game::getDateTime()
{
    time_t  timev = time(NULL);
    struct tm *aTime = localtime(&timev);
    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900
    int DateTimeReturn = (year * 10000) + (month * 100) + day ;
    return  DateTimeReturn;
}

void Game::saveOldGame()
{
    //FOLDER EXISTS?
    // CreatingFolder
    std::string OutputFolder = ".\\OldSavedGames";
    if (CreateDirectory(OutputFolder.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError())
    {
        //folder exists
    }
    //FILE EXISTS?
    std::ifstream ifile(".\\LegacyGame.db");
    if (ifile) {
        // Copying File
        std::ifstream  src("LegacyGame.db", std::ios::binary);
        time_t  timev = time(NULL);
        std::stringstream copiedFile;
        copiedFile << ".\\OldSavedGames\\LegacyGame" << getDateTime() << timev << ".db";
        std::string strCopiedFile = copiedFile.str();
        std::ofstream  dst(strCopiedFile.c_str(), std::ios::binary);
        dst << src.rdbuf();
    }
}

void Game::loadTextures()
{
    textureTitle = driver->getTexture(".\\IMG\\BANNERS\\title.png");
    textureNotAClicker = driver->getTexture(".\\IMG\\BANNERS\\notaclicker.png");
    texBackground = driver->getTexture(".\\IMG\\BACKGROUNDS\\background.jpg");
    texBackgroundInv = driver->getTexture(".\\IMG\\BACKGROUNDS\\backgroundReversed.jpg");
    textureHeroWalk1 = driver->getTexture(".\\IMG\\HERO\\WALK\\walk1.png");
    textureHeroWalk2 = driver->getTexture(".\\IMG\\HERO\\WALK\\walk2.png");
    textureHeroWalk3 = driver->getTexture(".\\IMG\\HERO\\WALK\\walk3.png");
    textureHeroWalk4 = driver->getTexture(".\\IMG\\HERO\\WALK\\walk4.png");
    textureHeroFight = driver->getTexture(".\\IMG\\HERO\\FIGHT\\fight.png");
    textureHeroRegen1 = driver->getTexture(".\\IMG\\HERO\\REGEN\\regen1.png");
    textureHeroRegen2 = driver->getTexture(".\\IMG\\HERO\\REGEN\\regen2.png");
    textureHeroRegen3 = driver->getTexture(".\\IMG\\HERO\\REGEN\\regen3.png");
    textureBtnNewGAme = driver->getTexture(".\\IMG\\BUTTONS\\btnNewGame.png");
    textureBtnLoadGame = driver->getTexture(".\\IMG\\BUTTONS\\btnLoadGame.png");
    textureBtnOthers = driver->getTexture(".\\IMG\\BUTTONS\\btnInGame.png");

    gui->setimgBackGroundImage(texBackground);
    gui->setimgBackGroundInvImage(texBackgroundInv);
    gui->setimgTitleImage(textureTitle);
    gui->setimgNotAClickerImage(textureNotAClicker);
    gui->setbtnNewGameImage(textureBtnNewGAme);
    gui->setbtnLoadGameImage(textureBtnLoadGame);
    gui->setDefaultBtnImage(textureBtnOthers);
}


//get
int Game::getWorldNumber()
{
    return this->worldNumber;
}

//set
void Game::setWorldNumber(int number)
{
    this->worldNumber = number;
}




