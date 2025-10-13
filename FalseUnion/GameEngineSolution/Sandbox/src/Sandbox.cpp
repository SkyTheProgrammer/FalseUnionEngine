#include "FalseUnion.h"

class Sandbox : public FalseUnion::Application
{
    public:
    Sandbox()
    {
        
    }

    ~Sandbox()
    {
        
    }
};

class Log : public FalseUnion::Logger
{
    public:
    Log()
    {
        
    }
    
    ~Log()
    {
        
    }
};

FalseUnion::Application* FalseUnion::CreateApplication()
{
    return new Sandbox();
}

FalseUnion::Logger* FalseUnion::CreateLogger()
{
    return new Log();
}