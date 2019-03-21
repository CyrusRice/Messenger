#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <iostream>
using namespace std;
class message
{
public:
    message(string person, string platform, string identification, int messageNo, string mesg);
    message();
    ~message();
    string getSender() const;
    string getDevice() const;
    string getId() const;
    int getMessageNum() const;
    int getContactNum() const;
    string getMsg() const; 
    void setMsgNum(int num);
    friend ostream& operator<<(ostream& out, message* m);
    message& operator+ (string& append);
    void operator=(const message& toCopy);
    bool operator ==(const message& messageTwo);

private:
    string sender;
    string device;
    string id;
    int messageNum;
    string msg;

};
#endif
