//
// Created by SkyTFB on 10/7/2025.
//
#pragma once

#include <list>

#include "Attribute.h"

namespace FalseUnion
{
    class GameObject
    {
    public:
        GameObject(); // default game object constructor
        virtual ~GameObject(); // virtual destructor for use in inheritance.
        void AddAttribute(const Attribute* attribute); // Adds attribute to attribute list of game object
        Attribute GetAttribute(std::string AttributeName);
        // Retrieves attribute by name from attribute list of game object
        bool HasAttribute(std::string AttributeName); // Checks if game object has a given attribute with name
        void RemoveAttribute(std::string AttributeName); // Removes an attribute from game object of given name
    private:
        std::pmr::list<Attribute> attributes; // list of attributes for game object.
    };
}
