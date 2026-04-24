#include <Renderer/RTSCameraController.hpp>
#include <SDL3/SDL.h>

void RTSCameraController::handleInput(const bool* keyboard, float deltaTime)
{

    if (keyboard[SDL_SCANCODE_W])
        panMove(0.0f, -m_panSpeed * deltaTime, deltaTime);
    if (keyboard[SDL_SCANCODE_S])
        panMove(0.0f, m_panSpeed * deltaTime, deltaTime);
    if (keyboard[SDL_SCANCODE_A])
        panMove(-m_panSpeed * deltaTime, 0.0f, deltaTime);
    if (keyboard[SDL_SCANCODE_D])
        panMove(m_panSpeed * deltaTime, 0.0f, deltaTime);
    if (keyboard[SDL_SCANCODE_E])
        panMove(0.0f, 0.0f, m_panSpeed * deltaTime);
    if (keyboard[SDL_SCANCODE_Q])
        panMove(0.0f, 0.0f, -m_panSpeed * deltaTime);
}

void RTSCameraController::handleMouseMovement(float xOffset, float yOffset)
{
    m_camera.rotate(xOffset * m_rotationSensitivity, -yOffset * m_rotationSensitivity);
}

void RTSCameraController::handleMouseScroll(float yOffset)
{
    glm::vec3 pos = m_camera.getPosition();
    float newY = pos.y - yOffset * m_scrollSensitivity;

    if (newY >= m_zoomMin && newY <= m_zoomMax)
    {
        pos.y = newY;
        m_camera.setPosition(pos);
    }
}

void RTSCameraController::panMove(float xOffset, float zOffset, float deltaTime)
{
    // Project forward and right onto the XZ plane
    glm::vec3 forward = m_camera.getForward(); // you'll need to expose this
    glm::vec3 right   = m_camera.getRight();

    forward.y = 0.0f;
    right.y   = 0.0f;
    forward   = glm::normalize(forward);
    right     = glm::normalize(right);

    glm::vec3 pos = m_camera.getPosition();
    pos += (-forward) * zOffset + right * xOffset;

    pos.x = glm::clamp(pos.x, m_boundXMin, m_boundXMax);
    pos.z = glm::clamp(pos.z, m_boundZMin, m_boundZMax);
    m_camera.setPosition(pos);
}