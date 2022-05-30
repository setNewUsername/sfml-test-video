#include <iostream>
#include "ThreadManager/ThreadManager.h"

#include "MessageModule/MsgDistr/MsgDistr.h"
#include "MessageModule/MsgClient/MsgClient.h"
#include "MessageModule/MsgClient/MsgClientName.h"

#include "MessageModule/Msg/BaseMessage.h"
#include "MessageModule/Msg/MsgRequestBody.h"

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

    MessageAnswer* ConstructAnswer(MessageRequest* MessageToAnswerTo)
    {
        MessageAnswer* Answer = nullptr;
        if(MessageToAnswerTo->GetMessageBody() == MSG_REQ_GET_0)
        {
            Answer = new MessageAnswer();
            Answer->SetMessageRecipient(MessageToAnswerTo->GetMessageSender());
            Answer->SetMessageSender(this->GetClientName());
        }
        delete(MessageToAnswerTo);
        return Answer;
    };

    void ReactToAnswer(MessageAnswer* AnswerToReactTo)
    {
        cout << "Got answer from " << AnswerToReactTo->GetMessageSender() << endl;
        delete(AnswerToReactTo);
    };

    void Test()
    {
        while(1)
        {
            MessageRequest* mes = new MessageRequest(MSG_REQ_GET_0);

            mes->SetMessageSender(this->GetClientName());
            mes->SetMessageRecipient(Recipient);

            this->AddMessage(mes);

            std::this_thread::sleep_for(Duration);
        }
    }
};

int main(int argc, char const* argv[])
{
    ThreadManager thrmgr;
    MsgDistr* msgdistr = new MsgDistr;

    msgdistr->SetSharedMutex(thrmgr.GetSharedMutex());
    msgdistr->SetThreadClientTag("msg_distr");

    thrmgr.CreateNewThread(static_cast<ThrCliFuncType>(&MsgDistr::StartMessagingLoop), msgdistr, "");

    test* cli0 = new test(MSG_CLI_1, 2000ms);

    cli0->SetSharedMutex(thrmgr.GetSharedMutex());

    cli0->SetClientName(MSG_CLI_0);
    cli0->SetClientTag("cli_0");
    cli0->SetThreadClientTag("cli_0");

    msgdistr->RegistrClient(static_cast<MsgClientInterface*>(cli0));

    test* cli1 = new test(MSG_CLI_0, 5000ms);

    cli1->SetSharedMutex(thrmgr.GetSharedMutex());

    cli1->SetClientName(MSG_CLI_1);
    cli1->SetClientTag("cli_1");
    cli1->SetThreadClientTag("cli_1");

    msgdistr->RegistrClient(static_cast<MsgClientInterface*>(cli1));

    thrmgr.CreateNewThread(static_cast<ThrCliFuncType>(&test::Test), cli0, "");
    thrmgr.CreateNewThread(static_cast<ThrCliFuncType>(&test::Test), cli1, "");

    while(1){}
}
