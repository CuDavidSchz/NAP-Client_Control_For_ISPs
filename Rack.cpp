//
//  Rack.cpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 09/06/24.
//

#include "Rack.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//--------------------------------------------------------------------------------
                                // Constructors

    // Default
Rack::Rack() :
    BackboneElement() ,
    oltTechnology(0) ,
    splices(vector<Splice*>()) ,
    numFibersR(numberFibers)
{}

    //Parametrizado
Rack::Rack(string ID, string status, string location, string manufacturer, string model, int numberFibers, int oltTechnology, vector<Splice*> splices) :

    BackboneElement(ID, status, location, manufacturer, model, numberFibers) ,
    oltTechnology(oltTechnology) ,
    splices(splices) 
{}

//--------------------------------------------------------------------------------
                                // Getters

int Rack::getOltTechnology()
{
    return this-> oltTechnology;
}

vector<Splice*> Rack::getSplices()
{
    return this-> splices;
}

int Rack::getNumberFibersR()
{
    return this-> numFibersR;
}

//--------------------------------------------------------------------------------
                                // Setters

void Rack::setOltTechnology(int oltTechnology)
{
    this-> oltTechnology = oltTechnology;
}
           
//--------------------------------------------------------------------------------
                                // Additionals

int Rack::calculateNumberFibersR()
{
    int usedFibers = 0;
    for (Splice* splice : splices)
    {
        usedFibers += splice->getNumberFibers();
    }
    int remainingFibers;
    remainingFibers = this->numberFibers - usedFibers;
    
    return remainingFibers;
    
}

int Rack::calculateTotalClients()
{
    int totalClients = 0;
    for (Splice* splice : splices)
    {
        for (Nap* nap : splice->getNaps())
        {
            totalClients += nap->getClients().size();
        }
    }
    return totalClients;
}

int Rack::calculateTotalNaps()
{
    int totalNaps = 0;
    for (Splice* splice : splices)
    {
        totalNaps += splice->getNaps().size();
    }
    return totalNaps;
}

void Rack::addSplice(Splice* splice)
{
    this-> splices.push_back(splice);
}

void Rack::showInfo()
{
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Información del Rack: " << ID << endl;
    cout << "Satus: " << status << endl;
    cout << "Location: " << location << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Model: " << model << endl;
    cout << "Fibras totales: " << numberFibers << endl;
    cout << "Fibras disponibles: " << numberFibers << endl;
    cout << "Cierres de empalme: " << this->splices.size() << endl;
    cout << "Total Naps: " << this->calculateTotalNaps() << endl;
    cout << "Clientes: " << this->calculateTotalClients() <<endl;
    cout << "--------------------------" << endl;
    cout << endl;

}

int Rack::getClientCount()  const
{
    int totalClients = 0;
    for (const Splice* splice : splices)
    {
        totalClients += splice->getClientCount();
    }
    return totalClients;
}
