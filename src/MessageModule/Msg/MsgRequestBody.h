#pragma once 
#ifndef MSGREQUESTBODY_H
#define MSGREQUESTBODY_H

enum MsgRequestBody
{
    MSG_REQ_NONE = -1,
    MSG_REQ_GET_0,
    MSG_REQ_GET_1
};

enum MsgType
{
    MSG_TYPE_NONE = -1,
    MSG_TYPE_REQUEST,
    MSG_TYPE_ANSWER
};

#endif