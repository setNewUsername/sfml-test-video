#include "MainWindow.h"

MainWindow::MainWindow()
{
    SetWindow(CreateWindow());
    SetBackGround(Color::White);
    SetWindowType(WIN_TYPE_MAIN);
    SetFullScreen();
}

MainWindow::~MainWindow()
{
}

RenderWindow* MainWindow::CreateWindow()
{
    return new RenderWindow(VideoMode(100, 100, 32), "Main Window", Style::Default);
}