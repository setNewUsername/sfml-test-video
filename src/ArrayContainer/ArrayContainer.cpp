#include "ArrayContainer.h"

ArrayContainer::ArrayContainer() : 
ArrayPointer(nullptr),
ArraySize(0)
{
    srand(time(0));
}

ArrayContainer::~ArrayContainer()
{
}

void ArrayContainer::CreateArray(unsigned int NewArraySize)
{
    ArrayPointer = new int[NewArraySize];
    ArraySize = NewArraySize;

    for(int i = 0; i < ArraySize; i++)
    {
        ArrayPointer[i] = 0;
    }
}

void ArrayContainer::SetRandRange(int StartPoint, int EndPoint)
{
    for(int i = 0; i < ArraySize; i++)
    {
        ArrayPointer[i] = StartPoint + rand() % (EndPoint - StartPoint + 1);
    }
}

void ArrayContainer::PrintArray()
{
    for(int i = 0; i < ArraySize; i++)
    {
        cout << ArrayPointer[i] << " ";
    }
    cout << endl;
}

void ArrayContainer::SwapElements(unsigned int FirstElementIndex, unsigned int SecondElementIndex)
{
    int Tmp = ArrayPointer[FirstElementIndex];
    ArrayPointer[FirstElementIndex] = ArrayPointer[SecondElementIndex];
    ArrayPointer[SecondElementIndex] = Tmp;
}

int ArrayContainer::GetArraySize()
{
    return ArraySize;
}