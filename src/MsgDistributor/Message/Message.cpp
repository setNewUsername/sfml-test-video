#include "Message.h"

Message::Message(MsgBodyEnum NewMessageToRecipient, MsgCliEnum NewRecipient)
{
    MessageToRecipient = NewMessageToRecipient;
    Recipient = NewRecipient;
}

Message::~Message()
{
}

MsgBodyEnum Message::GetMessageBody()
{
    return MessageToRecipient;
}

MsgCliEnum Message::GetMsgRecipient()
{
    return Recipient;
}