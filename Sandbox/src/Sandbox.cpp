#include "FalseUnion.h"

class TestLayer : public FalseUnion::Layer
{
public:
    TestLayer() : Layer("Test"){}

    void OnUpdate() override
    {
        // FU_CLIENT_INFO("LAYER TEST EXAMPLE WORKED");
    }

    void OnEvent(FalseUnion::Event& event) override
    {
        FU_CLIENT_INFO(event.ToString());
    }
};

class Sandbox : public FalseUnion::Application //defines sandboxes extention of application
{
    public:
    Sandbox()
    {
        PushLayer(new TestLayer());

        PushOverlay(new FalseUnion::ImGuiLayer());
    }

    ~Sandbox()
    {
        
    }
};

class Log : public FalseUnion::Logger // defines sandboxes extention of logger
{
    public:
    Log()
    {
        
    }
    
    ~Log()
    {
        
    }
};



FalseUnion::Application* FalseUnion::CreateApplication() // defines create application from the client such that the client can create it for the engine.
{
    return new Sandbox(); 
}

FalseUnion::Logger* FalseUnion::CreateLogger() // defines create logger from the client such that the client can create it for the engine.
{
    return new Log();
}