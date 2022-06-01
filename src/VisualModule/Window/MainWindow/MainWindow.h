#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

#include "../BaseWindow.h"

using namespace sf;

class MainWindow : public BaseWindow
{
private:
    
public:
    MainWindow();
    ~MainWindow();

    RenderWindow* CreateWindow() override;
};

#endif