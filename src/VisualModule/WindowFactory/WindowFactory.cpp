#include "WindowFactory.h"

WindowFactory::WindowFactory()
{
}

WindowFactory::~WindowFactory()
{
}

WindowInterface* WindowFactory::CreateWindow(WinType TypeOfNewWindow)
{
    WindowInterface* NewWindow = nullptr;

    switch (TypeOfNewWindow)
    {
    case WIN_TYPE_NONE:
        cout << "NONE type of window" << endl;
        break;
    
    case WIN_TYPE_MAIN:
        NewWindow = CreateMainWindow();
        break;

    default:
        cout << "Where is no window of that type" << endl;
        break;
    }

    cout << "Created new window; type = " << TypeOfNewWindow << endl;
    return NewWindow;
}

WindowInterface* WindowFactory::CreateMainWindow()
{
    BaseWindow* Window = new BaseWindow();
    Window->SetWindowType(WIN_TYPE_MAIN);
    Window->SetWindowName("Main window");

    return static_cast<WindowInterface*>(Window);
}