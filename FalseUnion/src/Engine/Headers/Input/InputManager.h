//
// Created by SkyTFB on 10/7/2025.
//
#pragma once

#include <list>
#include "../Math/Vector2.h"

namespace FalseUnion
{
    class InputManager
    {
    public:
        enum keyState
        {
            notPressed = 0,
            pressed = 1,
            held = 2,
            released = 3
        }; //enum to represent different keystates
        InputManager(); // Constructor for input manager
        virtual ~InputManager(); // Virtual deconstructor for input manager
        void Update(); // Update method for Input manager
        bool IsKeyNotPressed(int key);
        bool IsKeyPressed(int key); // Bool method to tell if a key is pressed
        bool IsKeyReleased(int key); // Bool method to tell if a key is released
        bool IsKeyHeld(int key); // Bool method to tell if a key is held
        bool IsMouseButtonNotPressed(int button);
        bool IsMouseButtonPressed(int button); // Bool method to tell if a mouse button is pressed
        bool IsMouseButtonReleased(int button); // Bool method to tell if a mouse button is released
        bool IsMouseButtonHeld(int button); // Bool method to tell if a mouse button is held.
        Vector2 GetMousePosition(); // Method to return the Vector2 of the mouse.
        Vector2 GetMouseLastPosition(); // Method to return the Vector2 of mouse's last position.

    private:
        std::list<std::pair<int, keyState>> keyStates; // List defining keys and their states in pairs
        std::list<std::pair<int, keyState>> mouseButtonStates; // list defining mouse buttons and their states in pairs
        Vector2 mousePosition; // Vector2 defining current mouse position
        Vector2 mouseLastPosition; // Vector2 defining last mouse position
        void UpdateKeyStates(); // method to update key states
        void UpdateMouseStates(); // method to update mouse button states
    };
}
