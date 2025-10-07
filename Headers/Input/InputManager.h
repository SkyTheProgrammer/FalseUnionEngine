//
// Created by SkyTFB on 10/7/2025.
//

#ifndef FALSEUNION_INPUT_H
#define FALSEUNION_INPUT_H
#include <list>
#include <string>
#include <utility>

#include "../Math/Vector2.h"

class InputManager {
public:
    enum keyState {
        notPressed = 1,
        pressed = 2,
        held = 3,
        released = 4
    };
    InputManager();
    void Update();
    bool IsKeyPressed(int key);
    bool IsKeyReleased(int key);
    bool IsKeyHeld(int key);
    bool IsMouseButtonPressed(int button);
    bool IsMouseButtonReleased(int button);
    bool IsMouseButtonHeld(int button);
    Vector2 GetMousePosition();
    private:
    std::list<std::pair<int, keyState>> keyStates;
    std::list<std::pair<int, keyState>> mouseButtonStates;
    Vector2 mousePosition;
    Vector2 mouseLastPosition;
    void UpdateKeyStates();
    void UpdateMouseStates();


};
#endif //FALSEUNION_INPUT_H