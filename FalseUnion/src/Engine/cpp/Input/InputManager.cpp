#include "fupch.h"
#include "../../Headers/Input/InputManager.h"
#include "../../Headers/Platform/WindowsInput.h"

namespace FalseUnion
{
    #ifdef FU_PLATFORM_WINDOWS
        InputManager* InputManager::s_Instance = new WindowsInput();
    #else
        InputManager* InputManager::s_Instance = nullptr;
    #endif
    
    bool InputManager::IsKeyPressed(int keyCode)
    {
        return s_Instance->IsKeyPressedImpl(keyCode);
    }

    bool InputManager::IsMouseButtonPressed(int mouseButton)
    {
        return s_Instance->IsMouseButtonPressedImpl(mouseButton);
    }

    float InputManager::GetMouseX()
    {
        return s_Instance->GetMouseXImpl();
    }

    float InputManager::GetMouseY()
    {
        return s_Instance->GetMouseYImpl();
    }

    std::pair<float, float> InputManager::GetMousePosition()
    {
        return s_Instance->GetMousePositionImpl();
    }
}
