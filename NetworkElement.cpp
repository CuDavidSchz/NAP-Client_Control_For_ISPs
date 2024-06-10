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
    
    ID = "Set ID";
    status = "Not set";
    location = "Set Location";
    manufacturer = "Set manufacturer";
    model = "Set model";
    
}
                
                //Parameterized
NetworkElement::NetworkElement(std::string _ID, std::string _status, std::string _location, std::string _manufacturer, std::string _model)
{
    ID = _ID;
    status = _status;
    location = _location;
    manufacturer = _manufacturer;
    model = _model;
}

                                //Getters


std::string NetworkElement::getID() const
{
    return this->ID;
}
std::string NetworkElement::getStatus() const
{
    return this->status;
}
std::string NetworkElement::getLocation() const
{
    return this->location;
}
std::string NetworkElement::getManufacturer() const
{
    return this->manufacturer;
}
std::string NetworkElement::getModel() const
{
    return this->model;
}



                            //Setters
        
void NetworkElement::setID(std::string _ID)
{
    this-> ID = _ID;
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

