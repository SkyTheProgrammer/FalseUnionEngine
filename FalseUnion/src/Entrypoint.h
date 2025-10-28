#pragma once

#ifdef FU_PLATFORM_WINDOWS // makes sure users platform is windows
#include "Engine/Headers/Core/Logger.h"

// Extern to allow Engine to communicate and build with client, pushing creation of important things like application to client
// Use these to create things that you need to see in console as engines console is hidden from user, also use these to create things from the client.
extern FalseUnion::Application* FalseUnion::CreateApplication(); 
extern FalseUnion::Logger* FalseUnion::CreateLogger();

int main(int argc, char** argv)
{
    // uses client to create logger
    FalseUnion::Logger::initializeLogger(FalseUnion::CreateLogger());
    auto app = FalseUnion::CreateApplication(); //uses client to create application
     // sets the logger instance to the client created logger.
    // FU_CLIENT_WARN("This is a warning to the client"); //uncomment to test logger
    // FU_ENGINE_ERROR("This is an error to the engine");
    app->Run(); //runs the application
    delete app; //ensures the application is thrown away.

    return 0; // ensures all trash is picked up.
}
#endif