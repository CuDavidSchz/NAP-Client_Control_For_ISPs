//
//  Domestic.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Domestic_h
#define Domestic_h
#include <iostream>
#include <string>
#include "Client.h"

class Domestic : public Client {
public:
    Domestic();
    Domestic(int, std::string, std::string, int, float, bool, int);
};

#endif /* Domestic_h */
