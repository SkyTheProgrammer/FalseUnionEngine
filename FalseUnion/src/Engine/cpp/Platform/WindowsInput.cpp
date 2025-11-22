#include "fupch.h"

#include "../../Headers/Platform/WindowsInput.h"

#include "../../Headers/Core/Application.h"
#include <GLFW/glfw3.h>

namespace FalseUnion
{
    
    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto[x,y] = GetMousePositionImpl();
        return x;
    }
    
    float WindowsInput::GetMouseYImpl()
    {
        auto[x,y] = GetMousePositionImpl();
        return y;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);

        return {static_cast<float>(x),static_cast<float>(y)};
    }
}
