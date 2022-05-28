#pragma once
#ifndef ANSWERMASSEGES_H
#define ANSWERMASSEGES_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class DefaultAnswerMessage
{
public:
    DefaultAnswerMessage() {};
    virtual ~DefaultAnswerMessage() {};
};



class AnswerObjMgr : public DefaultAnswerMessage
{
private:
    vector<Drawable*>* DrawableCollection;

public:
    AnswerObjMgr(vector<Drawable*>* NewDrawableCollection);
    ~AnswerObjMgr();

    vector<Drawable*>* GetDrawableCollection();
};


#endif