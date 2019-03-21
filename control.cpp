#include "control.h"
#include <iostream>
using namespace std;
control::control()
{

}

control::~control()
{
    delete myUser;
}

void control::start()
{
    email* incomingOne = new email("Jim Smith", "Text", "503-456-9708", 1, "Hey I got those reports man, thanks" );
    facebook* incomingTwo = new facebook("Thomas Sardinsky", "Facebook", "TSardine", 2, "What's up man, haven't seen you in a while?");
    text* incomingThree = new text("Jeff Klienerman", "Email", "JKleinerman@gmail.com", 3, "Hey so we are going to be having a meeting on Friday at noon, please reply to this email if you can make it, thanks.");
    myUser = new user();
    myUser->addIncomingMessage(incomingOne);
    myUser->addIncomingMessage(incomingTwo);
    myUser->addIncomingMessage(incomingThree);
    string first;
    cout << "----------Welcome to your messaging service------------------------------------" << endl
         << "-input the following key to do the corresponding task--------------------------" << endl
         << "Check mail: c" << endl
         << "Read message: r" << endl
         << "Send message: s" << endl
         << "Add contact: a" << endl
         << "Copy message: C" << endl
         << "Check if 2 messages are equal: e" << endl
         << "Add to outgoing message: A" << endl
         << "Display contacts list: t" << endl
         << "Quit: q" << endl;
    getline(cin, first);
    while(first != "q")
    {
        if(first == "c")
        {
            cout << "enter i for inbox, o for outbox: " << endl;
            getline(cin, first);
            if(first == "i")
            {
                myUser->checkInbox(); 
            } else if(first == "o")
            {
                myUser->checkOutbox();
            } else
            {
                cout << "Invalid input" << endl;
            }
        } else if(first == "r")
        {
            int index;
            cout << "enter i for inbox, o for outbox: " << endl;
            getline(cin, first);
            if(first == "i")
            {
                cout << "Enter message number: " << endl;
                cin >> index;
                cin.ignore(256, '\n');
                myUser->read("inbox",index); 
            } else if(first == "o")
            {
                cout << "Enter message number: " << endl;
                cin >> index;
                cin.ignore(256, '\n');
                myUser->read("outbox",index); 
            } else
            {
                cout << "Invalid input" << endl;
            }
        } else if(first == "s")
        {
            string person;
            string msgType;
            string info;
            string messg;
            int messNo;
            cout << "Enter recipients name: " << endl;
            getline(cin, person);
            cout << "Enter message type: " << endl;
            getline(cin, msgType);
            cout << "Enter account name/phone number: " << endl;
            getline(cin, info);
            cout << "Enter the message on one line: " << endl;
            getline(cin, messg);
            cout << "Enter the message number: " << endl;
            cin >> messNo;
            cin.ignore(256, '\n');
            myUser->send(person, msgType, info, messg, messNo);

        } else if(first == "a")
        {
            string person;
            char tag;
            string info;
            cout << "Enter recipients name: " << endl;
            getline(cin, person);
            cout << "Enter tag (T for text, F for facebook, E for email): " << endl;
            cin.get(tag);
            cin.ignore(256, '\n');
            cout << "Enter account name/phone number: " << endl;
            getline(cin, info);
            myUser->addContact(person, tag, info);
            cout << "Successfully added " << person << " to contacts list" << endl;
        } else if(first == "C")
        {
            int index;
            cout << "enter i for inbox, o for outbox: " << endl;
            getline(cin, first);
            if(first == "i")
            {
                cout << "Enter number of message in inbox to be copied: " << endl;
                cin >> index;
                cin.ignore(256, '\n');
                myUser->copyMessage("inbox", index);
            } else if(first == "o")
            {
                cout << "Enter number of message in outbox to be copied: " << endl;
                cin >> index;
                cin.ignore(256, '\n');
                myUser->copyMessage("outbox", index);
            } else
            {
                cout << "Invalid input" << endl;
            }
        } else if(first == "e")
        {
            cout << "enter i for inbox, o for outbox: " << endl;
            getline(cin, first);
            if(first == "i")
            {
                int msg1, msg2;
                cout << "Enter number of message one to check for equality: " << endl;
                cin >> msg1;
                cin.ignore(256, '\n');
                cout << "Enter number of message two to check for equality: " << endl;
                cin >> msg2;
                cin.ignore(256, '\n');
                myUser->checkEqual("inbox", msg1, msg2);
            } else if(first == "o")
            {
                int msg1, msg2;
                cout << "Enter number of message one to check for equality: " << endl;
                cin >> msg1;
                cin.ignore(256, '\n');
                cout << "Enter number of message two to check for equality: " << endl;
                cin >> msg2;
                cin.ignore(256, '\n');
                myUser->checkEqual("outbox", msg1, msg2);
            } else
            {
                cout << "Invalid input" << endl;
            }
        } else if(first == "A")
        {
            int msgNo;
            string messg;
            cout << "Enter number of message to add to: " << endl;
            cin >> msgNo;
            cin.ignore(256, '\n');
            cout << "Enter the string to add on one line: " << endl;
            getline(cin, messg);
            myUser->addToOutgoing(msgNo, messg);
        } else if(first == "q")
        {
            return;
        } else if(first == "t")
        {
            myUser->printContactList();            
        } else
        {
            cout << first << "is an Invalid request, try again" << endl;
        }
        cout << "-input the following key to do the corresponding task--------------------------" << endl
             << "Check mail: c" << endl
             << "Read message: r" << endl
             << "Send message: s" << endl
             << "Add contact: a" << endl
             << "Copy message: C" << endl
             << "Check if 2 messages are equal: e" << endl
             << "Add to outgoing message: A" << endl
             << "Display contacts list: t" << endl
             << "Quit: q" << endl;
        getline(cin, first);
    }
}
