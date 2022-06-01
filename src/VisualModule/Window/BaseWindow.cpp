#include "BaseWindow.h"

BaseWindow::BaseWindow() : 
Window(nullptr),
BackGroundColor(Color::Black),
WindowType(WIN_TYPE_NONE),
ResizeEnabled(true),
WindowName("none")
{
    Window = this->CreateWindow();
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
        if(event.type == Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                Window->close();
        }
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
    WindowName = NewWindowName;
    Window->setTitle(WindowName);
}

void BaseWindow::SetWindowSize(unsigned int const NewWindowWidth, unsigned int const NewWindowHeight)
{
    if(ResizeEnabled)
        Window->setSize(Vector2u(NewWindowWidth, NewWindowHeight));
}

void BaseWindow::SetFullScreen()
{
    Window->setSize(Vector2u(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Window->setPosition(Vector2(0, 0));
    ResizeEnabled = false;
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

void BaseWindow::SetVisible(bool Visible)
{
    Window->setVisible(Visible);
}

RenderWindow* BaseWindow::CreateWindow()
{
    cout << "Creating new window; BaseWindow" << endl; 
    return new RenderWindow(VideoMode(100, 100, 32), WindowName, Style::Default);
}

void BaseWindow::SetWindow(RenderWindow* NewWindow)
{
    if(NewWindow != nullptr)
    {   
        delete(Window);
        Window = NewWindow;
    }
    else
        cout << "ERROR NEW WINDOW IS NULLPTR" << endl;
}