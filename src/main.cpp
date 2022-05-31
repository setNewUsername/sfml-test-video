#include <iostream>
#include "ThreadManager/ThreadManager.h"

#include "MessageModule/MsgDistr/MsgDistr.h"
#include "MessageModule/MsgClient/MsgClient.h"
#include "MessageModule/MsgClient/MsgClientName.h"

#include "MessageModule/MsgQueue/MsgQueue.h"
#include "MessageModule/Msg/BaseMessage.h"
#include "MessageModule/Msg/MsgRequestBody.h"

#include "VisualModule/WindowFactory/WindowFactory.h"

using namespace std;

class test : public MsgClient
{
private:
    MsgCliName Recipient;
    std::chrono::milliseconds Duration;

public:
    test(MsgCliName NewRecipient, std::chrono::milliseconds NewDuration)
    { 
        Recipient = NewRecipient; 
        Duration = NewDuration;
    };
    ~test(){};

    void Test()
    {
        while(1)
        {
            for(int i = 0; i < 10; i++)
            {
                MessageRequest* mes = new MessageRequest(MSG_REQ_GET_0);

                mes->SetMessageSender(this->GetClientName());
                mes->SetMessageRecipient(Recipient);

                this->AddMessage(mes);
            }
            std::this_thread::sleep_for(Duration);
        }
    }

    MessageAnswer* MessageRecievedCallback(MessageRequest* MessageToReactTo) override
    {
        MessageAnswer* mes = new MessageAnswer();
        
        if(MessageToReactTo->GetMessageType() == MSG_TYPE_REQUEST)
        {
            cout << "got message from " << MessageToReactTo->GetMessageSender() << endl;
            mes->SetMessageSender(this->GetClientName());
            mes->SetMessageRecipient(MessageToReactTo->GetMessageSender());
        }

        delete(MessageToReactTo);
        return mes;
    }

    void HandleAnswer(MessageAnswer* AnswerToReactTo) override
    {
        cout << "got answer from " << AnswerToReactTo->GetMessageSender() << endl;
        delete(AnswerToReactTo);
    }
};

/*
    ThreadManager thrmgr;
    MsgQueue* msgqueue = new MsgQueue();
    MsgDistr* msgdistr = new MsgDistr;

    msgdistr->SetSharedMsgQueue(msgqueue);
    msgdistr->SetSharedMutex(thrmgr.GetSharedMutex());
    msgdistr->SetThreadClientTag("msg_distr");

    thrmgr.CreateNewThread(static_cast<ThrCliFuncType>(&MsgDistr::StartMessagingLoop), msgdistr, "");

    test* cli0 = new test(MSG_CLI_1, 10ms);
    cli0->SetSharedMutex(thrmgr.GetSharedMutex());
    cli0->SetSharedMsgQueue(msgqueue);
    cli0->SetClientName(MSG_CLI_0);
    cli0->SetClientTag("cli_0");
    cli0->SetThreadClientTag("cli_0");
    msgdistr->RegistrClient(static_cast<MsgClientInterface*>(cli0));
    thrmgr.CreateNewThread(static_cast<ThrCliFuncType>(&test::Test), cli0, "");

    test* cli1 = new test(MSG_CLI_0, 100ms);
    cli1->SetSharedMutex(thrmgr.GetSharedMutex());
    cli1->SetSharedMsgQueue(msgqueue);
    cli1->SetClientName(MSG_CLI_1);
    cli1->SetClientTag("cli_1");
    cli1->SetThreadClientTag("cli_1");
    msgdistr->RegistrClient(static_cast<MsgClientInterface*>(cli1));
    thrmgr.CreateNewThread(static_cast<ThrCliFuncType>(&test::Test), cli1, "");
*/

int main(int argc, char const* argv[])
{
    WindowFactory winfac;

    WindowInterface* basewin = winfac.CreateWindow(WIN_TYPE_MAIN);

    vector<Drawable*>* Obj = new vector<Drawable*>;

    int x(0), y(0);

    for(int i = 0; i < 100; i++)
    {
        RectangleShape* shape = new RectangleShape();

        shape->setFillColor(Color(255, 0, 0, 255));
        shape->setPosition(x, y);
        shape->setSize(Vector2f(10, 10));

        x+=10;
        if(x >= 1000)
        {
            x = 0; 
            y+=10;
        }

        Obj->push_back(shape);
    }

    basewin->SetObjectsToDraw(Obj);

    delete(Obj);

    while(basewin->IsWindowOpen())
    {
        basewin->DisplayWindow();
    }
}
