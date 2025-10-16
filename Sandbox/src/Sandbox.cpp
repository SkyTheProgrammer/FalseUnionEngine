#include "FalseUnion.h"

class Sandbox : public FalseUnion::Application //defines sandboxes extention of application
{
    public:
    Sandbox()
    {
        
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