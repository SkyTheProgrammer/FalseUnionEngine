//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_LOGGER_H
#define FALSEUNION_LOGGER_H
#include <string>
class Logger {
public:
    std::string info;
    std::string warning;
    std::string error;
    std::string log() const;
    Logger();
};
#endif //FALSEUNION_LOGGER_H