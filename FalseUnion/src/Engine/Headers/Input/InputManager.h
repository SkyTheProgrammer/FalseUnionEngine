#pragma once

#include "../Core/Core.h"

namespace FalseUnion{
    class FALSEUNION_API InputManager
    {
    public:

        static bool IsKeyPressed(int keyCode);

        static bool IsMouseButtonPressed(int mouseButton);

        static float GetMouseX();

        static float GetMouseY();

        static std::pair<float, float> GetMousePosition();

    protected:
        virtual bool IsKeyPressedImpl(int keyCode) = 0;
        virtual bool IsMouseButtonPressedImpl(int mouseButton) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
    private:
        static InputManager* s_Instance;
    };
}