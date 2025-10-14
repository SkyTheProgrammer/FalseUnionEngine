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