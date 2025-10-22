//
// Created by SkyTFB on 10/7/2025.
//

#include "fupch.h"
#include "../../Headers/Core/Timer.h"

namespace FalseUnion
{
    /// <summary>
    /// Default constructor for timer
    /// </summary>
    Timer::Timer()
    {
    }

    /// <summary>
    /// Default virtual destructor for timer in case of inheritance.
    /// </summary>
    Timer::~Timer()
    {
    }

    /// <summary>
    /// getter for time, returns float time
    /// </summary>
    /// @returns float time
    float Timer::GetTime()
    {
        return 0;
    }

    /// <summary>
    /// intakes float seconds and sleeps for given time.
    /// </summary>
    /// @param seconds time for sleep to happen in seconds.
    void Timer::Sleep(float seconds)
    {
    }
}
