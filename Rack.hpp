//
//  Rack.hpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 09/06/24.
//

#ifndef Rack_hpp
#define Rack_hpp
#include "BackboneElement.h"
#include "Splice.h"
#include <iostream>
#include <string>
#include <vector>
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
    Rack(string, string, string, string, string, int, int, vector<Splice*>);
    
    //Getters
    int getOltTechnology();
    vector<Splice*> getSplices();
    int getNumberFibersR();
    
    
    //Setters
    void setOltTechnology(int);
    
    //Additionals
    
    int calculateNumberFibersR();
    int calculateTotalClients();
    int calculateTotalNaps();
    
    void addSplice(Splice*);
    void showInfo() override;
    int getClientCount() const override;
};


#endif /* Rack_h */
