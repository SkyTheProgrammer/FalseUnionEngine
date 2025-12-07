//
// Created by SkyTFB on 10/7/2025.
//

#include "fupch.h"
#include "../../Headers/Core/Logger.h"

namespace FalseUnion
{
    Logger* Logger::instance = nullptr; // sets logger's instance to a nullptr by default.
#pragma region Constructor/destructor
    /// <summary>
    /// Default constructor of logger, sets console to the current consoles handle, logs it, and updates time.
    /// </summary>
    Logger::Logger()
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        std::cout << "Console Handle: " << hConsole << "\n";
        updateTime();
    }

    /// <summary>
    /// Default destructor for logger cause inheritance.
    /// </summary>
    Logger::~Logger() = default;
#pragma endregion
#pragma region Singleton Methods
    /// <summary>
    /// Uses CreateLogger() function from client 
    /// </summary>
    /// @param clientLogger Logger*, provided by the client and assigned one time.
    void Logger::initializeLogger(Logger* clientLogger)
    {
        if (instance == nullptr)
        {
            instance = clientLogger;
        }
        else
        {
            FU_ENGINE_WARN("Logger already exists");
        }
    }

    /// <summary>
    /// Returns the global logger instance
    /// </summary>
    /// @returns Logger* the global logger instance. If one hasn't been set will return null as logger needs to be made by client after engine startup.
    Logger* Logger::getLoggerInstance()
    {
        return instance;
    }
#pragma endregion
#pragma region Update Methods
    /// <summary>
    /// updates time every time it is called and prints it to console.
    /// </summary>
    void Logger::updateTime()
    {
        currentTime = time(nullptr);
        if (currentTime == static_cast<time_t>(-1))
        {
            std::cout << "[FalseUnion] Error: Error Converting Time.";
            return;
        }
        errno_t err = localtime_s(&localTime, &currentTime);
        if (err != 0)
        {
            std::cout << "[FalseUnion] Error: Error Converting LocalTime.";
            return;
        }
        std::cout << std::to_string(localTime.tm_hour) + ":" + std::to_string(localTime.tm_min) + ":" +
            std::to_string(localTime.tm_sec) << " ";
    }
#pragma endregion
#pragma region Different LogMethods
    /// <summary>
    /// Logs a message to console based off of its 3 parameters
    /// </summary>
    /// @param errorLevel int, represents the error level for the switch statement to handle.
    /// @param isToClient bool, tells whether the log is to client.
    /// @param information string, what the log should say.
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

    /// <summary>
    /// Logs a message to client console based off of its 2 parameters
    /// </summary>
    /// @param errorLevel int, represents the error level for the switch statement to handle.
    /// @param information string, what the log should say.
    void Logger::logToClient(const int& errorLevel, const std::string& information)
    {
        updateTime();
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << "[App] ";
        errorLevelSwitch(errorLevel, information);
    }

    /// <summary>
    /// Logs a message to Engine based off of its 2 parameters
    /// </summary>
    /// @param errorLevel int, represents the error level for the switch statement to handle.
    /// @param information string, what the log should say.
    void Logger::logToEngine(const int& errorLevel, const std::string& information)
    {
        updateTime();
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        std::cout << "[FalseUnion] ";
        errorLevelSwitch(errorLevel, information);
    }

    /// <summary>
    /// Logs an info message to console based off of its 2 parameters
    /// </summary>
    /// @param isToClient bool, tells whether the log is to client.
    /// @param information string, what the log should say.
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

    /// <summary>
    /// Logs a warn message to console based off of its 2 parameters
    /// </summary>
    /// @param isToClient bool, tells whether the log is to client.
    /// @param information string, what the log should say.
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

    /// <summary>
    /// Logs an error message to console based off of its 2 parameters
    /// </summary>
    /// @param isToClient bool, tells whether the log is to client.
    /// @param information string, what the log should say.
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

    /// <summary>
    /// Logs an info message to client console based off of its parameter
    /// </summary>
    /// @param information string, what the log should say.
    void Logger::logInfoToClient(const std::string& information)
    {
        logToClient(0, information);
    }

    /// <summary>
    /// Logs a warn message to client console based off of its parameter
    /// </summary>
    /// @param information string, what the log should say.
    void Logger::logWarnToClient(const std::string& information)
    {
        logToClient(1, information);
    }

    /// <summary>
    /// Logs an error message to client console based off of its parameter
    /// </summary>
    /// @param information string, what the log should say.
    void Logger::logErrorToClient(const std::string& information)
    {
        logToClient(2, information);
    }

    /// <summary>
    /// Logs an info message to engine console based off of its parameter
    /// </summary>
    /// @param information string, what the log should say.
    void Logger::logInfoToEngine(const std::string& information)
    {
        logToEngine(0, information);
    }

    /// <summary>
    /// Logs a warn message to engine console based off of its parameter
    /// </summary>
    /// @param information string, what the log should say.
    void Logger::logWarnToEngine(const std::string& information)
    {
        logToEngine(1, information);
    }

    /// <summary>
    /// Logs an error message to engine console based off of its parameter
    /// </summary>
    /// @param information string, what the log should say.
    void Logger::logErrorToEngine(const std::string& information)
    {
        logToEngine(2, information);
    }
#pragma endregion
#pragma region Helper Methods
    /// <summary>
    /// Switch case method broken out from the rest of code as to adhere more closely to dry
    /// Outputs different things to console based on error level and information.
    /// </summary>
    /// @param errorLevel int, int representing error level. 0 for info, 1 for warn, 2 for error
    /// @param information string, logs information.
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
#pragma endregion
}
