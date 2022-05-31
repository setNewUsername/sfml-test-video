#pragma once
#ifndef WINDOWINTERFACE_H
#define WINDOWINTERFACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "WindowType.h"

using namespace std;
using namespace sf;

class WindowInterface
{
public:
    WindowInterface() {};
    virtual ~WindowInterface() {};

    virtual void SetWindowName(string const NewWindowName) = 0;
    virtual void SetWindowSize(unsigned int const NewWindowWidth, unsigned int const NewWindowHeight) = 0;
    virtual void SetWindowPosition(unsigned int const NewWindowXpos, unsigned int const NewWindowYpos) = 0;
    virtual void SetObjectsToDraw(vector<Drawable*>* NewObjectsToDraw) = 0;
    virtual void SetBackGround(Color const &NewColor) = 0;
    virtual void SetWindowType(WinType NewWindowType) = 0;

    virtual WinType GetWindowType() = 0;

    virtual bool IsWindowOpen() = 0;

    virtual void DisplayWindow() = 0;
};

#endif