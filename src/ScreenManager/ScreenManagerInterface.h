#pragma once
#ifndef SCREENMANAGERINTERFACE_H
#define SCREENMANAGERINTERFACE_H

class ScreenManagerInterface
{
public:
    virtual ~ScreenManagerInterface() = 0;

    virtual int GetScreenWidth();
    virtual int GetScreenHeight();
};

#endif