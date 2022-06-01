#pragma once
#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

#include "WindowInterface.h"
#include "WindowType.h"

using namespace std;
using namespace sf;

class BaseWindow : public sf::NonCopyable, public WindowInterface
{
private:
    RenderWindow* Window;

    string WindowName;

    WinType WindowType;

    Color BackGroundColor;

    vector<Drawable*> ObjectsToDraw;

    bool ResizeEnabled;

public:
    BaseWindow();
    virtual ~BaseWindow();

    virtual void EventProcessing();
    virtual void DrawObjects();
    virtual RenderWindow* CreateWindow();

    void SetWindow(RenderWindow* NewWindow);

    void SetWindowName(string const NewWindowName) override;
    void SetWindowSize(unsigned int const NewWindowWidth, unsigned int const NewWindowHeight) override;
    void SetFullScreen() override;
    void SetWindowPosition(unsigned int const NewWindowXpos, unsigned int const NewWindowYpos) override;
    void SetObjectsToDraw(vector<Drawable*>* const NewObjectsToDraw) override;
    void SetBackGround(Color const &NewColor) override;
    void SetWindowType(WinType const NewWindowType) override;
    void SetVisible(bool Visible = true) override;

    WinType GetWindowType() override;

    bool IsWindowOpen() override; 

    void DisplayWindow() override;
};

#endif