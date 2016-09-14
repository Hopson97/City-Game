#ifndef DEBUG_LOG_H_INCLUDED
#define DEBUG_LOG_H_INCLUDED

#include <string>

enum class Log_Type
{
    Draw_Call,
    Resource_Load,
    Resource,
    FPS,
    State_Switch,
    Gaps,
    Update,
    Technical,
    General,
    NUM_LOG_TPES
};

namespace Log
{
    void beginFrame ();
    void endFrame   ();
    void logMessage ( const std::string& message, Log_Type type );
    void makeGap    ();

    void turnOnLogType  ( Log_Type type );
    void turnOffLogType ( Log_Type type );
}

#endif // DEBUG_LOG_H_INCLUDED
