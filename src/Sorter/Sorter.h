#pragma once
#ifndef SORTER_H
#define SORTER_H

#include "../ArrayContainer/ArrayContainer.h"

class Sorter// : public ThreadClient
{
private:
    ArrayContainer* ArrayContPointer;
    string SortirationName;

protected:
    void SetSortirationName(string NewSortirationName);
    void PrintSortirationName();
    ArrayContainer* GetArrayContPointer();

public:
    Sorter();
    virtual ~Sorter();

    void SetArrayContPointer(ArrayContainer* NewArrayContPointer);
    virtual void SortArray();
};

#endif