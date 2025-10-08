//
// Created by SkyTFB on 10/7/2025.
//

#ifndef FALSEUNION_GAMEOBJECT_H
#define FALSEUNION_GAMEOBJECT_H
#include <list>

#include "Attribute.h"

class GameObject {
public:
    GameObject();
    void AddAttribute();
    Attribute GetAttribute(std::string AttributeName);
    bool HasAttribute(std::string AttributeName);
    void RemoveAttribute(std::string AttributeName);
private:
    std::pmr::list<Attribute> attributes;
};
#endif //FALSEUNION_GAMEOBJECT_H