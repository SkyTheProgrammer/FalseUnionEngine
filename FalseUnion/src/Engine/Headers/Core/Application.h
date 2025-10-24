//
// Created by SkyTFB on 10/7/2025.
//
#pragma once


#include "Window.h"
#include "../Graphics/Renderer.h"
#include "../Input/InputManager.h"
#include "../Core/Core.h"
    

namespace FalseUnion
{
    class FALSEUNION_API Application{
    public:
    Application(); // default constructor for application
    virtual ~Application(); // virtual destructor for application
    void Run(); // run method for application
    void Initialize(); // initialize method for application
    void Update(float time); // update method for application, param time for use in update.
    void Render(); // render function for application
    void Shutdown(); // shutdown function for application
    Application& getInstance() const; // getter for application instance.
    //Window getWindow() const; // getter for application current window
    Renderer getRenderer() const; // getter for application current renderer.
    void windowOnEvent(Event& e);
    private:
    Application *s_instance; // applications current instance.
    std::unique_ptr<Window> m_Window;
    Renderer *m_renderer; // applications current renderer
    InputManager *m_inputManager; // applications current input manager.
    bool m_running; // bool for if application is running.
    float m_lastFrameTime; // float for the time it took the last frame to generate.
    };
    
    Application* CreateApplication(); // declaration for create method for use in client
}


