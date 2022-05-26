#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "WindowContainerEnum.h"

using namespace std;
using namespace sf;

class WindowContainer
{
private:
    string WindowName;

    int WindowWidth;
    int WindowHeight;

    RenderWindow* WindowObj;
    WINDOWS_DESCRIPTIONS WindowDesciptor;

public:
    WindowContainer();
    ~WindowContainer();

    void SetWindowSize(unsigned int NewWindowWidth, unsigned int NewWindowHeight);
    void SetWindowName(string NewWindowName);
    void SetWindowDescriptor(WINDOWS_DESCRIPTIONS NewWindowDescriptor);

    void CreateWindow();

    WINDOWS_DESCRIPTIONS GetWindowDesc();
    RenderWindow* GetWindowObj();
};



#endif