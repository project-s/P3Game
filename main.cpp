///
///     \file   main.cpp
///     \brief  Project 3 : idle game
///     \author TSDI01 : S饕astien COLLIGNON
///     \date   april 2017
///
///     \mainpage
///     \section starting starting the game
///     When you first launch the game, you only have access to the "NEW GAME" button.
///     Click on the "NEW GAME" button to start the game.
///     The game is automatically saved after each fight your hero will do.
///
///     \section loading loading the game
///     The next time you値l launch the game, you値l have access to two buttons, "NEW GAME" will be there and "LOAD GAME" will appear.
///     Click on "LOAD GAME" to continue your previous game, you値l start right where you left before.
///     If you want to start the game over, you can click on "NEW GAME".
///     Clicking on "NEW GAME" if you already have a game saved will :
///     -	Archive your "old game" in a special folder.
///     -	Create a new file for your new game.
///     You値l never lose a saved game.
///     To find out how to recover an old saved game, please refer to the documentation "recovering an old saved game".
///
///     \section playing Playing the game
///     Once you start or load the game, sit and relax.
///     if your hero dies, you'll have to pick what legacy you want to give to your next hero
///     when it's done, sit and relax.
///     repeat.
///
///     \section legacy Selecting a legacy
///     when the game over window appears, just click on the stat you want to increase
///     the level you died on will affect the amount of legacy your next hero will receive

#include "Game.h"
#include <time.h>

int main()
{
    //Create game
	Game *P3Game = new Game();

	//Start game
    P3Game->run();

    //Delete game
    delete P3Game;

    return 0;
}

