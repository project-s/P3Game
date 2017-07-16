///
///     \file   database.h
///     \brief  data access layer class; to interact with the database
///     \author TSDI01 : Sébastien COLLIGNON
///     \date   april 2017
///

#ifndef DATABASE_H
#define DATABASE_H

#include <irrlicht.h>
#include <iostream>

#include "hero.h"
#include "entity.h"
#include "statistics.h"
#include "sqlite3.h"

class database
{
    public:
        ///
        ///     \fn         database(Hero *LegacyBoy, statistics *P3Stats)
        ///     \brief      constructor of the object database.
        ///     \param      LegacyBoy: Hero object of the game
        ///     \param      P3Stats: statistics object of the game.
        ///
        database(Hero *LegacyBoy, statistics *P3Stats);
        ///
        ///     \fn         ~database()
        ///     \brief      destructor of the object database.
        ///
        virtual ~database();

        ///
        ///     \fn         bool openDatabase()
        ///     \brief      fn to open the database.
        ///     \return     true : if success.
        ///
        bool openDatabase();
        ///
        ///     \fn         bool closeDatabase()
        ///     \brief      fn to close the database.
        ///     \return     true : if success.
        ///
        bool closeDatabase();
        ///
        ///     \fn         irr::core::stringc getDbPathCStr()
        ///     \brief      cast the fullPath irr::core::stringw into irr::core::stringc.
        ///     \return     the fullPath as irr::core::stringc.
        ///
        irr::core::stringc getDbPathCStr();
        ///
        ///     \fn         bool executeQuery(irr::core::stringw query)
        ///     \brief      execute a query.
        ///     \param      query as an irr::core::stringw.
        ///     \return     true : if success.
        ///
        bool executeQuery(irr::core::stringw query);
        ///
        ///     \fn         bool createTable()
        ///     \brief      Create the table T_GAME if it doesnt exist.
        ///     \return     true : if success.
        ///
        bool createTable();
        ///
        ///     \fn         bool prepareQuery(irr::core::stringc query, sqlite3_stmt** stmt);
        ///     \brief      prepare the query.
        ///     \param      query as an irr::core::stringw.
        ///                 reader stmt.
        ///     \return     true : if success.
        ///
        bool prepareQuery(irr::core::stringc query, sqlite3_stmt** stmt);
        ///
        ///     \fn         bool initTable();
        ///     \brief      initialize the T_GAME table.
        ///                 Check if there are rows in the table.
        ///                 Prepare the sql.
        ///                 Check and create an empty row if there is no row.
        ///     \return     true : if success.
        ///
        bool initTable();
        ///
        ///     \fn         bool updateTable(int actualWorldLevel);
        ///     \brief      Update T-GAME with hero object, statistics object and actual world level.
        ///     \param      number of the actual world level the hero is fighting as int.
        ///     \return		true : if success.
        ///
        bool updateTable(int actualWorldLevel);
        ///
        ///     \fn         int loadGame();
        ///     \brief      load the game, read the database and put the data on Hero and Statisctics object.
        ///     \return     the world level to fight as int.
        ///
        int loadGame();

    protected:

    private:
        sqlite3 *db;
        irr::core::stringw fullPath;
        Hero *LegacyBoyDB;
        statistics *P3StatsDB;
};

#endif // DATABASE_H
