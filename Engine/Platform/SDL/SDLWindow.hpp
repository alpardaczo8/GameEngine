#pragma once

#include <Platform/IWindow.hpp>
#include <SDL3/SDL.h>
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

    SDL_Window* m_window;
    SDL_GLContext m_context;

    bool m_isOpen = false;
};

}