#pragma once

#include <functional>
#include "../Core/Core.h"

namespace FalseUnion
{
    enum class EventType
    {
        None = 0,
        KeyPressed, KeyReleased, //KeyHeld
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled, //MouseButtonHeld
        AppTick, AppUpdate, AppRender,
        WindowClose, WindowResize, //WindowFocus, WindowLostFocus, WindowMoved
    }; // enum class to define the types of event, Added everything I could think of needing might add or remove as I see necessity.

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
    virtual EventType GetEventType() const override { return GetStaticType();}\
    virtual const std::string GetName() const {return #type;}
// macro to for GetStaticType(), GetEventType(), and GetName() for EventType such that I don't have to manually make it in classes that inherit from event.
    enum EventCategory
    {
        None = 0,
        InputEvt,
        ApplicationEvt,
        KeyboardEvt,
        MouseEvt,
        MouseButtonEvt
    }; // enum for event category
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
    //macro for GetCategoryFlags(), makes it return category.

    class FALSEUNION_API Event
    {
        friend class EventDispatcher;
        // ^ defines Event dispatcher as a friend class of event allowing access to protected variables
        // Outline a block event system.
        // Events must be dealt with as they enter
        // Try and move to a buffer system if possible.
    public:
        virtual ~Event() = default;
        virtual EventType GetEventType() const = 0; // Virtual declartion for event type getter
        virtual const std::string GetName() const = 0; // virtual declaration for name getter
        virtual int GetCategoryFlags() const = 0; // virtual declaration for category getter
        virtual std::string ToString() const { return GetName(); }
        // virtual declaration for ToString, defines GetName at top.

        /// <summary>
        /// method to check if event is in provided event category
        /// </summary>
        /// @param category EventCategory to check against the event.
        /// @returns Bool true if the event is in category false otherwise.
        inline bool IsInCategory(EventCategory category)
        {
            if (category == EventCategory::InputEvt)
            {
                if (GetCategoryFlags() == EventCategory::InputEvt || GetCategoryFlags() == EventCategory::KeyboardEvt ||
                    GetCategoryFlags() == EventCategory::MouseEvt || GetCategoryFlags() == EventCategory::MouseButtonEvt)
                {
                    return true;
                }
            }
            return GetCategoryFlags() & category;
        }

    protected:
        bool m_Handled = false; // A variable to track whether an event has been handled
    };

    class EventDispatcher // Event Dispatcher class placed inside of event as they are tightly coupled.
    {
        template <typename T>
        // Define the using EventFn so that it can be used in EventDispatcher
        // T represents a class that inherits from event.
        using EventFn = std::function<bool(T&)>;

    public:
        /// <summary>
        /// Event dispatcher takes in and assigns a reference event.
        /// </summary>
        EventDispatcher(Event& event) : m_Event(event)
        {
        }


        template <typename T>
        /// <summary>
        /// Event Dispatcher, takes in a handler event from EventFn<T> where T is a class that inherits from Event
        /// Checks the event type of the handler vs the event if it is the same runs the dispatch and return true
        /// other it returns false
        /// </summary>
        /// @param func EventFn<T> Dispatcher function of a class T where T is a class that inherits from event
        /// @return Bool, True if this dispatchers event matches the dispatch type false otherwise.
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event& m_Event; // Declaration of Event for event dispatcher to use.
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    } // overwrite of the << ostram operator such that this automatically returns its tostring
}
