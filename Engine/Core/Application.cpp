#include "Core/Application.hpp"
#include <Core/Timer.hpp>
#include "Core/Logger.hpp"
#include "Renderer/Renderer.hpp"

#include <chrono>
#include <thread>
#include <vector>

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
    Timer timer;
    // Main application loop
    while (!m_window->shouldClose())
    {
        float deltaTime = timer.getDeltaTime();
        m_window->pollEvents();
        // Update and render your application here
        m_renderer.clear();

        const bool* keyboard = SDL_GetKeyboardState(nullptr);

        if (keyboard[SDL_SCANCODE_W])
            camera.moveForward(0.01f * deltaTime * 60.0f); // Move forward at a speed of 0.01 units per second
        if (keyboard[SDL_SCANCODE_S])
            camera.moveForward(-0.01f * deltaTime * 60.0f); // Move forward at a speed of 0.01 units per second
        if (keyboard[SDL_SCANCODE_A])
            camera.moveRight(-0.01f * deltaTime * 60.0f); // Move right at a speed of 0.01 units per second
        if (keyboard[SDL_SCANCODE_D])
            camera.moveRight(0.01f * deltaTime * 60.0f); // Move right at a speed of 0.01 units per second
        m_renderer.beginScene(camera);
        m_renderer.submit(mesh, material);
        m_renderer.endScene();
        m_window->swapBuffers();
    }
}

}