#include "monster.h"

Monster::Monster(float incValue)
{
    //ctor
    this->setSTR(5*incValue);
    this->setDEF(2*incValue);
    this->incMaxHP(incValue);


}

Monster::~Monster()
{
    //dtor
}
