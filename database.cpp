#include "database.h"

database::database(Hero *LegacyBoy, statistics *P3Stats)
{
    fullPath = "./LegacyGame.db";
    LegacyBoyDB = LegacyBoy;
    P3StatsDB = P3Stats;

    if (openDatabase())
    {
        std::cout << "* DB : OPENED*" << std::endl;
    }
}

database::~database()
{
    //dtor
    if (closeDatabase())
    {
        std::cout << "* DB : CLOSED*" << std::endl;
    }
}

bool database::openDatabase()
{
    sqlite3_initialize();
    return sqlite3_open(getDbPathCStr().c_str(), &db) == SQLITE_OK;
}

irr::core::stringc database::getDbPathCStr()
{
    return fullPath.c_str();
}

bool database::closeDatabase()
{
    bool result = 0;
    if (sqlite3_close_v2(db) == SQLITE_OK) {
        result=1;
    }
    sqlite3_shutdown();
    return result;
}

bool database::executeQuery(irr::core::stringw query)
{
    char *errorMessage = 0;
    irr::core::stringc sql = query.c_str();

    bool result=0;
    if (sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage) == SQLITE_OK) {
        result=1;
    }
    return result;
}

bool database::createTable()
{
	irr::core::stringc sql = "CREATE TABLE IF NOT EXISTS T_GAME (idGame INTEGER PRIMARY KEY AUTOINCREMENT, heroName TEXT, strHero REAL, defHero REAL, sprHero REAL, spdHero REAL, maxHP REAL, legacyNum INTEGER, actualWorldLevel INTEGER, monsterKilled INTEGER, HighestWorld INTEGER, dmgDone REAL, dmgTaken REAL, PlayingTime REAL);";
    return executeQuery(sql);
}

bool database::initTable()
{
    int result;
    irr::core::stringc sql = "SELECT COUNT(idGame) FROM T_GAME";
    sqlite3_stmt *stmt;
    if (!prepareQuery(sql, &stmt))
    {
        std::cout << "ERROR PREPARE QUERY : " <<  sql.c_str() << std::endl;
        return false;
    }

    int returnValue = 0;
    do
    {
        result = sqlite3_step(stmt);
        if (result == SQLITE_ROW){
            returnValue = sqlite3_column_int(stmt,0);
        }
    }
    while (result == SQLITE_ROW);

    if (returnValue>0)
    {
        std::cout << "DATABASE IS EMPTY" << std::endl;
        return true;
    }
    else
    {
        sql = "INSERT INTO T_GAME (heroName, strHero, defHero, sprHero, spdHero, maxHP, legacyNum, actualWorldLevel, monsterKilled, HighestWorld, dmgDone, dmgTaken, PlayingTime) VALUES ('',0,0,0,0,0,0,0,0,0,0,0,0);";
        return executeQuery(sql);
    }
}

bool database::prepareQuery(irr::core::stringc query, sqlite3_stmt** stmt)
{
    return sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str())+1, stmt, NULL) == SQLITE_OK;
}

bool database::updateTable(int actualWorldLevel)
{
    irr::core::stringc sql = "UPDATE T_GAME SET heroName = '";
    sql += LegacyBoyDB->getName().c_str();
    sql += "', strHero = ";
    sql += LegacyBoyDB->getSTR();
    sql += ", defHero = ";
    sql += LegacyBoyDB->getDEF();
    sql += ", sprHero = ";
    sql += LegacyBoyDB->getSPR();
    sql += ", spdHero = ";
    sql += LegacyBoyDB->getSpd();
    sql += ", maxHP = ";
    sql += LegacyBoyDB->getMaxHP();
    sql += ", legacyNum =  ";
    sql += LegacyBoyDB->getLegacyNumber();
    sql += ", actualWorldLevel = ";
    sql +=  actualWorldLevel;
    sql += ", monsterKilled = ";
    sql += P3StatsDB->getMonsterKilled();
    sql += ", HighestWorld = ";
    sql += P3StatsDB->getHighestWorld();
    sql += ", dmgDone = ";
    sql += P3StatsDB->getDmgDone();
    sql += ", dmgTaken = ";
    sql += P3StatsDB->getDmgTaken();
    sql += ", PlayingTime = ";
    sql += P3StatsDB->getTimePlayed();
    sql += " WHERE idGame = 1;";
    return executeQuery(sql);
}

int database::loadGame()
{
    //Check if there are rows in the table
    int result=0;
    irr::core::stringc sql = "SELECT COUNT(idGame) FROM T_GAME";
    // Prepare the sql
    sqlite3_stmt *stmt;
    if (!prepareQuery(sql, &stmt))
    {
        std::cout << "ERROR PREPARE QUERY : " <<  sql.c_str() << std::endl;
        return false;
    }
    //now to count
    int returnValue = 0;
    do
    {
        result = sqlite3_step(stmt);
        if (result == SQLITE_ROW){
            returnValue = sqlite3_column_int(stmt,0);
        }
    }
    while (result == SQLITE_ROW);

    closeDatabase();
    openDatabase();
    //var for the return
    int actualWorldLevel=0;
    if (returnValue>0)
    {
        sql = "SELECT idGame, heroName, strHero, defHero, sprHero, spdHero, maxHP, legacyNum, actualWorldLevel, monsterKilled, HighestWorld, dmgDone, dmgTaken, PlayingTime FROM T_GAME where idGame =1;";
        if (!prepareQuery(sql, &stmt))
        {
            std::cout << "ERROR PREPARE QUERY : " <<  sql.c_str() << std::endl;
            return false;
        }
        else
        {
            do
            {
                //Reader for the SQL : Add values to HERO/STATS and return the actualWorldNumber
                result = sqlite3_step(stmt);
                //if result = 100 (code for SQLITE_ROW)
                if (result == SQLITE_ROW){
                    //Loading data to the hero and stats
                    irr::core::stringc heroName;
                    heroName = sqlite3_column_text(stmt, 1);
                    LegacyBoyDB->setName(heroName.c_str());//heroName
                    LegacyBoyDB->setSTR((float) sqlite3_column_double(stmt,2));//strHero
                    LegacyBoyDB->setDEF((float) sqlite3_column_double(stmt,3));//defHero
                    LegacyBoyDB->setSPR((float) sqlite3_column_double(stmt,4));// sprHero
                    LegacyBoyDB->setSPD((float) sqlite3_column_double(stmt,5));//spdHero
                    LegacyBoyDB->setMaxHP((float) sqlite3_column_double(stmt,6));//maxHP
                    LegacyBoyDB->setLegacyNumber(sqlite3_column_int(stmt,7));//legacyNum
                    actualWorldLevel = sqlite3_column_int(stmt,8);//actualWorldLevel
                    P3StatsDB->setMonsterKilled(sqlite3_column_int(stmt,9));//monsterKilled
                    P3StatsDB->setHighestWorld(sqlite3_column_int(stmt,10));//HighestWorld
                    P3StatsDB->setDmgDone((float) sqlite3_column_double(stmt,11));//dmgDone
                    P3StatsDB->setDmgTaken((float) sqlite3_column_double(stmt,12));//dmgTaken
                    P3StatsDB->setTimePlayed(sqlite3_column_double(stmt,13));//PlayingTime
                }
            }
            while (result == SQLITE_ROW);
        }
        //returning the actualworldlevel : where the game will have to start
        return actualWorldLevel;
    }
    else
    {
        return 0;
    }
}


