//
//  BackboneElement.h
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 01/06/24.
//

#ifndef BackboneElement_h
#define BackboneElement_h

#include "NetworkElement.h"
#include <iostream>
#include <vector>
#include <string>

class BackboneElement : public NetworkElement
{
protected:
    int numberFibers;
    
public:
                            //Constructors
    BackboneElement();
    BackboneElement(std::string, std::string, std::string, std::string, std::string, int);
    
                            //Getters
    int getNumberFibers();
    
                            //Settters
    void setNumberFibers(int);
    
                            // Additionals
    

};

#endif /* BackboneElement_h */
