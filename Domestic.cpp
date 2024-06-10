//
//  Domestic.cpp
//  ProjectNAP_Client_Control_Classes
//
//

#include "Domestic.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constructors

        //Default
Domestic::Domestic() : Client() {}

        //Parametrizado
Domestic::Domestic(int _idc, std::string _serviceOwner, std::string _address, int _phoneNumber, float _fee, bool _status, int _bandwidth) :

    Client(_idc, _serviceOwner, _address, _phoneNumber, _fee, _status, _bandwidth)
{}

// Additionals

void Domestic::showInfo()
{
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Información del cliente: " << serviceOwner << endl;
    cout << "Estatus: " << status << endl;
    cout << "Ubicación: " << address << endl;
    cout << "Número de teléfono: " << phoneNumber << endl;
    cout << "Tarifa: " << fee << endl;
    cout << "Ancho de banda: " << bandwidth << endl;
    cout << "--------------------------" << endl;
    cout << endl;

}
