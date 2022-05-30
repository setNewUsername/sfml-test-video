#include "ObjectManager.h"

ObjectManager::ObjectManager() : 
ObjectCollection(nullptr)
{
    ObjectCollection = new vector<Drawable*>;

    CreateTestObjects(1000);
} 

ObjectManager::~ObjectManager()
{
}

void ObjectManager::CreateTestObjects(int ObjectsAmount)
{  
    int x(0), y(0);
    for(int i = 0; i < ObjectsAmount; i++)
    {
        RectangleShape* shape = new RectangleShape();
        shape->setSize(Vector2f(10, 10));
        shape->setFillColor(Color(255, 0, 0, 255));
        shape->setPosition(x, y);

        ObjectCollection->push_back(shape);

        x += 10;

        if(x > 1500)
        {
            x = 0; 
            y+=10;
        }
    }
}