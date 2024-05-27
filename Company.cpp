//
//  Company.cpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 26/05/24.
//

#include "Company.h"
#include <iostream>
#include <string>

Company::Company()
{
    idc = 0;
    serviceOwner = "Set Name";
    address = "Set Address";
    phoneNumber = 0;
    fee = 0.0;
    status = false;
    bandwidth = 10;
    
    //New
    companyName = "Set Company Name";
    techsupportad = false;
    
}
Company::Company(int _idc, std::string _serviceOwner, std::string _address, int _phoneNumber, float _fee, bool _status, int _bandwidth, std::string _companyName, bool _techsupportad)
{
    idc = _idc;
    serviceOwner = _serviceOwner;
    address = _address;
    phoneNumber = _phoneNumber;
    fee = _fee;
    status = _status;
    bandwidth = _bandwidth;
    
    //New
    companyName = _companyName;
    techsupportad = _techsupportad;
}

// New Getters

std::string Company::getCompanyName()
{
    return  companyName;
}
bool Company::getTechsupportad()
{
    return techsupportad;
}

//New Setters

void Company::setCompanyName(std::string _companyName)
{
    companyName = _companyName;
}

void Company::setTechsupportad(<#bool#> _techsupportad)
{
    techsupportad = _techsupportad;
}
