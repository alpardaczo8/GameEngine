#include "Core/Application.hpp"
#include "Renderer/Renderer.hpp"
#include "Core/Logger.hpp"

namespace Engine
{   
Application::Application(/* args */)
{
    m_window = std::make_unique<SDLWindow>(800, 600, "Game Engine");
    ENG_INFO("Application initialized.");
}

Application::~Application()
{
    ENG_INFO("Application shutting down.");
}

void Application::run()
{
    ENG_WARNING("Running application...");
    m_renderer.init();
    // Main application loop
    while (!m_window->shouldClose())
    {
        m_window->pollEvents();
        // Update and render your application here
        m_renderer.clear();
        m_renderer.draw();
        m_window->swapBuffers();
    }
    ENG_ERROR("This is an error message for testing purposes.");
}

}