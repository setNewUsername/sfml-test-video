#include "WindowContainer.h"

WindowContainer::WindowContainer() : 
WindowName("none"),
WindowWidth(100),
WindowHeight(100),
WindowObj(nullptr),
WindowDesciptor(),
DrawableCont(nullptr)
{
    DrawableCont = new vector<Drawable*>;
}

WindowContainer::~WindowContainer()
{
}

void WindowContainer::SetWindowSize(unsigned int NewWindowWidth, unsigned int NewWindowHeight)
{
    WindowWidth = NewWindowWidth;
    WindowHeight = NewWindowHeight;
}

void WindowContainer::SetWindowName(string NewWindowName)
{
    WindowName = NewWindowName;
}

void WindowContainer::SetWindowDescriptor(WINDOWS_DESCRIPTIONS NewWindowDescriptor)
{
    WindowDesciptor = NewWindowDescriptor;
}

RenderWindow* WindowContainer::GetWindowObj()
{
    return WindowObj;
}

void WindowContainer::CreateWindow()
{
    WindowObj = new RenderWindow(VideoMode(WindowWidth, WindowHeight), WindowName.c_str());
    WindowObj->setFramerateLimit(30);

    cout << "Created window. Size: width = " << GetWidth() << " heght = " << GetHeight() << endl;
}

WINDOWS_DESCRIPTIONS WindowContainer::GetWindowDesc()
{
    return WindowDesciptor;
}

void WindowContainer::DrawObjects()
{
    if(WindowObj != nullptr)
    {
        for(auto CurrentObject : *DrawableCont)
        {
            WindowObj->draw(*CurrentObject);
        }
    }
}

int WindowContainer::GetWidth()
{
    int Result(0);

    if(WindowObj != nullptr)
    {
        Result = WindowObj->getSize().x;
    }

    return Result;
}

int WindowContainer::GetHeight()
{
    int Result(0);

    if(WindowObj != nullptr)
    {
        Result = WindowObj->getSize().y;
    }

    return Result;
}

void WindowContainer::SetDrawableObjectCollection(vector<Drawable*>* NewDrawableCont)
{
    DrawableCont = NewDrawableCont;
}