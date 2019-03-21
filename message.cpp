#include "message.h"
using namespace std;
message::message(string person, string platform, string identification, int messageNo, string mesg)
{
    sender = person;
    device = platform;
    id = identification;
    messageNum = messageNo;
    msg = mesg;
}

message::message()
{

}

message::~message()
{

}

string message::getSender() const
{
    return sender;
}

string message::getDevice() const
{
    return device;
}

string message::getId() const
{
    return id;
}

int message::getMessageNum() const
{
    return messageNum;
}

void message::setMsgNum(int num)
{
    this->messageNum = num;
}

string message::getMsg() const
{
    return msg;
}

ostream& operator<<(ostream& out, message* m)
{
    out << "Name: " <<  m->getSender() << endl; 
    out << "Device: " <<  m->getDevice() << endl; 
    out << "Contact Info: " << m->getId() << endl; 
    out << "Message Number: " << m->getMessageNum() << endl << endl; 
    out << "Message: " << m->getMsg() << endl << endl; 
    return out;
}

message& message::operator+ (string& append)
{
    this->msg.append(append);
    return *this;
}

void message::operator=(const message& toCopy)
{
    this->sender = toCopy.getSender(); 
    this->device = toCopy.getDevice(); 
    this->id = toCopy.getId(); 
    this->msg = toCopy.getMsg(); 
}

bool message::operator ==(const message& messageTwo)
{
   return this->sender == messageTwo.sender &&
          this->device == messageTwo.device &&
          this->id == messageTwo.id &&
          this->msg == messageTwo.msg;
}
