//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Input/InputManager.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for input manager, Defaults mouse position to 0,0
    /// </summary>
    InputManager::InputManager() : mousePosition(0, 0), mouseLastPosition(0, 0)
    {
        //constructor for inputmanager
    }

    /// <summary>
    /// Default virtual destructor of input manager, here in case of inheritance.
    /// </summary>
    InputManager::~InputManager()
    = default;


    /// <summary>
    /// Updates for inputmanager, runs update key states and update mouse states every cycle as well as any other necessary code every cycle.
    /// </summary>
    void InputManager::Update()
    {
        //inputmanagers update function
    }

    /// <summary>
    /// Tells whether a given key is notPressed in the key states list
    /// </summary>
    /// @param key int representing key on keyboard
    /// @return bool true if key is notPressed in list false otherwise
    bool InputManager::IsKeyNotPressed(int key)
    {
        // checks list for key, if not pressed return true otherwise return false.
        return false;
    }

    /// <summary>
    /// Tells whether a given key is pressed in the key states list
    /// </summary>
    /// @param key int representing key on keyboard
    /// @return bool true if key is pressed in list false otherwise
    bool InputManager::IsKeyPressed(int key)
    {
        //takes in key outputs if that key is currently in the pressed state in the list of keys and states
        return false;
    }

    /// <summary>
    /// Tells whether a given key is released in the key states list
    /// </summary>
    /// @param key int representing key on keyboard
    /// @return bool true if key is released in list false otherwise
    bool InputManager::IsKeyReleased(int key)
    {
        //takes in key outputs if that key is currently in the released state in the list of keys and states
        return false;
    }

    /// <summary>
    /// Tells whether a given key is held in the key states list
    /// </summary>
    /// @param key int representing key on keyboard
    /// @return bool true if key is held in list false otherwise
    bool InputManager::IsKeyHeld(int key)
    {
        //takes in key outputs if that key is currently in the held state in the list of keys and states
        return false;
    }

    /// <summary>
    /// Tells whether a given mouse button is notPressed in the mouse states list
    /// </summary>
    /// @param button int representing button on mouse
    /// @return bool true if button is notPressed in list false otherwise
    bool InputManager::IsMouseButtonNotPressed(int button)
    {
        // checks if button in list is currently not pressed, returns true if it is, false if it isn't.
        return false;
    }

    /// <summary>
    /// Tells whether a given mouse button is pressed in the mouse states list
    /// </summary>
    /// @param button int representing button on mouse
    /// @return bool true if button is pressed in list false otherwise
    bool InputManager::IsMouseButtonPressed(int button)
    {
        //takes in mousebutton outputs if that button is currently in the pressed state in the list of keys and states
        return false;
    }

    /// <summary>
    /// Tells whether a given mouse button is Released in the mouse states list
    /// </summary>
    /// @param button int representing button on mouse
    /// @return bool true if button is pressed in list false otherwise
    bool InputManager::IsMouseButtonReleased(int button)
    {
        //takes in mousebutton outputs if that button is currently in the released state in the list of keys and states
        return false;
    }
    
    /// <summary>
    /// Tells whether a given mouse button is held in the mouse states list
    /// </summary>
    /// @param button int representing button on mouse
    /// @return bool true if button is held in list false otherwise
    bool InputManager::IsMouseButtonHeld(int button)
    {
        //takes in mousebutton outputs if that button is currently in the held state in the list of keys and states
        return false;
    }

    /// <summary>
    /// Returns current mousePosition
    /// </summary>
    /// @return Vector2 Current mousePosition
    Vector2 InputManager::GetMousePosition()
    {
        return mousePosition;
    }

    /// <summary>
    /// Returns current mouseLastPosition
    /// </summary>
    /// @return Vector2 Current mouseLastPosition
    Vector2 InputManager::GetMouseLastPosition()
    {
        return mouseLastPosition;
    }

    /// <summary>
    /// Updates Key States list based on user key interactions.
    /// </summary>
    void InputManager::UpdateKeyStates()
    {
        //updates key states
    }

    /// <summary>
    /// Updates Mouse States list based on user key interactions
    /// </summary>
    void InputManager::UpdateMouseStates()
    {
        //updates mouse states
    }
}
