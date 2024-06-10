//
//  Rack.h
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 26/05/24.
//

#ifndef Rack_h
#define Rack_h
#include "BackboneElement.h"
#include "Splice.h"
#include <iostream>
#include <string>
using namespace std;

class Rack : public BackboneElement
{
private:
    int oltTechnology;
    vector<Splice*> splices;
    int numFibersR; // Fibras restantes para uso
    
public:
    //Constructors
    Rack();
    Rack(string, string, string, string, string, string, int);
    
    //Getters
    int getRackUnits();
    
    //Setters
    void setRackUnits(int);
    
};


#endif /* Rack_h */
