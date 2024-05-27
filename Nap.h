//
//  Nap.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Nap_h
#define Nap_h
#include "NetworkElement.h"
#include <iostream>
#include <string>

class Nap : public NetworkElement
{
private:
    int capacity;
    
public:
    //Constructors
    Nap();
    Nap(int, std::string, std::string, std::string, std::string, std::string, int);
    
    //Getters
    int getCapacity();
    
    //Setters
    void setCapacity(int);
    
};

#endif /* Nap_h */
