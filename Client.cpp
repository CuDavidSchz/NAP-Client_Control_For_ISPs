//
//  Client.cpp
//  ProjectNAP_Client_Control_Classes
//
//

#include "Client.h"
#include <iostream>
#include <string>

//Constructors

Client::Client()
{
    idc = 0;
    serviceOwner = "Set Name";
    address = "Set Address";
    phoneNumber = 0;
    fee = 0.0;
    status = false;
    bandwidth = 10;
}
Client::Client(int _idc, std::string _serviceOwner, std::string _address, int _phoneNumber, float _fee, bool _status, int _bandwidth)
{
    idc = _idc;
    serviceOwner = _serviceOwner;
    address = _address;
    phoneNumber = _phoneNumber;
    fee = _fee;
    status = _status;
    bandwidth = _bandwidth;
}


//Getters

int Client::getIDC() const
{
    return idc;
}
std::string Client::getServiceOwner() const
{
    return serviceOwner;
}
std::string Client::getAddress() const
{
    return address;
}
int Client::getPhoneNumber() const
{
    return phoneNumber;
}
float Client::getFee() const
{
    return fee;
}
bool Client::getStatus() const
{
    return status;
}
int Client::getBandwidth() const
{
    return bandwidth;
}

//Setters

void Client::setIDC(int _idc)
{
    idc = _idc;
}

void Client::setServiceOwner(std::string _serviceOwner)
{
    serviceOwner = _serviceOwner;
}

void Client::setAddress(std::string _address)
{
    address = _address;
}

void Client::setPhoneNumber(int _phoneNumber)
{
    phoneNumber = _phoneNumber;
}

void Client::setFee(float _fee)
{
    fee = _fee;
}

void Client::setStatus(bool _status)
{
    status = _status;
}

void Client::setBandwidth(int _bandwidth)
{
    bandwidth = _bandwidth;
}

