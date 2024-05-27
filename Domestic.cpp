//
//  Domestic.cpp
//  ProjectNAP_Client_Control_Classes
//
//

#include "Domestic.h"
#include <iostream>
#include <string>

//Constructors

Domestic::Domestic()
{
    idc = 0;
    serviceOwner = "Set Name";
    address = "Set Address";
    phoneNumber = 0;
    fee = 0.0;
    status = false;
    bandwidth = 10;
}

Domestic::Domestic(int _idc, std::string _serviceOwner, std::string _address, int _phoneNumber, float _fee, bool _status, int _bandwidth)
{
    idc = _idc;
    serviceOwner = _serviceOwner;
    address = _address;
    phoneNumber = _phoneNumber;
    fee = _fee;
    status = _status;
    bandwidth = _bandwidth;
}
