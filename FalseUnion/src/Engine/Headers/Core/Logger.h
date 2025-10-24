//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include <string>
#include <ctime>
#include <windows.h>
#include "Core.h"

namespace FalseUnion {
    //please remember to move to a singleton when you get a chance.
    class FALSEUNION_API Logger
    {
    public:
        Logger(); // default constructor for logger
        virtual ~Logger(); // virtual destructor for logger
        enum errorLevel // enum for loggers error levels
        {
            info = 0,
            warning = 1,
            error = 2
        };
        void log(const int &errorLevel, const bool &isToClient, const std::string &information); // logs a message when given the params, output is different depenant on them
        void logToClient(const int &errorLevel, const std::string& information); // logs a message to client given params, output is different dependent on them
        void logToEngine(const int &errorLevel, const std::string &information); // logs a message to client given params, output is different dependent on them
        void logInfo(const bool &isToClient, const std::string &information); // logs info, output is different dependant on params
        void logWarn(const bool &isToClient, const std::string &information); // logs warn, output is different dependent on params
        void logError(const bool &isToClient, const std::string &information); // logs error, output is different dependant on params
        void logInfoToClient(const std::string &information); // logs info to client, takes in a param for the logs text.
        void logWarnToClient(const std::string &information); // logs warn to client, takes in a param for the logs text.
        void logErrorToClient(const std::string &information); // logs error to client, takes in a param for the logs text.
        void logInfoToEngine(const std::string &information); // logs info to engine, takes in a param for the logs text.
        void logWarnToEngine(const std::string &information); // logs warn to engine, takes in a param for the logs text.
        void logErrorToEngine(const std::string &information); // logs error to engine, takes in a param for the logs text.
        static Logger* getLoggerInstance(); // gets the global logger instance.
        static void setLoggerInstance(Logger* inLogger); // sets the global logger instance to the logger in param.
        
        
            
    private:
        void errorLevelSwitch(const int &errorLevel, const std::string &information) const; // switch statement broken into method to reduce code, takes in error level and information
        void updateTime(); // updates the time
        time_t currentTime;
        tm localTime;
        HANDLE hConsole; // the handle of the console to be output to
        static Logger* instance; // the global instance of the logger.
        
    };
    Logger* CreateLogger(); // definition of create logger to be used in client.
}

//defines an easier way to call functions to log
#define FU_ENGINE_INFO(...) ::FalseUnion::Logger::getLoggerInstance()->logInfoToEngine(__VA_ARGS__) 
#define FU_ENGINE_WARN(...) :: FalseUnion::Logger::getLoggerInstance()->logWarnToEngine(__VA_ARGS__)
#define FU_ENGINE_ERROR(...) :: FalseUnion::Logger::getLoggerInstance()->logErrorToEngine(__VA_ARGS__)

#define FU_CLIENT_INFO(...) ::FalseUnion::Logger::getLoggerInstance()->logInfoToClient(__VA_ARGS__)
#define FU_CLIENT_WARN(...) ::FalseUnion::Logger::getLoggerInstance()->logWarnToClient(__VA_ARGS__)
#define FU_CLIENT_ERROR(...) ::FalseUnion::Logger::getLoggerInstance()->logErrorToClient(__VA_ARGS__)
//