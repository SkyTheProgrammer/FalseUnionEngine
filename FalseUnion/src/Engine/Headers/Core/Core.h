#pragma once

// sets up to build and communicate between engine and client. ensures windows only support.

#ifdef FU_PLATFORM_WINDOWS
    #ifdef FU_BUILD_DLL
        #define FALSEUNION_API __declspec(dllexport)
    #else
        #define FALSEUNION_API __declspec(dllexport)
    #endif
#else
    #error FalseUnion only supports windows.
#endif

#ifdef FU_ENABLE_ASSERTS
    #define FU_CLIENT_ASSERT(x, ...) {if(!(x)){ FU_CLIENT_ERROR("Assertion failed: " + __VA_ARGS__); __debugbreak; } }
    #define FU_ENGINE_ASSERT(x, ...) {if(!(x)){ FU_ENGINE_ERROR("Assertion failed: " + __VA_ARGS__); __debugbreak; } }
#else
    #define FU_CLIENT_ASSERT(x, ...)
    #define FU_ENGINE_ASSERT(x, ...)
#endif
