#include "Core/Application.hpp"
#include <Core/Timer.hpp>
#include "Core/Logger.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/CameraController.hpp"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
    //   x      y       z       nx      ny      nz       u      v
        -0.5f,  -0.5f,  0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   0.0f,
        0.5f,   -0.5f,  0.0f,   0.0f,   0.0f,   1.0f,   1.0f,   0.0f,
        -0.5f,  0.5f,   0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   1.0f,
        0.5f,   0.5f,   0.0f,   0.0f,   0.0f,   1.0f,   1.0f,   1.0f
    };

    std::vector<unsigned int> indicies = {
         0, 1, 2,
        2, 1, 3
    };

    VertexBufferLayout layout;
    layout.push<float>(3); // 3 floats per vertex (x, y, z)
    layout.push<float>(3); // normals
    layout.push<float>(2); // UV
    Mesh mesh(verticies, indicies, layout);
    auto texture = std::make_shared<Texture>("assets/brick.png");
    Material material("BasicMaterial", std::make_shared<Shader>("assets/triangle.vert", "assets/triangle.frag"), texture);
    Camera camera(800.0f / 600.0f);
    CameraController cameraController(camera);
    Timer timer;
    glm::vec3 lightPos = camera.getPosition();
    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
    // Main application loop
    while (!m_window->shouldClose())
    {
        float deltaTime = timer.getDeltaTime();
        m_window->pollEvents();
        // Update and render your application here
        m_renderer.clear();

        if (m_window->wasKeyPressed(SDL_SCANCODE_F5))
            material.getShader()->reload();

        const bool* keyboard = SDL_GetKeyboardState(nullptr);

        cameraController.handleInput(keyboard, deltaTime);
        // Handling camera mouseMovement
        float dx = m_window->getMouseDeltaX();
        float dy = m_window->getMouseDeltaY();

        if (dx != 0.0f || dy != 0.0f)
        cameraController.handleMouseMovement(dx, dy);

        glm::mat4x4 transform{1.0};
        m_renderer.beginScene(camera);
        material.getShader()->setVec3("u_LightPos", lightPos);
        material.getShader()->setVec3("u_LightColor", lightColor);
        material.getShader()->setVec3("u_ViewPos", camera.getPosition());
        m_renderer.submit(mesh, material, transform);
        transform = glm::translate(transform, glm::vec3{0.5f, 0.0f, 0.0f});
        transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3{0.0f, 1.0f, 0.0f});
        m_renderer.submit(mesh, material, transform);
        m_renderer.endScene();
        m_window->swapBuffers();
    }
}

}