//
// Created by SkyTFB on 10/7/2025.
//

#ifndef FALSEUNION_APPLICATION_H
#define FALSEUNION_APPLICATION_H
#include "Window.h"
#include "../Graphics/Renderer.h"
#include "../Input/Input.h"

class Application {
public:
    Application();
    void Run();
    void Initialize();
    void Update(float time);
    void Render();
    void Shutdown();
    Application getInstance();
    Window getWindow();
    Renderer getRenderer();
private:
    Application s_instance;
    Window *m_window;
    Renderer *m_renderer;
    InputManager *m_inputManager;
    bool m_running;
    float m_lastFrameTime;
};
#endif //FALSEUNION_APPLICATION_H