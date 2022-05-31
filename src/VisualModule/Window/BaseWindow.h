#pragma once
#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "WindowInterface.h"
#include "WindowType.h"

using namespace std;
using namespace sf;

class BaseWindow : public sf::NonCopyable, public WindowInterface
{
private:
    RenderWindow* Window;

    WinType WindowType;

    Color BackGroundColor;

    vector<Drawable*> ObjectsToDraw;

    virtual void EventProcessing();
    virtual void DrawObjects();

public:
    BaseWindow();
    ~BaseWindow();

    void SetWindowName(string const NewWindowName) override;
    void SetWindowSize(unsigned int const NewWindowWidth, unsigned int const NewWindowHeight) override;
    void SetWindowPosition(unsigned int const NewWindowXpos, unsigned int const NewWindowYpos) override;
    void SetObjectsToDraw(vector<Drawable*>* NewObjectsToDraw) override;
    void SetBackGround(Color const &NewColor) override;
    void SetWindowType(WinType NewWindowType) override;

    WinType GetWindowType() override;

    bool IsWindowOpen() override; 

    void DisplayWindow() override;
};

#endif