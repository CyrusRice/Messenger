#ifndef TEXT_H
#define TEXT_H
#include "message.h"
class text : public message
{
public:
    text(string name,string type, string identification, int messagNo, string messag);
    ~text();
    

private:

};
#endif
