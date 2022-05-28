#include "ObjectManager.h"

ObjectManager::ObjectManager(MessageDistributor* NewMsgDistr, MessageFactory* NewMsgFac) : 
ObjectCollection(nullptr)
{
    this->SetMsgClientName(OBJECT_MANAGER_MSG_CLI);
    this->SetMsgClientTag("obj manager");
    this->SetMessageFactory(NewMsgFac);
    this->SetMsgDistr(NewMsgDistr);

    this->GetMsgDistributor()->RegMsgClient(static_cast<MessageClientInterface*>(this));

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

DefaultAnswerMessage* ObjectManager::ConstructAnswer()
{
    switch (GetMessageToAnswer()->GetMessageBody())
    {
    case MSG_GET_OBJ_TO_DRAW:
        return new AnswerObjMgr(ObjectCollection);
        break;
    
    default:
        return new AnswerObjMgr(new vector<Drawable*>);
        break;
    }
    
    
}