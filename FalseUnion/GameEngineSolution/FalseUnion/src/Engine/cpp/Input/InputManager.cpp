//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Input/InputManager.h"

InputManager::InputManager() : mousePosition(0,0), mouseLastPosition(0,0) {
    //constructor for inputmanager
}


void InputManager::Update() {
    //inputmanagers update function
}

bool InputManager::IsKeyPressed(int key) {
    //takes in key outputs if that key is currently in the pressed state in the list of keys and states
    return false;
}

bool InputManager::IsKeyReleased(int key) {
    //takes in key outputs if that key is currently in the released state in the list of keys and states
    return false;
}

bool InputManager::IsKeyHeld(int key) {
    //takes in key outputs if that key is currently in the held state in the list of keys and states
    return false;
}

bool InputManager::IsMouseButtonPressed(int button) {
    //takes in mousebutton outputs if that button is currently in the pressed state in the list of keys and states
    return false;
}

bool InputManager::IsMouseButtonReleased(int button) {
    //takes in mousebutton outputs if that button is currently in the released state in the list of keys and states
    return false;
}

bool InputManager::IsMouseButtonHeld(int button) {
    //takes in mousebutton outputs if that button is currently in the held state in the list of keys and states
    return false;
}

Vector2 InputManager::GetMousePosition() {
    //returns mouses Vector2
    return mousePosition;
}

void InputManager::UpdateKeyStates() {
    //updates key states
}

void InputManager::UpdateMouseStates() {
    //updates mouse states
}
