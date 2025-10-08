//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_LOGGER_H
#define FALSEUNION_LOGGER_H
#include <string>
class Logger {
public:
    [[nodiscard]] std::string log() const;
    [[nodiscard]] std::string getInfo() const;
    [[nodiscard]] std::string getWarning() const;
    [[nodiscard]] std::string getError() const;
    void setInfo(const std::string &newInfo);
    void setWarning(const std::string &newWarning);
    void setError(const std::string &newError);

    Logger();
    Logger(const std::string &newInfo, const std::string &newWarning, const std::string &newError);
    Logger(const std::string &newInfo, const std::string &newWarning);
    explicit Logger(const std::string &newInfo);
private:
    std::string info;
    std::string warning;
    std::string error;
};
#endif //FALSEUNION_LOGGER_H