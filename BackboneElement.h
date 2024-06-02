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
    int idBE;
    int numberFibers;
    
public:
                            //Constructors
    BackboneElement();
    BackboneElement(std::string, std::string, std::string, std::string, std::string, int, int);
    
                            //Getters
    int getNumberFibers();
    int getID() override;
    
                            //Settters
    void setNumberFibers(int);
    void setID(int) override;
};

#endif /* BackboneElement_h */
