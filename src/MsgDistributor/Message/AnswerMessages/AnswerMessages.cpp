#include "AnswerMessages.h"

AnswerObjMgr::AnswerObjMgr(vector<Drawable*>* NewDrawableCollection) : 
DrawableCollection(nullptr)
{
    DrawableCollection = NewDrawableCollection;
}

AnswerObjMgr::~AnswerObjMgr()
{
}

vector<Drawable*>* AnswerObjMgr::GetDrawableCollection()
{
    return DrawableCollection;
}