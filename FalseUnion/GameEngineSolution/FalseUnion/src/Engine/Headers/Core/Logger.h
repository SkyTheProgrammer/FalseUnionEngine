//
// Created by SkyTFB on 10/6/2025.
//
#pragma once
#include <string>
#include <ctime>
#include <windows.h>
#include "../Core/Core.h"

namespace FalseUnion {
    class FALSEUNION_API Logger
    {
    public:
        enum errorLevel
        {
            info = 0,
            warning = 1,
            error = 2
        };
        
        void log(const int &errorLevel, const bool &isToClient, const std::string &information);
        void logToClient(const int &errorLevel, const std::string& information);
        void logToEngine(const int &errorLevel, const std::string &information);
        void logInfo(const bool &isToClient, const std::string &information);
        void logWarn(const bool &isToClient, const std::string &information);
        void logError(const bool &isToClient, const std::string &information);
        void logInfoToClient(const std::string &information);
        void logWarnToClient(const std::string &information);
        void logErrorToClient(const std::string &information);
        void logInfoToEngine(const std::string &information);
        void logWarnToEngine(const std::string &information);
        void logErrorToEngine(const std::string &information);
        static Logger* getLoggerInstance();
        static void setLoggerInstance(Logger* inLogger);
        Logger();
        virtual ~Logger();
        
            
    private:
        void errorLevelSwitch(const int &errorLevel, const std::string &information) const;
        void updateTime();
        time_t currentTime;
        tm localTime;
        HANDLE hConsole;
        static Logger* instance;
        
    };
    Logger* CreateLogger();
}

#define FU_ENGINE_INFO(...) ::FalseUnion::Logger::getLoggerInstance()->logInfoToEngine(__VA_ARGS__)
#define FU_ENGINE_WARN(...) :: FalseUnion::Logger::getLoggerInstance()->logWarnToEngine(__VA_ARGS__)
#define FU_ENGINE_ERROR(...) :: FalseUnion::Logger::getLoggerInstance()->logErrorToEngine(__VA_ARGS__)

#define FU_CLIENT_INFO(...) ::FalseUnion::Logger::getLoggerInstance()->logInfoToClient(__VA_ARGS__)
#define FU_CLIENT_WARN(...) ::FalseUnion::Logger::getLoggerInstance()->logWarnToClient(__VA_ARGS__)
#define FU_CLIENT_ERROR(...) ::FalseUnion::Logger::getLoggerInstance()->logErrorToClient(__VA_ARGS__)
