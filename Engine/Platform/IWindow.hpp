#pragma once

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void pollEvents() = 0;
    virtual void swapBuffers() = 0; 

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    virtual float getMouseDeltaX() const = 0;
    virtual float getMouseDeltaY() const = 0;
    virtual float getScrollDeltaY() const = 0;

    virtual bool shouldClose() const = 0;
    virtual bool wasKeyPressed(int scancode) const = 0;
};
