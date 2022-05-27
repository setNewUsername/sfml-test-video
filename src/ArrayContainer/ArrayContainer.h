#pragma once 
#ifndef ARRAYCONTAINER_H
#define ARRAYCONTAINER_H

#include <iostream>
#include <ctime>

using namespace std;

class ArrayContainer
{
private:
    int* ArrayPointer;
    int ArraySize;

public:
    ArrayContainer();
    ~ArrayContainer();

    void CreateArray(unsigned int NewArraySize);
    void SetRandRange(int StartPoint, int EndPoint);
    void PrintArray();
    void SwapElements(unsigned int FirstElementIndex, unsigned int SecondElementIndex);

    int GetArraySize();

    int operator [] (unsigned int ElementNumber)
    {
        return ArrayPointer[ElementNumber];
    }
};

#endif