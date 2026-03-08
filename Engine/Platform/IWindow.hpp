class IWindow
{
public:
    virtual ~IWindow();

    virtual void pollEvents() = 0;
    virtual void swapBuffers() = 0;

    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
};
