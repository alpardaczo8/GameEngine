#include <Core/Timer.hpp>

float Timer::getDeltaTime()
{
    auto currentTime = Timer::Clock::now();
    std::chrono::duration<float> deltaTime = currentTime - m_lastTime;
    m_lastTime = currentTime;
    return deltaTime.count();
}
