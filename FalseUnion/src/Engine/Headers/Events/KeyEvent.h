#pragma once
#include <sstream>

#include "Event.h"

namespace FalseUnion
{
    // Base Key Event class for others to inherit from, inherits from event.
    class FALSEUNION_API KeyEvent : public Event
    {
    public:
        /// <summary>
        /// Returns the key code of this KeyEvent
        /// </summary>
        /// @returns int representing key code of this KeyEvent.
        int GetKeyCode() const { return m_KeyCode; } 
        EVENT_CLASS_CATEGORY(Keyboard) // Defines the category as keyboard.

    protected:
        /// <summary>
        /// Protected constructor for KeyEvent, takes in int for KeyCode.
        /// </summary>
        /// @param keycode int to be assigned as this KeyEvents KeyCode
        KeyEvent(int keycode) : m_KeyCode(keycode)
        {
        }
        
        int m_KeyCode; // Key code declared as private
    };

    // key pressed event class inherits from key event
    class FALSEUNION_API KeyPressedEvent : public KeyEvent
    {
    public:
        /// <summary>
        /// Constructor for KeyPressedEvent. Takes in key code and repeat count as ints. Assigns both.
        /// </summary>
        /// @param keycode int representing the code of the key pressed
        /// @param repeatCount int representing the number of times the key has repeated.
        KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount)
        {
        } 

        /// <summary>
        /// Getter for repeat count
        /// </summary>
        /// @returns int repeat count of key pressed.
        int GetRepeatCount() const { return m_RepeatCount; }

        /// <summary>
        /// Override of ToString for KeyPressedEvent.
        /// </summary>
        /// @returns string, String that says "KeyPressedEvent:" then the keycode and its repeat count.
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }
        // macro definition with key pressed
        EVENT_CLASS_TYPE(KeyPressed) 
        private:
        // int for repeat count
        int m_RepeatCount;
    };
}
