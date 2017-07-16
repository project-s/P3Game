#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    //ctor
    HP = 500;
    maxHP = 500;
}

Entity::~Entity()
{
    //dtor
}

//M/F
float Entity::fight(Entity *enemy)
{
    float tempDMG=0;
    //enemy loses HP if he doesnt have enough DEF
    if (this->STR > enemy->getDEF())
    {
        //tempDMG = this->STR - enemy->getDEF();
        tempDMG = (this->STR - enemy->getDEF()) * 0.1 ;

        enemy->setHP(enemy->getHP()- (tempDMG));
    }

    //making sure he'll never be under 0 HP
    if (enemy->getHP()<0)
    {
        tempDMG+=enemy->getHP();
        enemy->setHP(0);
    }
    return  tempDMG;
}

void Entity::incMaxHP(float incMaxHP)
{
    this->maxHP = this->maxHP+incMaxHP;
}

//SET
void Entity::setHP(float HP)
{
    this->HP = HP;
}

void Entity::setSTR(float STR)
{
    this->STR = STR;
}

void Entity::setDEF(float DEF)
 {
     this->DEF = DEF;
 }

 void Entity::setMaxHP(float MaxHP)
 {
     this->maxHP = MaxHP;
 }

//GET
float Entity::getHP()
{
    return this->HP;
}

float Entity::getMaxHP()
{
    return this->maxHP;
}

float Entity::getDEF()
{
    return this->DEF;
}

float Entity::getSTR()
{
    return this->STR;
}
