///
///     \file   monster.h
///     \brief  class for the monsters; entity inheritance
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include "entity.h"

class Monster:public Entity
{
    public:
        ///
        ///     \fn         Monster(float incValue)
        ///     \brief      constructor of the monster object
        ///     \param      increase value to define monster's stats as float
        ///
        Monster(float incValue);
        ///
        ///     \fn         ~Monster()
        ///     \brief      constructor of the monster object
        ///
        virtual ~Monster();

    protected:

    private:


};

#endif // MONSTER_H
