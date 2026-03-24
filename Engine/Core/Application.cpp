#include "Core/Application.hpp"
#include "Renderer/Renderer.hpp"
#include "Core/Logger.hpp"

#include <vector>
#include <thread>
#include <chrono>

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

    std::vector<float> verticies = {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        -0.5f, 0.5f,0.0f,
        0.5f, 0.5f,0.0f
    };

    std::vector<unsigned int> indicies = {
         0, 1, 2,
        2, 1, 3
    };

    VertexBufferLayout layout;
    layout.push<float>(3); // 3 floats per vertex (x, y, z)
    Mesh mesh(verticies, indicies, layout);
    Material material("BasicMaterial", std::make_shared<Shader>("assets/triangle.vert", "assets/triangle.frag"));
    Camera camera(800.0f / 600.0f);
    // Main application loop
    while (!m_window->shouldClose())
    {
        m_window->pollEvents();
        // Update and render your application here
        m_renderer.clear();

        m_renderer.beginScene(camera);
        m_renderer.submit(mesh, material);
        m_renderer.endScene();
        m_window->swapBuffers();

        std::chrono::milliseconds frameTime(16); // Approximate 60 FPS
        std::this_thread::sleep_for(frameTime);
        camera.moveForward(-0.01f);
    }
}

}