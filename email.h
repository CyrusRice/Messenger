#ifndef EMAIL_H
#define EMAIL_H
#include "message.h"
class email : public message
{
public:
    email(string name,string type, string identification, int messagNo, string messag);
    ~email();
    

private:

};
#endif
