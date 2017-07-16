#include "hero.h"

Hero::Hero()
{
    //ctor
    HeroStatus = HERO_STATUS_NOP;
    SPD = 100;
    SPR = 100;
    this->setSTR(10); //10
    this->setDEF(4); //4
    LegacyNumber = 0;
    LegacyBoyName = "LegacyBoy";
}

Hero::~Hero()
{
    //dtor
}

//M/F
void Hero::regenHP(float amountRegen)
{
    //if the regen amout is bigger then maxHP; HP = MaxHP
    if (this->getHP()+ amountRegen > this->getMaxHP())
    {
        this->setHP(this->getMaxHP());
    }
    else
    {
        this->setHP(this->getHP()+amountRegen);
    }
}

void Hero::incSPR(float incSpr)
{
    this->SPR = this->SPR+incSpr;
}

void Hero::incSPD(float incSpd)
{
    this->SPD = this->SPD+incSpd;
}

void Hero::incSTR(float incStr)
{
    this->setSTR(this->getSTR()+incStr);
}

void Hero::incDEF(float incDef)
{
    this->setDEF(this->getDEF()+incDef);
}

void Hero::incLegacyNumber()
{
    this->LegacyNumber++;
}

//SET
void Hero::setHeroStatus(int status)
{
    this->HeroStatus = status;
}

void Hero::setLegacyNumber(int number)
{
    this->LegacyNumber = number;
}

void Hero::setName(std::string legacyBoyname)
{
    this->LegacyBoyName = legacyBoyname;
}

void Hero::setSPD(int speed)
{
    this->SPD = speed;
}

void Hero::setSPR(int spr)
{
    this->SPR = spr;
}

//GET
float Hero::getSpd()
{
    return this->SPD;
}

float Hero::getSPR()
{
    return this->SPR;
}

int Hero::getHeroStatus()
{
    return HeroStatus;
}

int Hero::getLegacyNumber()
{
    return this->LegacyNumber;
}

std::string Hero::getName()
{
    return this->LegacyBoyName;
}
