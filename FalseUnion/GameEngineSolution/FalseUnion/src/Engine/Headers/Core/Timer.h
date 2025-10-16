//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

namespace FalseUnion
{
    class FALSEUNION_API Timer
    {
    public:
        Timer(); // default constructor for timer.
        virtual ~Timer(); // virtual deconstructor for timer in case of inheritance.
        float GetTime(); // Getter for time.
        void Sleep(float seconds); // Sleep function to sleep for given time
    private:
        float m_time; // float representing time.
    };
}
