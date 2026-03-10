#pragma once

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void pollEvents() = 0;
    virtual void swapBuffers() = 0;

    virtual int getWidth() = 0;
    virtual int getHeight() = 0;

    virtual bool shouldClose() const = 0;
};
