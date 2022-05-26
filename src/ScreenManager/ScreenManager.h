#pragma once
#ifndef SCREENMANAGER_H
#define SCREEMMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../ThreadClient/ThreadClient.h"
#include "Window/WindowContainer.h"

using namespace sf;
using namespace std;

class ScreenManager : public ThreadClient
{
private:
    vector<Drawable*>* ObjectsToDraw;
    vector<WindowContainer*>* Windows;

    Drawable* DrawableToAdd;

    int ScreenWidth;
    int ScreenHeight;

    bool ScreenSizeChanged;

    RenderWindow* ScreenWindow;

    void ScreenManagerLoop();

public:
    ScreenManager();
    ~ScreenManager();

    vector<Drawable*>* GetObjects();

    RenderWindow* GetWindowByDesc(WINDOWS_DESCRIPTIONS WinDesc);

    void StartScreenManagerLoop();
    void SetScreenSize(int NewScreenWidth, int NewScreenHeight);
    void SetupMainWindow();
    void AddDrawableObject(Drawable* ObjectToDraw);
    void PushWindow(unsigned int Width, unsigned int Height, string Name, WINDOWS_DESCRIPTIONS WindowDesc);
};
#endif