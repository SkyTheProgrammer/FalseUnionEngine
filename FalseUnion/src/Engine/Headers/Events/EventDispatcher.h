#pragma once

#include "Event.h"

namespace FalseUnion
{
    class EventDispatcher
    {
        
    public:
        EventDispatcher(Event& event) : m_event(event)
        {
        }

        bool Dispatch();
        
    private:
        Event& m_event;
    };
}
