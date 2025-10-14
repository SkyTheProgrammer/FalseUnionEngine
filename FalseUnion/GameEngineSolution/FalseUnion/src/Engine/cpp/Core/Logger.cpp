//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Logger.h"

#include <iostream>


namespace FalseUnion
{
    Logger* Logger::instance = nullptr;

    Logger::Logger()
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        std::cout << "Console Handle: " << hConsole << "\n";
        updateTime();
    }

    Logger::~Logger()
    {
    }

    void Logger::updateTime()
    {
        errno_t err;
        currentTime = time(nullptr);
        if (currentTime == (time_t)(-1))
        {
            std::cout << "[FalseUnion] Error: Error Converting Time.";
            return;
        }
        err = localtime_s(&localTime, &currentTime);
        if (err != 0)
        {
            std::cout << "[FalseUnion] Error: Error Converting LocalTime.";
            return;
        }
        std::cout << std::to_string(localTime.tm_hour) + ":" + std::to_string(localTime.tm_min) + ":" +
            std::to_string(localTime.tm_sec) << " ";
    }

    void Logger::log(const int& errorLevel, const bool& isToClient, const std::string& information)
    {
        if (isToClient)
        {
            logToClient(errorLevel, information);
        }
        else
        {
            logToEngine(errorLevel, information);
        }
    }

    void Logger::logToClient(const int& errorLevel, const std::string& information)
    {
        updateTime();
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << "[App] ";
        errorLevelSwitch(errorLevel, information);
    }

    void Logger::logToEngine(const int& errorLevel, const std::string& information)
    {
        updateTime();
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        std::cout << "[FalseUnion] ";
        errorLevelSwitch(errorLevel, information);
    }

    void Logger::logInfo(const bool& isToClient, const std::string& information)
    {
        if (isToClient)
        {
            logToClient(0, information);
        }
        else
        {
            logToEngine(0, information);
        }
    }

    void Logger::logWarn(const bool& isToClient, const std::string& information)
    {
        if (isToClient)
        {
            logToClient(1, information);
        }
        else
        {
            logToEngine(1, information);
        }
    }

    void Logger::logError(const bool& isToClient, const std::string& information)
    {
        if (isToClient)
        {
            logToClient(2, information);
        }
        else
        {
            logToEngine(2, information);
        }
    }

    void Logger::logInfoToClient(const std::string& information)
    {
        logToClient(0, information);
    }

    void Logger::logWarnToClient(const std::string& information)
    {
        logToClient(1, information);
    }

    void Logger::logErrorToClient(const std::string& information)
    {
        logToClient(2, information);
    }

    void Logger::logInfoToEngine(const std::string& information)
    {
        logToEngine(0, information);
    }

    void Logger::logWarnToEngine(const std::string& information)
    {
        logToEngine(1, information);
    }

    void Logger::logErrorToEngine(const std::string& information)
    {
        logToEngine(2, information);
    }

    Logger* Logger::getLoggerInstance()
    {
        return instance;
    }

    void Logger::setLoggerInstance(Logger* inLogger)
    {
        instance = inLogger;
    }

    void Logger::errorLevelSwitch(const int& errorLevel, const std::string& information) const
    {
        switch (errorLevel)
        {
        case 1:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            std::cout << "Warn: ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << information << "\n";
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            std::cout << "Error: ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << information << "\n";
            break;
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
            std::cout << "Info: ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << information << "\n";
            break;
        }
    }
}
