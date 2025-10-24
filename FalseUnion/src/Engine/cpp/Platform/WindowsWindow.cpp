#include "fupch.h"
#include "../../Headers/Platform/WindowsWindow.h"

#include "../../Headers/Core/Logger.h"


namespace FalseUnion
{
    static bool GLFWInitialized = false; // sets the initial state of the static bool GLFWInitialized.

    /// <summary>
    /// Create function for window, uses the provided properties to make a WindowsWindow with those params.
    /// </summary>
    /// @param props WindowProperties&, uses the windows properties struct to build a WindowsWindow.
    Window* Window::Create(const WindowProperties& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow() = default;

    void WindowsWindow::Init(const WindowProperties& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        FU_ENGINE_INFO("creating window " + props.Title + " (" + std::to_string(props.Width) + ", " + std::to_string(props.Height) + ")");

        if (!GLFWInitialized)
        {
            int success = glfwInit();
            if (success == 0)
            {
                FU_ENGINE_ASSERT(success, "Failed to initialize GLFW!");
            }

            GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }
}
