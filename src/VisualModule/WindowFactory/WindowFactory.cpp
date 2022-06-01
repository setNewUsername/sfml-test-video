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

    case WIN_TYPE_0:
        NewWindow = CreateTestWindow();
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
    MainWindow* Window = new MainWindow();

    return static_cast<WindowInterface*>(Window);
}

WindowInterface* WindowFactory::CreateTestWindow()
{
    BaseWindow* Window = new BaseWindow();
    Window->SetWindowType(WIN_TYPE_0);
    Window->SetWindowName("TEST WINDOW");
    Window->SetVisible(false);

    return static_cast<WindowInterface*>(Window);
}