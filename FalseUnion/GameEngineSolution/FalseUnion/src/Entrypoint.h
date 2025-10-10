#pragma once

#ifdef FU_PLATFORM_WINDOWS
#include "Engine/Headers/Core/Logger.h"

extern FalseUnion::Application* FalseUnion::CreateApplication();
extern FalseUnion::Logger* FalseUnion::CreateLogger();

int main(int argc, char** argv)
{
    auto app = FalseUnion::CreateApplication();
    auto logger = FalseUnion::CreateLogger();
    FalseUnion::Logger::setLoggerInstance(logger);
    FU_CLIENT_WARN("This is a warning to the client");
    FU_ENGINE_ERROR("This is an error to the engine");
    app->Run();
    delete app;

    return 0;
}
#endif