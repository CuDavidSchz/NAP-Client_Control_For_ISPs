//
//  BackboneElement.cpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 01/06/24.
//

#include "BackboneElement.h"
#include <iostream>
#include <vector>
#include <string>

                    //Constructors
    // Default
BackboneElement::BackboneElement() : NetworkElement()
{
    this-> numberFibers = 0;
}
    // Parametrized
BackboneElement::BackboneElement(std::string _ID, std::string _status, std::string _location, std::string _manufacturer, std::string _model, int _numberfibers) :
    
    NetworkElement(_ID,_status,_location,_manufacturer,_model) ,
    numberFibers(_numberfibers)
{}

                    //Getters

int BackboneElement::getNumberFibers()
{
    return numberFibers;
}

                    //Setters
void BackboneElement::setNumberFibers(int _numberfibers)
{
    this-> numberFibers = _numberfibers;
}

