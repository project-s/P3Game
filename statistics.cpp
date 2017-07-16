#include "statistics.h"

statistics::statistics()
{
    //ctor
    monsteKilled = 0;
    highestWorld = 1;
    dmgDone = 0;
    dmgTaken = 0;
    legacyNumber = 0;
    timePlayed = 0;
}

statistics::~statistics()
{
    //dtor
}


//get
int statistics::getMonsterKilled()
{
    return monsteKilled;
}

int statistics::getHighestWorld()
{
    return highestWorld;
}

float statistics::getDmgDone()
{
    return dmgDone;
}

float statistics::getDmgTaken()
{
    return dmgTaken;
}

int statistics::getLegacyNumber()
{
    return legacyNumber;
}

double statistics::getTimePlayed()
{
    return timePlayed;
}

//set
void statistics::setMonsterKilled(int monsterKilled)
{
    this->monsteKilled = monsterKilled;
}

void statistics::setHighestWorld(int highestWorld)
{
    this->highestWorld = highestWorld;
}

void statistics::setDmgDone(float DmgDone)
{
    this->dmgDone = DmgDone;
}

void statistics::setDmgTaken(float DmgTaken)
{
    this->dmgTaken = DmgTaken;
}

void statistics::setTimePlayed(double timePlayed)
{
    this->timePlayed = timePlayed;
}

//M/F
void statistics::increaseMonsteKilled()
{
    monsteKilled++;
}

void statistics::incTimePlayed(double duration)
 {
    timePlayed+=duration;
 }

void statistics::increaseHighestWorld(int worldNumber)
{
    if (worldNumber > highestWorld)
    {
        highestWorld = worldNumber;
    }
}

void statistics::increaseDmgDone(float dmg)
{
    dmgDone+=dmg;
}

void statistics::increaseDmgTaken(float dmg)
{
    dmgTaken+=dmg;
}

void statistics::increaseLegacyNumber()
{
    legacyNumber++;
}








