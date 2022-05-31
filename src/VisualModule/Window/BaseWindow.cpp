#include "BaseWindow.h"

BaseWindow::BaseWindow() : 
Window(nullptr),
BackGroundColor(Color::Black),
WindowType(WIN_TYPE_NONE)
{
    Window = new RenderWindow(VideoMode(100, 100, 32), "none");
    Window->setFramerateLimit(30);
}

BaseWindow::~BaseWindow()
{
}

void BaseWindow::EventProcessing()
{
    Event event;
    while (Window->pollEvent(event))
    {
        if (event.type == Event::Closed)
            Window->close();
    }
}

void BaseWindow::DrawObjects()
{
    for(Drawable* CurrentObject : ObjectsToDraw)
    {
        Window->draw(*CurrentObject);
    }
}

void BaseWindow::DisplayWindow()
{
    EventProcessing();
    Window->clear(BackGroundColor);

    DrawObjects();

    Window->display();
}

bool BaseWindow::IsWindowOpen()
{
    return Window->isOpen();
}

void BaseWindow::SetWindowName(string const NewWindowName)
{
    Window->setTitle(NewWindowName);
}

void BaseWindow::SetWindowSize(unsigned int const NewWindowWidth, unsigned int const NewWindowHeight)
{
    Window->setSize(Vector2u(NewWindowWidth, NewWindowHeight));
}

void BaseWindow::SetWindowPosition(unsigned int const NewWindowXpos, unsigned int const NewWindowYpos)
{
    Window->setPosition(Vector2i(NewWindowXpos, NewWindowYpos));
}

void BaseWindow::SetObjectsToDraw(vector<Drawable*>* NewObjectsToDraw)
{
    ObjectsToDraw = *NewObjectsToDraw;
}

void BaseWindow::SetBackGround(Color const &NewColor)
{
    BackGroundColor = NewColor;
}

WinType BaseWindow::GetWindowType()
{
    return WindowType;
}

void BaseWindow::SetWindowType(WinType NewWindowType)
{
    WindowType = NewWindowType;
}