//
// Created by SkyTFB on 10/7/2025.
//

#ifndef FALSEUNION_ATTRIBUTE_H
#define FALSEUNION_ATTRIBUTE_H
#include <string>

class Attribute {
public:
    Attribute();
    virtual ~Attribute();
    Attribute(const std::string& newName);
    void setName(const std::string& newName);
    std::string getName();
private:
    std::string name;
    
    
};
#endif //FALSEUNION_ATTRIBUTE_H