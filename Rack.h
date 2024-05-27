//
//  Rack.h
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 26/05/24.
//

#ifndef Rack_h
#define Rack_h
#include "NetworkElement.h"
#include <iostream>
#include <string>

class Rack : public NetworkElement
{
private:
    int rackUnits;
    
public:
    //Constructors
    Rack();
    Rack(int, std::string, std::string, std::string, std::string, std::string, int);
    
    //Getters
    int getRackUnits();
    
    //Setters
    void setRackUnits(int);
    
};


#endif /* Rack_h */
