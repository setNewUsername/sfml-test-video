#pragma once
#ifndef TEST_H
#define TEST_H

#include "../ThreadClient/ThreadClient.h"
#include <iostream>

using namespace std;

class test : public ThreadClient
{
private:
    
public:
    test();
    ~test();

    void TestFunc();
};

#endif