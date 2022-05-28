#pragma once 
#ifndef WINDOWCONTAINERINTERFACE_H
#define WINDOWCONTAINERINTERFACE_H

class WindowContainerInterface
{
private:
    
public:
    WindowContainerInterface() {};
    virtual ~WindowContainerInterface() {};

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;
};

#endif