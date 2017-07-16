///
///     \file   MyEventReceiver.h
///     \brief  class for the Event Receiver
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef MYEVENTRECEIVER_H
#define MYEVENTRECEIVER_H

#include <irrlicht.h>
#include "enums.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Game;

class MyEventReceiver : public IEventReceiver
{
    public:
        ///
        ///     \fn         MyEventReceiver(Game *P3Game)
        ///     \brief      constructor of the envent receiver object
        ///     \param      the game as game
        ///
        MyEventReceiver(Game *P3Game);
        ///
        ///     \fn         ~MyEventReceiver()
        ///     \brief      destructor of the envent receiver object
        ///
        virtual ~MyEventReceiver();

        virtual bool OnEvent(const SEvent& event);
    protected:

    private:
        Game *P3Game;
};

#endif // MYEVENTRECEIVER_H
