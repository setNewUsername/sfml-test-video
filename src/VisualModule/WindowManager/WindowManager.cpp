#include "WindowManager.h"

WindowManager::WindowManager() : 
WindowFac(nullptr)
{
}

WindowManager::~WindowManager()
{
}

void WindowManager::AddNewWindow(WinType WindowToGet)
{
    if(GetWindowByType(WindowToGet, true) == nullptr)
    {
        WindowInterface* NewWindow = WindowFac->CreateWindow(WindowToGet);
        if(NewWindow != nullptr)
            WindowCollection.push_back(NewWindow);
        else
            cout << "Window is nullptr" << endl;
    }
    else
    {
        cout << "That window already exists" << endl;
    }
    cout << "Added new window; type = " << WindowToGet << endl;
}

void WindowManager::SetupScreen()
{
    if(WindowFac != nullptr)
    {
        AddNewWindow(WIN_TYPE_MAIN);
        //AddNewWindow(WIN_TYPE_0);
    }
    else
        cout << "Window factory is nullptr" << endl;
}

void WindowManager::ShowAllWindows()
{
    while (1)
    {
        for(auto CurrentWindow : WindowCollection)
        {
            if(CurrentWindow != nullptr)
            {
                if(CurrentWindow->IsWindowOpen())
                {
                    CurrentWindow->DisplayWindow();
                }
            }  
            else
                cout << "Window is nullptr" << endl;
        }
    }
}

void WindowManager::SetWindowFactory(WindowFactory* NewWindowFac)
{
    WindowFac = NewWindowFac;
}

WindowInterface* WindowManager::GetWindowByType(WinType WindowToGet, bool MuteMessage)
{
    WindowInterface* Result = nullptr;

    for(WindowInterface* CurrentWindow : WindowCollection)
    {
        if(CurrentWindow->GetWindowType() == WindowToGet)
        {
            Result = CurrentWindow;
            break;
        }
    }

    if(Result == nullptr && !MuteMessage)
        cout << "Where is no window of that type" << endl;
    return Result;
}

void WindowManager::Test()
{
    while(GetWindowByType(WIN_TYPE_MAIN)->IsWindowOpen())
    {
        ShowAllWindows();
    }
}