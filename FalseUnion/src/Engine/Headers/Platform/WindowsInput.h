#pragma once

#include "../Input/InputManager.h"
#include "../Core/Core.h"

namespace FalseUnion
{
    class FALSEUNION_API WindowsInput : public InputManager
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;

        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;

        virtual std::pair<float, float> GetMousePositionImpl() override;

    
    };
}
