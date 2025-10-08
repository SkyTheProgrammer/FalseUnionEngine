//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Logger.h"

#include <iostream>


Logger::Logger() {
    info = "deafult info";
    warning = "deafult warning";
    error = "deafult error";
}

std::string Logger::log() const {
    return info + " " + warning + " " + error;
}
