//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/ECS/GameObject.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for game object.
    /// </summary>
    GameObject::GameObject()
    {
    }

    /// <summary>
    /// virtual destructor for game object
    /// </summary>
    GameObject::~GameObject()
    {
    }

    /// <summary>
    /// Adds the given attribute to game objects attribute list
    /// </summary>
    /// @param attribute Attribute, attribute to be added to the game object
    void GameObject::AddAttribute(const Attribute* attribute)
    {
        attributes.push_front(*attribute);
    }

    /// <summary>
    /// Returns an attribute of given name from attribute list.
    /// </summary>
    /// @param AttributeName String, name of attribute to search for
    /// @returns Attribute found in list, default attribute if none.
    Attribute GameObject::GetAttribute(std::string AttributeName)
    {
        return Attribute();
    }

    /// <summary>
    /// Returns a bool based on if an attribute with a given name exists in the attributes list.
    /// </summary>
    /// @param AttributeName String, name of attribute to search for
    /// @returns bool, true if found false otherwise
    bool GameObject::HasAttribute(std::string AttributeName)
    {
        return false;
    }

    /// <summary>
    /// removes an attribute from list if it matches given attribute name.
    /// </summary>
    /// @param AttributeName String, attribute to be removed
    void GameObject::RemoveAttribute(std::string AttributeName)
    {
    }
}
