#pragma once

#ifdef FU_PLATFORM_WINDOWS
    #ifdef FALSEUNION_BUILD_DLL
        #define FALSEUNION_API __declspec(dllexport)
    #else
        #define FALSEUNION_API __declspec(dllexport)
    #endif
#else
    #error FalseUnion only supports windows.
#endif