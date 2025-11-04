//
// Created by SkyTFB on 10/7/2025.
//
#pragma once


#include "Window.h"
#include "../Graphics/Renderer.h"
#include "../Input/InputManager.h"
#include "../Core/Core.h"
#include "../Events/ApplicationEvent.h"
#include "../Layer/LayerStack.h"


namespace FalseUnion
{
    class FALSEUNION_API Application
    {
    public:
        Application(); // default constructor for application
        virtual ~Application(); // virtual destructor for application
        void Run(); // run method for application
        void Initialize(); // initialize method for application
        void Update(float time); // update method for application, param time for use in update.
        void Render(); // render function for application
        void Shutdown(); // shutdown function for application
        Application& getInstance() const; // getter for application instance.
        void windowOnEvent(Event& e); // Method for windows on event to be bound.
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        static Application& GetApplication();
        Window& GetWindow();

    private:
        static Application* s_Instance; // applications current instance.
        std::unique_ptr<Window> m_Window;
        bool m_Running; // bool for if application is running.
        bool OnWindowClosed(WindowCloseEvent& e); // method to bind window closed event.
        float m_LastFrameTime; // float for the time it took the last frame to generate.
        LayerStack m_LayerStack; // Layer stack for the given application.
    };

    Application* CreateApplication(); // declaration for create method to be used in client
}
