//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Window.h"

namespace FalseUnion
{
    Window* Window::m_window = nullptr;
    /// <summary>
    /// Default constructor for window, defaults size to my monitors size and title to ""
    /// </summary>
    Window::Window()
    {
        m_size = Vector2(2560,1600); //my monitors resolution
        m_title= "";
    }

    /// <summary>
    /// window constructor with params for size and title
    /// </summary>
    /// @param width int, to be width of the window
    /// @param height int, to be height of the window
    /// @param title string, to be title of the window
    Window::Window(int width, int height, const std::string& title)
    {
        m_size = { static_cast<float>(width), static_cast<float>(height) };
        m_title = title;
    }

    /// <summary>
    /// default virtual destructor in case of inheritance.
    /// </summary>
    Window::~Window()
    {
    }

    /// <summary>
    /// getter for window size
    /// </summary>
    /// @returns Vector2 window size
    Vector2 Window::getSize()
    {
        return m_size;
    }

    /// <summary>
    /// Getter for window title
    /// </summary>
    /// @returns string Window title.
    std::string Window::getTitle()
    {
        return m_title;
    }

    /// <summary>
    /// Setter for window title.
    /// </summary>
    /// @param title String, to be window title.
    void Window::setTitle(const std::string& title)
    {
        m_title = title;
    }

    /// <summary>
    /// Setter for window size.
    /// </summary>
    /// @param width int, to be width of window size
    /// @param height int, to be height of window
    void Window::setSize(int width, int height)
    {
        m_size = { static_cast<float>(width), static_cast<float>(height) };
    }

    /// <summary>
    /// setter for static m_window, makes this window m_window
    /// </summary>
    void Window::setPrimaryWindow()
    {
        m_window = this;
    }


    /// <summary>
    /// Getter for native window
    /// </summary>
    /// @returns int representing native window.
    int Window::getNativeWindow()
    {
        return 0;
    }

    /// <summary>
    /// Frame Buffer method for window
    /// </summary>
    void Window::FrameBuffer(Window window, int width, int height)
    {
    }
}
