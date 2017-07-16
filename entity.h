///
///     \file   entity.h
///     \brief  entity class
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
    public:
        ///
        ///     \fn         Entity()
        ///     \brief      constructor of the entity object
        ///
        Entity();
        ///
        ///     \fn         ~Entity()
        ///     \brief      destructor of the entity object
        ///
        virtual ~Entity();

        //M/F
        ///
        ///     \fn         float fight(Entity *enemy)
        ///     \brief      fn to generate a round of a fight
        ///     \param      entity object the enemy
        ///     \return     dmg done to the entity as float
        ///
        float fight(Entity *enemy);
        ///
        ///     \fn         void incMaxHP(float incMaxHP)
        ///     \brief      fn to increase the maximum HP of the entity
        ///     \param      amount of HP to increase as a float
        ///
        void incMaxHP(float incMaxHP);

        //set
        ///
        ///     \fn         setHP(float HP);
        ///     \brief      to set entity's HP
        ///     \param      HP to set as float
        ///
        void setHP(float HP);
        ///
        ///     \fn         setSTR(float STR);
        ///     \brief      to set entity's STR
        ///     \param      STR to set as float
        ///
        void setSTR(float STR);
        ///
        ///     \fn         setDEF(float DEF);
        ///     \brief      to set entity's DEF
        ///     \param      DEF to set as float
        ///
        void setDEF(float DEF);
        ///
        ///     \fn         setMaxHP(float MaxHP);
        ///     \brief      to set entity's MaxHP
        ///     \param      MaxHP to set as float
        ///
        void setMaxHP(float MaxHP);

        //get
        ///
        ///     \fn         float getHP()
        ///     \brief      to get entity's HP
        ///     \return     HP to get as float
        ///
        float getHP();
        ///
        ///     \fn         float getMaxHP()
        ///     \brief      to get entity's maxHP
        ///     \return     maxHP to get as float
        ///
        float getMaxHP();
        ///
        ///     \fn         float getDEF()
        ///     \brief      to get entity's DEF
        ///     \return     DEF to get as float
        ///
        float getDEF();
        ///
        ///     \fn         float getSTR()
        ///     \brief      to get entity's STR
        ///     \return     STR to get as float
        ///
        float getSTR();

    protected:

    private:
        float STR; //strentgh stat : attack power
        float DEF; // defence stat : defence power
        float HP; //health point stat : actual entity HP
        float maxHP;//max health point stat : max entity HP
};

#endif // ENTITY_H
