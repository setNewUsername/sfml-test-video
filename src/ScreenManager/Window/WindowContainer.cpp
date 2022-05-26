#include "WindowContainer.h"

WindowContainer::WindowContainer() : 
WindowName("none"),
WindowWidth(100),
WindowHeight(100),
WindowObj(nullptr),
WindowDesciptor()
{
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
}

WINDOWS_DESCRIPTIONS WindowContainer::GetWindowDesc()
{
    return WindowDesciptor;
}