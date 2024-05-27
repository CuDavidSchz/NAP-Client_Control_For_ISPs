//
//  Splice.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Splice_h
#define Splice_h
#include "NetworkElement.h"
#include <iostream>
#include <string>

class Splice : public NetworkElement
{
private:
    int capacity;
    std::string level;
    
public:
    //Constructors
    Splice();
    Splice(int, std::string, std::string, std::string, std::string, std::string, int, std::string);
    
    //Getters
    int getCapacity();
    std::string getLevel();
    
    //Setters
    void setCapacity(int);
    void setLevel(std::string);
    
};



#endif /* Splice_h */
