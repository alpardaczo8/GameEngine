#pragma once

#include <glm/glm.hpp>

class Camera 
{
public:
    Camera() = default;
    Camera(float fov, float aspect, float nearPlane, float farPlane);
    Camera(float aspectRatio) : m_aspectRatio(aspectRatio) {}

    const glm::vec3& getPosition() const { return m_position; }
    const glm::vec3& getUp() const { return m_up; }
    const glm::vec3& getRight() const { return m_right; }
    const glm::vec3& getForward() const { return m_forward; }

    glm::mat4 getProjectionMatrix() const;
    glm::mat4 getViewMatrix() const;
    float getYaw() const { return m_yaw; }
    float getPitch() const { return m_pitch; }

    void setPosition(const glm::vec3& position) { m_position = position; }

    void moveForward(float distance);
    void moveRight(float distance);
    void moveUp(float distance);
    void rotate(float yawOffset, float pitchOffset);

    ~Camera() = default;
private:
    glm::vec3 m_position {0.0f, 1.0f, 3.0f};

    glm::vec3 m_forward {0.0f, 0.0f, -1.0f};
    glm::vec3 m_up    {0.0f, 1.0f, 0.0f};
    glm::vec3 m_right {1.0f, 0.0f, 0.0f};

    glm::vec3 m_worldUp {0.0f, 1.0f, 0.0f};

    float m_yaw = -90.0f;
    float m_pitch = 0.0f;

    float m_fov = 45.0f;
    float m_aspectRatio;
    float m_nearPlane = 0.1f;
    float m_farPlane  = 100.0f;
};