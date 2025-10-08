//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Core/Application.h"

Application::Application() : s_instance(this), m_window(nullptr), m_renderer(nullptr), m_inputManager(nullptr),
                             m_running(false),
                             m_lastFrameTime(0) {
}

void Application::Run() {
}

void Application::Initialize() {
}

void Application::Update(float time) {
}

void Application::Render() {
}

void Application::Shutdown() {
}

Application Application::getInstance() {
}

Window Application::getWindow() {
}

Renderer Application::getRenderer() {
}
