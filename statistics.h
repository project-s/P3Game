///
///     \file   statistics.h
///     \brief  class for the game statistics
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef STATISTICS_H
#define STATISTICS_H


class statistics
{
    public:
        ///
        ///     \fn         statistics()
        ///     \brief      constructor of the statistics object
        ///
        statistics();
        ///
        ///     \fn         ~statistics()
        ///     \brief      destructor of the statistics object
        ///
        virtual ~statistics();

        //get
        ///
        ///     \fn         int getMonsterKilled()
        ///     \brief      to get statistics' monsters killed
        ///     \return     monsters killed to get as int
        ///
        int getMonsterKilled();
        ///
        ///     \fn         int getHighestWorld()
        ///     \brief      to get statistics' highest world
        ///     \return     highest world to get as int
        ///
        int getHighestWorld();
        ///
        ///     \fn         float getDmgDone()
        ///     \brief      to get statistics' damages done
        ///     \return     damages done to get as float
        ///
        float getDmgDone();
        ///
        ///     \fn         float getDmgTaken()
        ///     \brief      to get statistics' damages taken
        ///     \return     damages taken to get as float
        ///
        float getDmgTaken();
        ///
        ///     \fn         int getLegacyNumber()
        ///     \brief      to get statistics' Legacy number
        ///     \return     Legacy number to get as int
        ///
        int getLegacyNumber();
        ///
        ///     \fn         double getTimePlayed()
        ///     \brief      to get statistics' Time played
        ///     \return     Time played to get as double
        ///
        double getTimePlayed();

        //set
        ///
        ///     \fn         void setMonsterKilled(int monsterKilled)
        ///     \brief      to set statistics' monsters killed
        ///     \param      monsters killed to set as int
        ///
        void setMonsterKilled(int monsterKilled);
        ///
        ///     \fn         void setHighestWorld(int highestWorld)
        ///     \brief      to set hstatistics' highest world
        ///     \param      highestWorld highest world to set as int
        ///
        void setHighestWorld(int highestWorld);
        ///
        ///     \fn         setDmgDone(float DmgDone)
        ///     \brief      to set statistics'damages done
        ///     \param      damages done to set as float
        ///
        void setDmgDone(float DmgDone);
        ///
        ///     \fn         setDmgTaken(float DmgTaken)
        ///     \brief      to set statistics' damages taken
        ///     \param      damages taken to set as float
        ///
        void setDmgTaken(float DmgTaken);
        ///
        ///     \fn         setTimePlayed(double timePlayed)
        ///     \brief      to set statistics'Time played
        ///     \param      Time played to set as double
        ///
        void setTimePlayed(double timePlayed);

        //M/F
        ///
        ///     \fn         increaseMonsteKilled()
        ///     \brief      increase statisticts monsters killed number
        ///
        void increaseMonsteKilled();
        ///
        ///     \fn         increaseHighestWorld(int worldNumber)
        ///     \brief      increase statisticts highest world depending on world number
        ///     \param      actual world number to compare with statistics highest world
        ///
        void increaseHighestWorld(int worldNumber);
        ///
        ///     \fn         increaseDmgDone(float dmg)
        ///     \brief      increase statisticts damages done number
        ///     \param      amount to increase as float
        ///
        void increaseDmgDone(float dmg);
        ///
        ///     \fn         increaseDmgTaken(float dmg)
        ///     \brief      increase statisticts damages taken number
        ///     \param      amount to increase as float
        ///
        void increaseDmgTaken(float dmg);
        ///
        ///     \fn         increaseLegacyNumber()
        ///     \brief      increase statisticts Legacy number
        ///
        void increaseLegacyNumber();
        ///
        ///     \fn         incTimePlayed(double duration)
        ///     \brief      increase statistics time played number
        ///     \param      amount to increase as double
        ///
        void incTimePlayed(double duration);

    protected:

    private:
        int monsteKilled;
        int highestWorld;
        float dmgDone;
        float dmgTaken;
        int legacyNumber;
        double timePlayed;

};

#endif // STATISTICS_H
