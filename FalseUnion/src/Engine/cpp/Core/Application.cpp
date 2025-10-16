//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Application.h"

namespace FalseUnion
{
    /// <summary>
    /// Default application constructor, sets the instance to this application, and all variables to their default constructors.
    /// </summary>
    Application::Application()
    {
        s_instance = this;
        m_window = new Window();
        m_renderer = new Renderer();
        m_inputManager = new InputManager();
        m_lastFrameTime = 0.0f;
    }

    /// <summary>
    /// default virtual destructor in case of inheritance.
    /// </summary>
    Application::~Application()
    {
    }

    /// <summary>
    /// Run method for application starts a while running loop.
    /// </summary>
    void Application::Run()
    {
        //Initializes the application, runs the application, starts the update loop
        printf("Running...\n");
        m_running = true;
        while (m_running);
    }

    /// <summary>
    /// Defines the important application objects and then run's application.
    /// </summary>
    void Application::Initialize()
    {
        //Defines any important variables and objects.
    }

    /// <summary>
    /// Runs all updates and passes time when necessary, sets new time since last frame.
    /// </summary>
    /// @param time float, time to be passed when necessary
    void Application::Update(float time)
    {
        //Updates the application and renders any changes.
    }

    /// <summary>
    /// Uses its renderer to render and updates it with any pertinent information.
    /// </summary>
    void Application::Render()
    {
        //uses the renderer to render and update visual information.
    }
    /// <summary>
    /// Gracefully shuts down the application and does whatever it needs to do before that happens. (saving, ect.)
    /// </summary>
    void Application::Shutdown()
    {
        //when this is run saves and gracefully shuts down the program.
    }

    /// <summary>
    /// Returns the applications instance.
    /// </summary>
    /// @returns Application, instance of application.
    Application Application::getInstance() const
    {
        //returns this applications instance
        return *s_instance;
    }

    /// <summary>
    /// Returns the applications window.
    /// </summary>
    /// @returns Window applications window.
    Window Application::getWindow() const
    {
        return *m_window;
    }

    /// <summary>
    /// Returns the applications renderer
    /// </summary>
    /// @returns Renderer, applications renderer.
    Renderer Application::getRenderer() const
    {
        return *m_renderer;
    }
}
