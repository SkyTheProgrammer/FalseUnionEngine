//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_TIMER_H
#define FALSEUNION_TIMER_H
class Timer {
    public:
        double time;
        float GetTime();
        void Sleep(float seconds);
        Timer();
};

#endif //FALSEUNION_TIMER_H