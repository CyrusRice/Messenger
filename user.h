#include <vector>
#include <string>
#include <set>
#include "email.h"
#include "facebook.h"
#include "text.h"
using namespace std;
struct contact
{
    string name;
    char tag;
    string info;
    int index;
};
class user
{
public:
    user();
    user(const user* toCopy);
    ~user();
    void send(string name, string tag, string user, string mesg, int messageNumber);
    void checkInbox();
    void checkOutbox();
    void read(string mailType, int index);
    void addContact(string name, char tag, string info);
    void addIncomingMessage(message* msg);
    void addToOutgoing(int messageNo, string newStr); 
    void copyMessage(string mailType, int msgNo);
    void checkEqual(string mailType, int msgNo1, int msgNo2);
    void printContactList();
    void operator=(const user* toCopy);


private:
    set<message*> inbox;
    set<message*> outbox;
    set<message*>::iterator it;
    vector<contact*> contactList; 
};
