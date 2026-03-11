#pragma once

#include <Platform/IWindow.hpp>
#include <GLAD/glad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <string>

namespace Engine
{

class SDLWindow : public IWindow
{   
public:
    SDLWindow(int width, int height, const std::string& title);
    ~SDLWindow();

    void pollEvents() override;
    void swapBuffers() override;

    int getWidth() override;
    int getHeight() override;

    bool shouldClose() const { return !m_isOpen; }

private:
    void createWindow(int width, int height, const std::string& title);
    void destroyWindow();

    SDL_Window* m_window = nullptr;
    SDL_GLContext m_context = nullptr;

    bool m_isOpen = false;
};

}