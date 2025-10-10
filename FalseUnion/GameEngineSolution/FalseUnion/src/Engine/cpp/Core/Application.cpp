//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Application.h"

namespace FalseUnion{
Application::Application() : s_instance(this), m_window(nullptr), m_renderer(nullptr), m_inputManager(nullptr),
                             m_running(false),
                             m_lastFrameTime(0) {
}
Application::~Application()
{}
    

void Application::Run() {
    //Initializes the application, runs the application, starts the update loop
    printf("Running...\n");
    while (true);
}

void Application::Initialize() {
    //Defines any important variables and objects.
}

void Application::Update(float time) {
    //Updates the application and renders any changes.
}

void Application::Render() {
    //uses the renderer to render and update visual information.
}

void Application::Shutdown() {
    //when this is run saves and gracefully shuts down the program.
}

Application Application::getInstance() const {
    //returns this applications instance
    return *s_instance;
}

Window Application::getWindow() const {
    return *m_window;
}

Renderer Application::getRenderer() const {
    return *m_renderer;
}
}
