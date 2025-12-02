#include "fupch.h"

#include "../../Headers/Platform/WindowsWindow.h"
#include "../../Headers/Core/Logger.h"

#include "../../Headers/Events/KeyEvent.h"
#include "../../Headers/Events/MouseEvent.h"
#include "../../Headers/Events/ApplicationEvent.h"

#include "../../Headers/Platform/WindowsInput.h"

#include "../../Headers/Platform/OpenGL/OpenGLContext.h"

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

namespace FalseUnion
{
    static bool GLFWInitialized = false; // sets the initial state of the static bool GLFWInitialized.

    static void GLFWErrorCallback(int error, const char* description)
    {
        FU_ENGINE_ERROR("GLFW Error " + std::to_string(error) + ": " + description);
    }
    /// <summary>
    /// Create function for window, uses the provided properties to make a WindowsWindow with those params.
    /// </summary>
    /// @param props WindowProperties&, uses the windows properties struct to build a WindowsWindow.
    Window* Window::Create(const WindowProperties& props)
    {
        return new WindowsWindow(props);
    }

    /// <summary>
    /// Calls window Init to initialize a new window with provided props. Ensures GLFW safety.
    /// </summary>
    /// @param props WindowProperties&, properties struct for WindowsWindow defines important variables like title width and height.
    WindowsWindow::WindowsWindow(const WindowProperties& props)
    {
        WindowsWindow::Init(props);
    }

    // Default virtual destructor for windows window.
    WindowsWindow::~WindowsWindow() = default;

    /// <summary>
    /// Initializer for WindowsWindow. Takes in WindowProperties and sets window to match, then logs the creation to engine and checks if GLFW was initialized.
    /// Sets a few GLFW values to good defaults.
    /// </summary>
    /// @param props WindowProperties&, Properties to set window variables to.
    void WindowsWindow::Init(const WindowProperties& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        FU_ENGINE_INFO(
            "creating window " + props.Title + " (" + std::to_string(props.Width) + ", " + std::to_string(props.Height)
            + ")");


        if (!GLFWInitialized)
        {
            glfwSetErrorCallback(GLFWErrorCallback);
            int success = glfwInit();
            if (success == 0)
            {
                FU_ENGINE_ASSERT(success, "Failed to initialize GLFW!");
            }

            GLFWInitialized = true;
        }
        m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), m_Data.Title.c_str(),
                                    nullptr, nullptr);

        m_Context = new OpenGLContext(m_Window);
        m_Context->Init();
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);


        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int KeyCode){
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            KeyTypedEvent event(KeyCode);
            data.EventCallback(event);
        });
        
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            data.Width = width;
            data.Height = height;
            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (action)
            {
            case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
            case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
            case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (action)
            {
            case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });
        
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
            data.EventCallback(event);
        });
    }

    /// <summary>
    /// Ensures GLFW window is destroyed on shutdown.
    /// </summary>
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    /// <summary>
    /// Calls important glfw functions on update.
    /// </summary>
    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        m_Context->SwapBuffers();
        
    }

    /// <summary>
    /// Sets VSync based on provided bool
    /// </summary>
    /// @param enabled bool, if true enables Vsync otherwise disables it.
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
