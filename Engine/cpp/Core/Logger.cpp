//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Logger.h"

#include <iostream>


Logger::Logger() {
    //sets loggers variables to default values
    info = "default info";
    warning = "default warning";
    error = "default error";
}

Logger::Logger(const std::string &newInfo, const std::string &newWarning, const std::string &newError) {
    info = newInfo;
    warning = newWarning;
    error = newError;
}

Logger::Logger(const std::string &newInfo, const std::string &newWarning) {
    info = newInfo;
    warning = newWarning;
    error = "default error";
}

Logger::Logger(const std::string &newInfo) {
    info = newInfo;
    warning = "default warning";
    error = "default error";
}


std::string Logger::log() const {
    if (error == "default error") {
        return "info: " + info + " warning: " + warning;
    }
    if (error == "default warning") {
        return "info: " + info;
    }
    return "info: " + info +  + " error: " + error;
}

std::string Logger::getInfo() const {
    return info;
}

std::string Logger::getWarning() const {
    return warning;
}

std::string Logger::getError() const {
    return error;
}

void Logger::setInfo(const std::string &newInfo) {
    info = newInfo;
}

void Logger::setWarning(const std::string &newWarning) {
    warning = newWarning;
}

void Logger::setError(const std::string &newError) {
    error = newError;
}
