#pragma once

#include <chrono>

class Timer
{
public:
    using Clock = std::chrono::high_resolution_clock;

    Timer() : m_lastTime(Clock::now()) {}
    float getDeltaTime();
private:
    Clock::time_point now() const { return Clock::now(); }
    Clock::time_point m_lastTime;
};
