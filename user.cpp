#include <iostream>
#include "user.h"
using namespace std;
user::user()
{

}
user::user(const user* toCopy)
{
    for(unsigned int i = 0; i < toCopy->contactList.size(); i++)
    {
        contactList[i] = new contact;
        contactList[i]->name = toCopy->contactList[i]->name;
        contactList[i]->tag = toCopy->contactList[i]->tag;
        contactList[i]->info = toCopy->contactList[i]->info;
        contactList[i]->index = toCopy->contactList[i]->index;
    }

    for(it = toCopy->inbox.begin(); it != toCopy->inbox.end(); ++it)
    {
        message* toInsert = new message;
        *toInsert = *(*(toCopy->it)); 
        inbox.insert(toInsert);
    }

    for(it = toCopy->outbox.begin(); it != toCopy->outbox.end(); ++it)
    {
        message* toInsert = new message;
        *toInsert = *(*(toCopy->it)); 
        outbox.insert(toInsert);
    }
}

void user::operator=(const user* toCopy)
{
    for(unsigned int i = 0; i < toCopy->contactList.size(); i++)
    {
        contactList[i] = new contact;
        contactList[i]->name = toCopy->contactList[i]->name;
        contactList[i]->tag = toCopy->contactList[i]->tag;
        contactList[i]->info = toCopy->contactList[i]->info;
        contactList[i]->index = toCopy->contactList[i]->index;
    }

    for(it = toCopy->inbox.begin(); it != toCopy->inbox.end(); ++it)
    {
        message* toInsert = new message;
        *toInsert = *(*(toCopy->it)); 
        inbox.insert(toInsert);
    }

    for(it = toCopy->outbox.begin(); it != toCopy->outbox.end(); ++it)
    {
        message* toInsert = new message;
        *toInsert = *(*(toCopy->it)); 
        outbox.insert(toInsert);
    }
}

user::~user()
{
    for(unsigned int i = 0; i < contactList.size(); i++)
    {
        delete contactList[i]; 
    }

    for(it = inbox.begin(); it != inbox.end(); ++it)
    {
        delete *it;
    }

    for(it = outbox.begin(); it != outbox.end(); ++it)
    {
        delete *it;
    }
}

void user::send(string name, string tag, string user, string mesg, int messageNumber)
{
    message* outGoing = new message(name, tag, user, messageNumber, mesg);
    outbox.insert(outGoing);
    cout << "Successfully sent message to " << name << "'s " 
         << tag << ": " << user << endl;
}

void user::checkOutbox()
{
    cout << "-------Outbox--------" << endl;
    for(it = outbox.begin(); it != outbox.end(); ++it)
    {
        cout << "Name: " <<  (*it)->getSender() << endl; 
        cout << "Device: " <<  (*it)->getDevice() << endl; 
        cout << "Contact Info: " << (*it)->getId() << endl; 
        cout << "Message Number: " << (*it)->getMessageNum() << endl << endl; 
    }
    cout << "---------------------" << endl;
}

void user::checkInbox()
{
    cout << "-------Inbox--------" << endl;
    for(it = inbox.begin(); it != inbox.end(); ++it)
    {
        cout << "Name: " <<  (*it)->getSender() << endl; 
        cout << "Device: " <<  (*it)->getDevice() << endl; 
        cout << "Contact Info: " << (*it)->getId() << endl; 
        cout << "Message Number: " << (*it)->getMessageNum() << endl << endl; 
    }
    cout << "---------------------" << endl;
}

void user::read(string mailType, int index)
{
    if(mailType == "inbox")
    {
        it = inbox.begin();
        while(it != inbox.end())
        {
            if((*it)->getMessageNum() == index)
            {
                message* toRead = *it;
                cout << toRead;
                return;
            } else
            {
                it++;
            }
        }
        cout << "Invalid message number" << endl;
    } else if(mailType == "outbox")
    {
        it = outbox.begin();
        while(it != outbox.end())
        {
            if((*it)->getMessageNum() == index)
            {
                message* toRead = *it;
                cout << toRead;
                return;
            } else
            {
                it++;
            }
        }
        cout << "Invalid message number" << endl;
    } 
}

void user::addContact(string name, char tag, string info)
{
    contact* newContact = new contact;
    newContact->name = name;
    newContact->tag = tag;
    newContact->info = info;
    newContact->index = contactList.size();
    contactList.push_back(newContact);
}

