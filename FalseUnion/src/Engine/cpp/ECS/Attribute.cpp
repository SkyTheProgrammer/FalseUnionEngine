#include "../../Headers/ECS/Attribute.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for attribute, sets name to ""
    /// </summary>
    Attribute::Attribute()
    {
        name = "";
    }

    /// <summary>
    /// virtual destructor for attribute, used for inheritance.
    /// </summary>
    Attribute::~Attribute()
    {
    }

    /// <summary>
    /// Constructor for attribute with param for name
    /// </summary>
    /// @param newName String, the to be name of the attribute.
    Attribute::Attribute(const std::string& newName)
    {
        name = newName;
    }

    /// <summary>
    /// Setter for Attribute name, takes in string
    /// </summary>
    /// @param newName String, to be name of the attribute
    void Attribute::setName(const std::string& newName)
    {
        name = newName;
    }

    /// <summary>
    /// Getter for Attribute returns string
    /// </summary>
    /// @returns string Attribute name
    std::string Attribute::getName()
    {
        return name;
    }
}
