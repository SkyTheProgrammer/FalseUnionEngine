#pragma once

#include "../../Headers/Core/Core.h"
#include "../../Headers/Events/Event.h"
#include <string>
#include "../../Headers/Core/Timestep.h"


namespace FalseUnion
{
    class FALSEUNION_API Layer 
    {
    public:
        /// <summary>
        /// constructor that defines a string defaults to layer
        /// </summary>
        /// @param name string&, defaults to layer.
        Layer(const std::string& name = "Layer");
        virtual ~Layer(); // virtual destructor as this class will be inherited from.

        virtual void OnAttach() {} // to be used to attach layers
        virtual void OnDetach() {} // to be used to detach layers
        virtual void OnUpdate(Timestep timestep) {} // to be called on app update
        virtual void OnImGuiRender() {} // to be call on ImGui Render.
        virtual void OnEvent(Event& event) {} // Layers on event binding function thing.

        const std::string& GetName() const { return m_DebugName; } // GetName mainly used for debug.

    protected:
        std::string m_DebugName; // name for layer, only really used for debugging.
    };
}
