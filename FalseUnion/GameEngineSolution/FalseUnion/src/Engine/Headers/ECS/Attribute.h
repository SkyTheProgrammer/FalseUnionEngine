//
// Created by SkyTFB on 10/7/2025.
//
#pragma once

#include <string>

namespace FalseUnion
{
    class FALSEUNION_API Attribute
    {
    public:
        Attribute(); // Default attribute constructor
        virtual ~Attribute(); // virtual attribute destructor for inheratence
        Attribute(const std::string& newName); // attribute constructor that takes in param for name.
        void setName(const std::string& newName); // method to set name
        std::string getName(); // method to get name
    private:
        std::string name; //attributes name
    };
}
