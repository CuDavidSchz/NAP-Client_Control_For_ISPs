//
//  Company.cpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 26/05/24.
//

#include "Company.h"
#include <iostream>
#include <string>
using namespace std;

Company::Company() : Client()
{
    // New
    companyName = "Set Company Name";
    techsupportad = false;
    
}
Company::Company(int _idc, std::string _serviceOwner, std::string _address, int _phoneNumber, float _fee, bool _status, int _bandwidth, std::string _companyName, bool _techsupportad) :

    Client(_idc, _serviceOwner, _address, _phoneNumber, _fee, _status, _status)
{
    
    //New
    companyName = _companyName;
    techsupportad = _techsupportad;
    
}

// New Getters

std::string Company::getCompanyName()
{
    return  this->companyName;
}
bool Company::getTechsupportad()
{
    return this->techsupportad;
}

//New Setters

void Company::setCompanyName(std::string _companyName)
{
    this->companyName = _companyName;
}

void Company::setTechsupportad(bool _techsupportad)
{
    this->techsupportad = _techsupportad;
}

// Additionals

void Company::showInfo()
{
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Información de la compañia: " << companyName << endl;
    cout << "Nombre de firmante: " << serviceOwner << endl;
    cout << "Estatus: " << status << endl;
    cout << "Ubicación: " << address << endl;
    cout << "Número de teléfono: " << phoneNumber << endl;
    cout << "Tarifa: " << fee << endl;
    cout << "Ancho de banda: " << bandwidth << endl;
    cout << "Acceso a soporte avanzado: " << techsupportad << endl;
    cout << "--------------------------" << endl;
    cout << endl;
}
