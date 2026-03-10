#include "Core/Application.hpp"

namespace Engine
{   
Application::Application(/* args */)
{
    m_window = std::make_unique<SDLWindow>(800, 600, "Game Engine");
}

Application::~Application()
{

}

void Application::run()
{
    // Main application loop
    while (!m_window->shouldClose())
    {
        m_window->pollEvents();
        // Update and render your application here
        m_window->swapBuffers();    
    }
}

}