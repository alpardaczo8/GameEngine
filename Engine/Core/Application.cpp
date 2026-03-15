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
    m_renderer.init();
    float vertices[] =
    {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        -0.5f, 0.5f,0.0f,
        0.5f, 0.5f,0.0f
    };

    unsigned int indicies[] = 
    {
         0, 1, 2,
        2, 1, 3
    };

    VertexBufferLayout layout(vertices, sizeof(vertices));
    layout.push<float>(3); // 3 floats per vertex (x, y, z)
    Mesh mesh(vertices, sizeof(vertices), indicies, sizeof(indicies) / sizeof(unsigned int), layout);
    Shader shader("assets/triangle.vert", "assets/triangle.frag");

    // Main application loop
    while (!m_window->shouldClose())
    {
        m_window->pollEvents();
        // Update and render your application here
        m_renderer.clear();
        m_renderer.draw(mesh, shader);
        m_window->swapBuffers();
    }
}

}