void user::addIncomingMessage(message* msg)
{
    inbox.insert(msg);
}

void user::addToOutgoing(int messageNo, string newStr)
{
    it = outbox.begin();
    while(it != outbox.end())
    {
        if((*it)->getMessageNum() == messageNo)
        {
            message* toRead = *it;
            *toRead = *toRead + newStr;
            cout << "Successfully appended to message " << messageNo << " of outbox" << endl;
            return;
        } else
        {
            it++;
        }
    }
    cout << "Invalid message number" << endl;
}

void user::copyMessage(string mailType, int msgNo)
{
    if(mailType == "outbox")
    {
        it = outbox.begin();
        while(it != outbox.end())
        {
            if((*it)->getMessageNum() == msgNo)
            {
                message* newMsg = new message();
                *newMsg = *(*it);
                newMsg->setMsgNum(outbox.size() + 1);
                outbox.insert(newMsg);
                cout << "Made copy of message " << msgNo << " in outbox" << endl;
                return;
            } else
            {
                it++;
            }
        }
        cout << "Invalid message number" << endl;
    } else if(mailType == "inbox")
    {
        it = inbox.begin();
        while(it != inbox.end())
        {
            if((*it)->getMessageNum() == msgNo)
            {
                message* newMsg = new message();
                *newMsg = *(*it);
                newMsg->setMsgNum(outbox.size() + 1);
                inbox.insert(newMsg);
                cout << "Made copy of message " << msgNo << " in inbox" << endl;
                return;
            } else
            {
                it++;
            }
        }
        cout << "Invalid message number" << endl;
    } 
}

void user::checkEqual(string mailType, int msgNo1, int msgNo2)
{
    message* msg1 = new message();
    message* msg2 = new message();
    if(mailType == "outbox")
    {
        bool flag = true;
        it = outbox.begin();
        while(it != outbox.end() && flag)
        {
            if((*it)->getMessageNum() == msgNo1)
            {
                msg1 = *it;
                flag = false;
            } else
            {
                ++it;;
            }
        }
        if(flag)
        {
            cout << "Invalid message number" << endl;
            return;
        }
        it = outbox.begin();
        flag = true;
        while(it != outbox.end() && flag)
        {
            if((*it)->getMessageNum() == msgNo2)
            {
                msg2 = *it;
                flag = false;
            } else
            {
                it++;
            }
        }
        if(flag)
        {
            cout << "Invalid message number" << endl;
            return;
        }
        if(*msg2 == *msg1)
        {
            cout << "message " << msg1->getMessageNum() 
                 << " is identical to message " << msg2->getMessageNum() << endl;
        } else
        {
            cout << "message " << msg1->getMessageNum() 
                 << " is not identical to message " << msg2->getMessageNum() << endl;
        }
    } else if(mailType == "inbox")
    {
        bool flag = true;
        it = inbox.begin();
        while(it != inbox.end() && flag)
        {
            if((*it)->getMessageNum() == msgNo1)
            {
                msg1 = *it;
                flag = false;
            } else
            {
                it++;
            }
        }
        if(flag)
        {
            cout << "Invalid message number" << endl;
            return;
        }
        it = inbox.begin();
        flag = true;
        while(it != inbox.end() && flag)
        {
            if((*it)->getMessageNum() == msgNo2)
            {
                msg2 = *it;
                flag = false;
            } else
            {
                it++;
            }
        }
        if(flag)
        {
            cout << "Invalid message number" << endl;
            return;
        }
        if(*msg2 == *msg1)
        {
            cout << "message " << msg1->getMessageNum() 
                 << " is identical to message " << msg2->getMessageNum() << endl;
        } else
        {
            cout << "message " << msg1->getMessageNum() 
                 << " is not identical to message " << msg2->getMessageNum() << endl;
        }
    } 
}

void user::printContactList()
{
    cout << "--------Contact List-----------" << endl;
    for(unsigned int i = 0; i < contactList.size(); i++)
    {
        cout << "Name: " << contactList[i]->name << endl;
        cout << "Tag: " << contactList[i]->tag << endl;
        cout << "Info: " << contactList[i]->info << endl;
        cout << "Contact Number: " << contactList[i]->index << endl << endl;
    }
}
