//
//  NetworkElement.cpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 26/05/24.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "NetworkElement.h"


//Constructors
NetworkElement::NetworkElement()
{
    idNE = 0;
    name = "Set Name";
    location = "Set Location";
    manufacturer = "Set manufacturer";
    model = "Set model";
    status = false;
    numberFibers = 0;
}

NetworkElement::NetworkElement(int _idNE, std::string _name, std::string _location, std::string _manufacturer, std::string _model, bool _status, int _numeberFibers)
{
    idNE = _idNE;
    name = _name;
    location = _location;
    manufacturer = _manufacturer;
    model = _model;
    status = _status;
    numberFibers = _numeberFibers;
}

//Getters

int NetworkElement::getIDNE() const
{
    return idNE;
}
std::string NetworkElement::getName() const
{
    return name;
}
std::string NetworkElement::getLocation() const
{
    return location;
}
std::string NetworkElement::getManufacturer() const
{
    return manufacturer;
}
std::string NetworkElement::getModel() const
{
    return model;
}
bool NetworkElement::getStatus() const
{
    return status;
}
int NetworkElement::getnumberFibers() const
{
    return numberFibers;
}

//Setters

void NetworkElement::setIDNE(int _idNE)
{
    idNE = _idNE;
}
void NetworkElement::setName(std::string _name)
{
    name = _name;
}
void NetworkElement::setLocation(std::string _location)
{
    location = _location;
}
void NetworkElement::setManufacturer(std::string _manufacturer)
{
    manufacturer = _manufacturer;
}
void NetworkElement::setModel(std::string _model)
{
    model = _model;
}
void NetworkElement::setStatus(bool _status)
{
    status = _status;
}
void NetworkElement::setNumberFibers(int _numberFibers)
{
    numberFibers = _numberFibers;
}
