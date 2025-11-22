//
// Created by SkyTFB on 10/7/2025.
//

#pragma once

#include <string>
#include "../Events/Event.h"
#include "Core.h"

namespace FalseUnion
{
    struct WindowProperties
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProperties(const std::string& title = "FalseUnion Engine", unsigned int width = 1280,
                         unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {
        }
    };

    class FALSEUNION_API Window // abstract class to build system specific windows from
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        // Defines EventCallbackFn as a reference to a void event function.

        virtual ~Window() = default; //default destructor for abstact class

        // virtual constructors for necessary methods.
        virtual void OnUpdate() = 0;

        virtual unsigned int GetHeight() const = 0;
        virtual unsigned int GetWidth() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enable) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;
        
        static Window* Create(const WindowProperties& properties = WindowProperties());
    };
}
