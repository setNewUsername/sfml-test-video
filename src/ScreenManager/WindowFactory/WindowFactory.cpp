#include "WindowFactory.h"

WindowFactory::WindowFactory() : 
WinContColl(nullptr)
{
    WinContColl = new vector<WindowContainer*>;
}

WindowFactory::~WindowFactory()
{
}

void WindowFactory::CreateWindowContainer(WINDOWS_DESCRIPTIONS NewWindowDesc)
{
    WindowContainer* NewWindow = nullptr;

    switch (NewWindowDesc)
    {
    case MAIN_WINDOW:
        NewWindow = CreateMainWindow();
        break;
    
    case WINDOW_ONE:
        NewWindow = CreateWindowOne();
        break;

    default:
        break;
    }

    WinContColl->push_back(NewWindow);
}

WindowContainer* WindowFactory::CreateMainWindow()
{
    WindowContainer* NewWindow = new WindowContainer();
    NewWindow->SetWindowSize(1500, 800);
    NewWindow->SetWindowName("Main window");
    NewWindow->SetWindowDescriptor(MAIN_WINDOW);
    NewWindow->CreateWindow();

    return NewWindow;
}

WindowContainer* WindowFactory::CreateWindowOne()
{
    WindowContainer* NewWindow = new WindowContainer();
    NewWindow->SetWindowSize(800, 800);
    NewWindow->SetWindowName("Window num.1");
    NewWindow->SetWindowDescriptor(MAIN_WINDOW);
    NewWindow->CreateWindow();
    return NewWindow;
}

vector<WindowContainer*>* WindowFactory::GetWindowCollection()
{
    return WinContColl;
}