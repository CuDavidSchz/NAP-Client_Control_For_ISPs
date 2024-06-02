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
                //Default
NetworkElement::NetworkElement()
{
    
    name = "Set Name";
    status = "Not set";
    location = "Set Location";
    manufacturer = "Set manufacturer";
    model = "Set model";
    
}
                
                //Parameterized
NetworkElement::NetworkElement(std::string _name, std::string _status, std::string _location, std::string _manufacturer, std::string _model)
{
    name = _name;
    status = _status;
    location = _location;
    manufacturer = _manufacturer;
    model = _model;
}

                                //Getters


std::string NetworkElement::getName() const
{
    return name;
}
std::string NetworkElement::getStatus() const
{
    return status;
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



                            //Setters
        
void NetworkElement::setName(std::string _name)
{
    this-> name = _name;
}
void NetworkElement::setStatus(std::string _status)
{
    this-> status = _status;
}
void NetworkElement::setLocation(std::string _location)
{
    this-> location = _location;
}
void NetworkElement::setManufacturer(std::string _manufacturer)
{
    this-> manufacturer = _manufacturer;
}
void NetworkElement::setModel(std::string _model)
{
    this-> model = _model;
}

