#include "debug_log.h"

#include <map>
#include <string>
#include <fstream>
#include <iostream>

#include <ctime>
#include <cassert>
#include <iomanip>

#include <SFML/System.hpp>

namespace Log
{
    namespace
    {
        std::map<Log_Type, bool> isLogTurnedOnMap;
        bool isLogging = true;

        std::ofstream outLog;

        sf::Clock deltaClock;
        sf::Clock elapsedClock;
        sf::Clock frameTimer;


        std::string getTimeFormal ()
        {
            time_t t = time(0);
            tm* now = localtime( &t );

            auto h = now->tm_hour;
            auto m = now->tm_min;
            auto s = now->tm_sec;

            auto year   = now->tm_year + 1900;
            auto month  = now->tm_mon + 1;
            auto day    = now->tm_mday;

            std::string timeString = std::to_string( h )   + ":" + std::to_string( m )     + ":" + std::to_string( s );
            std::string dateString = std::to_string( day ) + "/" + std::to_string( month ) + "/" + std::to_string( year );

            return timeString + " on " + dateString;
        }

        std::string getTimeFileName ()
        {
            time_t t = time(0);
            tm* now = localtime( &t );

            auto year   = now->tm_year + 1900;
            auto month  = now->tm_mon + 1;
            auto day    = now->tm_mday;

            std::string date = std::to_string( day ) + "-" + std::to_string( month ) + "-" + std::to_string( year );

            auto h = now->tm_hour;
            auto m = now->tm_min;
            auto s = now->tm_sec;

            std::string timeString = std::to_string( h ) + "-" + std::to_string( m ) + "-" + std::to_string( s );

            return date + " " + timeString;
        }

        std::string getTimeSinceLastLog()
        {
            float time = deltaClock.restart().asSeconds();
            return std::to_string ( time );
        }

        std::string getElapsedTime()
        {
            float time = elapsedClock.getElapsedTime().asSeconds();
            return std::to_string ( time );
        }

        void openLogIfNeeded ()
        {
            if ( !outLog.is_open() ) {
                outLog.open ( "Logs/Log " + getTimeFileName() + ".txt" );

                outLog << "Log created at " << getTimeFormal() << "." << std::endl;
                outLog << std::endl;

                outLog << "  Time of log     | Time since last Log (s) | Message " << std::endl;
                outLog << "  (s since start) |  (s)                    |         " << std::endl;

                for ( size_t i = 0 ; i < static_cast<int>(Log_Type::NUM_LOG_TPES) ; i++ )
                {
                    isLogTurnedOnMap.insert( std::make_pair( static_cast<Log_Type>(i), true ) );
                }
                assert ( isLogTurnedOnMap.size() == static_cast<int>( Log_Type::NUM_LOG_TPES ) );
            }
        }

        bool typeIsTurnedOn ( Log_Type type )
        {
            return isLogTurnedOnMap.at( type );
        }
    }

    void logMessage ( const std::string& message, Log_Type type )
    {
        openLogIfNeeded();

        if ( !isLogging ) return;
        if ( !typeIsTurnedOn( type ) ) return;

        outLog << "  "      << getElapsedTime() << "\t  |\t" << getTimeSinceLastLog() << "\t    |\t";
        outLog << message   << std::endl;
    }

    void makeGap()
    {
        openLogIfNeeded();

        if ( !isLogging ) return;
        if ( !isLogTurnedOnMap.at( Log_Type::Gaps ) ) return;

        outLog << std::endl;
    }

    void turnOnLogType  ( Log_Type type )
    {
        openLogIfNeeded();

        isLogTurnedOnMap.at( type ) = true;
    }

    void turnOffLogType ( Log_Type type )
    {
        openLogIfNeeded();

        isLogTurnedOnMap.at( type ) = false;
    }
}
