//
// Created by SkyTFB on 10/7/2025.
//

#include "fupch.h"
#include "../../Headers/Core/Application.h"

#include <GL/gl.h>

#include "../../Headers/Core/Logger.h"
#include "../../Headers/Events/ApplicationEvent.h"
#include "../../Headers/Events/MouseEvent.h"
#include "../../Headers/Events/KeyEvent.h"

namespace FalseUnion
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1) // macro to prevent repeating bind code block



    /// <summary>
    /// Default application constructor, sets the instance to this application, and all variables to their default constructors.
    /// </summary>
    Application::Application()
    {
        s_instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(windowOnEvent));
        m_renderer = new Renderer();
        m_inputManager = new InputManager();
        m_lastFrameTime = 0.0f;
    }

    /// <summary>
    /// Dispatches given event and displays to console. Binds certain events to actions (e.g pressing window close closes window)
    /// </summary>
    /// @param e Event&, the event in deed of dispatch.
    void Application::windowOnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));
        FU_ENGINE_INFO(e.ToString());

        //holy this is complicated
        for (auto stackEnd = m_LayerStack.end(); stackEnd != m_LayerStack.begin();) // gets the end of the stack and every iteration of the loop makes sure we haven't hit the beginning.
        {
            (*--stackEnd)->OnEvent(e); // dereferences, decrements and then calls the OnEvent method of the layer passing the given event.
            if (e.IsHandled())
            {
                
            }
        }
    }

    /// <summary>
    /// default virtual destructor in case of inheritance.
    /// </summary>
    Application::~Application()
    = default;

    /// <summary>
    /// Run method for application starts a while running loop.
    /// </summary>
    void Application::Run()
    {
        //Initializes the application, runs the application, starts the update loop
        printf("Running...\n");
        m_Running = true;
        while (m_Running)
        {
            glClearColor(1.0f, 0.3f, 1.0f, 1.0f); // just a bit of fun to see if i can colour the background.
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack) // foreach for layer in stack
            {
                layer->OnUpdate(); // runs layers on update
            }
            m_Window->OnUpdate(); // runs windows on update
        }
    }

    /// <summary>
    /// Event to be bound to window close. Ensures app stops running properly.
    /// </summary>
    /// @param e WindowCloseEvent&, the event that caused this might be useful later.
    /// @returns bool, true for now, might have a false response as needed later.
    bool Application::OnWindowClosed(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
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
    Application& Application::getInstance() const
    {
        //returns this applications instance
        return *s_instance;
    }

    /// <summary>
    /// Returns the applications window.
    /// </summary>
    /// @returns Window applications window.
    // Window Application::getWindow() const
    // {
    //     return *m_window;
    // }

    /// <summary>
    /// Returns the applications renderer
    /// </summary>
    /// @returns Renderer, applications renderer.
    Renderer Application::getRenderer() const
    {
        return *m_renderer;
    }

    /// <summary>
    /// Pushes the given layer from this apps layer stack using the LayerStacks .PushLayer() method.
    /// </summary>
    /// @param layer Layer*, Pointer layer you want pushed from stack, used to find and push from stack.
    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    /// <summary>
    /// Pushes the given layer from the stacks overlay using the PushOverlay method from LayerStack
    /// </summary>
    /// @param overlay Layer*, pointer to the layer you want pushed from this stacks overlay, used to find and push from stack.
    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }
}
