#include "../../Headers/ECS/Attribute.h"

Attribute::Attribute()
{
    name = "";
}

Attribute::~Attribute()
{}

Attribute::Attribute(const std::string& newName)
{
    name = newName;
}

void Attribute::setName(const std::string& newName)
{
    name = newName;
}

std::string Attribute::getName()
{
    return name;
}

