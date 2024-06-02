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
BackboneElement::BackboneElement(){
    name = "Default";
    status = "Not specified";
    location = "Insert URL location";
    manufacturer = "Not specified";
    model = "Not specified";
    
    idBE = 0;
    numberFibers = 0;
}

BackboneElement::BackboneElement(std::string _name, std::string _status, std::string _location, std::string _manufacturer, std::string _model, int _idBE, int _numberfibers)
{
    name = _name;
    status = _status;
    location = _location;
    manufacturer = _manufacturer;
    model = _model;
    
    idBE = _idBE;
    numberFibers = _numberfibers;
}

                    //Getters

int BackboneElement::getNumberFibers()
{
    return numberFibers;
}

int BackboneElement::getID()
{
    return idBE;
}

                    //Setters
void BackboneElement::setNumberFibers(int _numberfibers)
{
    this-> numberFibers = _numberfibers;
}
void BackboneElement::setID(int _idBE)
{
    this-> idBE = _idBE;
}
