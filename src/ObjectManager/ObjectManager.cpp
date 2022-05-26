#include "ObjectManager.h"

ObjectManager::ObjectManager(vector<sf::Drawable*>* Objects) : 
ObjetsVec(nullptr)
{
    ObjetsVec = new vector<sf::Drawable*>;
    ObjetsVec = Objects;
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Test()
{
    int a = 0;
    int b = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(!GetThreadStatusKilled())
        {
            RectangleShape* shape = new RectangleShape();
            shape->setFillColor(Color(255, 0, 0, 255));

            if(a>1000)
            {
                b+=10;
                a = 0;
            }

            cout << a << " " << b << endl;

            shape->setSize(Vector2f(10,10));

            shape->setPosition(Vector2f(a, b));

            Lock();
            ObjetsVec->push_back(shape);
            Unlock();

            //cout << "Added object" << endl;
            a+=10;

            this_thread::sleep_for(10ms);
        }
    }
}