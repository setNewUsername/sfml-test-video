#pragma once
#ifndef WINDOWCONTAINER_H
#define WINDOWCONTAINER_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "WindowContainerEnum.h"
#include "WindowContainerInterface.h"

using namespace std;
using namespace sf;

class WindowContainer : public WindowContainerInterface
{
private:
    string WindowName;

    int WindowWidth;
    int WindowHeight;

    vector<Drawable*>* DrawableCont;

    RenderWindow* WindowObj;
    WINDOWS_DESCRIPTIONS WindowDesciptor;

public:
    WindowContainer();
    ~WindowContainer();

    void SetWindowSize(unsigned int NewWindowWidth, unsigned int NewWindowHeight);
    void SetWindowName(string NewWindowName);
    void SetWindowDescriptor(WINDOWS_DESCRIPTIONS NewWindowDescriptor);
    void SetDrawableObjectCollection(vector<Drawable*>* NewDrawableCont);

    void CreateWindow();
    void DrawObjects();

    int GetWidth() override;
    int GetHeight() override;

    WINDOWS_DESCRIPTIONS GetWindowDesc();
    RenderWindow* GetWindowObj();
};

#endif