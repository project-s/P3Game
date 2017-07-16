///
///     \file   hero.h
///     \brief  class for the hero; entity inheritance
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef HERO_H
#define HERO_H
#include "entity.h"
#include "enums.h"

#include <string>

class Hero:public Entity
{
    public:
        ///
        ///     \fn         Hero()
        ///     \brief      constructor of the hero object
        ///
        Hero();
        ///
        ///     \fn         ~Hero()
        ///     \brief      destructor of the hero object
        ///
        virtual ~Hero();

        //M/F
        ///
        ///     \fn         regenHP(float amountRegen)
        ///     \brief      increasing hero's HP as he regens based on the amountRegen value
        ///     \param      the amount of HP regen as float
        ///
        void regenHP(float amountRegen);
        ///
        ///     \fn         void incSPR(float incSpr)
        ///     \brief      fn to increase the SPR of the hero
        ///     \param      amount of SPR to increase as a float
        ///
        void incSPR(float incSpr);
        ///
        ///     \fn         void incSPD(float incSpd)
        ///     \brief      fn to increase the SPD of the hero
        ///     \param      amount of SPD to increase as a float
        ///
        void incSPD(float incSpd);
        ///
        ///     \fn         void incSTR(float incStr)
        ///     \brief      fn to increase the STR of the hero
        ///     \param      amount of STR to increase as a float
        ///
        void incSTR(float incStr);
        ///
        ///     \fn         void incDEF(float incDef)
        ///     \brief      fn to increase the DEF of the hero
        ///     \param      amount of DEF to increase as a float
        ///
        void incDEF(float incDef);
        ///
        ///     \fn         void incLegacyNumber()
        ///     \brief      fn to increase the legacy number of the hero
        ///
        void incLegacyNumber();

        //set
        ///
        ///     \fn         setHeroStatus(int status)
        ///     \brief      to set hero's status
        ///     \param      status to set as float
        ///
        void setHeroStatus(int status);
        ///
        ///     \fn         setLegacyNumber(int number)
        ///     \brief      to set hero's legacy number
        ///     \param      number to set as int
        ///
        void setLegacyNumber(int number);
        ///
        ///     \fn         setName(std::string legacyBoyname)
        ///     \brief      to set hero's name
        ///     \param      legacyBoyname to set as std::string
        ///
        void setName(std::string legacyBoyname);
        ///
        ///     \fn         setSPD(int speed)
        ///     \brief      to set hero's spd
        ///     \param      speed to set as int
        ///
        void setSPD(int speed);
                ///
        ///     \fn         setSPR(int spr)
        ///     \brief      to set hero's spirit
        ///     \param      spr to set as int
        ///
        void setSPR(int spr);


        //get
        ///
        ///     \fn         float getSpd()
        ///     \brief      to get hero's speed
        ///     \return     spd to get as float
        ///
        float getSpd();
        ///
        ///     \fn         float getSPR()
        ///     \brief      to get entity's spirit
        ///     \return     spr to get as float
        ///
        float getSPR();
        ///
        ///     \fn         int getHeroStatus()
        ///     \brief      to get entity's status
        ///     \return     status to get as int
        ///
        int getHeroStatus();
        ///
        ///     \fn         int getLegacyNumber()
        ///     \brief      to get entity's Legacy Number
        ///     \return     legacy number to get as int
        ///
        int getLegacyNumber();
        ///
        ///     \fn         std::string getName()
        ///     \brief      to get entity's name
        ///     \return     name to get as std::string
        ///
        std::string getName();

    protected:

    private:
        float SPR; //spirit stat : regen speed
        float SPD; //speed stat : walking speed
        int HeroStatus;  //status of hero's action : in order: walk / fight / regen;
        int LegacyNumber;
        std::string LegacyBoyName;
};

#endif // HERO_H
