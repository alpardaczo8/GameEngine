#include <Renderer/Camera.hpp>

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspect, float nearPlane, float farPlane)
    : m_fov(fov), m_aspectRatio(aspect), m_nearPlane(nearPlane), m_farPlane(farPlane) 
{
    m_forward = glm::vec3(0.0f, 0.0f, -1.0f);
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getProjectionMatrix() const 
{
    return glm::perspective(glm::radians(m_fov), m_aspectRatio, m_nearPlane, m_farPlane);
}

glm::mat4 Camera::getViewMatrix() const 
{
    return glm::lookAt(m_position, m_position + m_forward, m_up);
}

void Camera::moveForward(float distance) 
{
    m_position += m_forward * distance;
}

void Camera::moveRight(float distance) 
{
    m_position += m_right * distance;
}

void Camera::moveUp(float distance)
{
    m_position += m_worldUp * distance;
}

void Camera::rotate(float yawOffset, float pitchOffset) 
{
    m_yaw += yawOffset;
    m_pitch += pitchOffset;

    // Constrain the pitch to prevent screen flipping
    if (m_pitch > 89.0f)
        m_pitch = 89.0f;
    if (m_pitch < -89.0f)
        m_pitch = -89.0f;

    // Update forward vector
    glm::vec3 forward;
    forward.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    forward.y = sin(glm::radians(m_pitch));
    forward.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_forward = glm::normalize(forward);

    // Recalculate right and up vectors
    m_right = glm::normalize(glm::cross(m_forward, m_worldUp));
    m_up = glm::normalize(glm::cross(m_right, m_forward));
}

