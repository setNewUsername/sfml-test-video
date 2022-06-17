#pragma once
#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <vector>
#include <iostream>

#include "../Window/WindowInterface.h"
#include "../Window/WindowType.h"
#include "../WindowFactory/WindowFactory.h"

using namespace std;

class WindowManager
{
private:
    vector<WindowInterface*> WindowCollection;
    WindowFactory* WindowFac;

    void AddNewWindow(WinType WindowToGet);

public:
    WindowManager();
    ~WindowManager();

    void SetWindowFactory(WindowFactory* NewWindowFac);

    WindowInterface* GetWindowByType(WinType WindowToGet, bool MuteMessage = false);

    void Test();

    void SetupScreen();
    void ShowAllWindows();
};

#endif