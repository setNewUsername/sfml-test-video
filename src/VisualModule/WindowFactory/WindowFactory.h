#pragma once
#ifndef WINDOWFACTORY_H
#define WINDOWFACTORY_H

#include <vector>
#include <iostream>

#include "../Window/WindowInterface.h"
#include "../Window/BaseWindow.h"
#include "../Window/WindowType.h"

using namespace std;

class WindowFactory
{
private:
    WindowInterface* CreateMainWindow();

public:
    WindowFactory();
    ~WindowFactory();

    WindowInterface* CreateWindow(WinType TypeOfNewWindow);
};

#endif