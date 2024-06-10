//
//  Splice.cpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 08/06/24.
//


#include "Splice.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//--------------------------------------------------------------------------------
                                // Constructors
    //Default
Splice::Splice() :
    BackboneElement() ,
    naps(vector<Nap*>()) ,
    maxClients(0) ,
    maxClientsR(0)
{}
    // Parametirezed
Splice::Splice(string ID, string status, string location, string manufacturer, string model, int numberFibers, vector<Nap*> naps, int maxClients, int maxClientsR) :

    BackboneElement(ID, status, location, manufacturer, model, numberFibers) ,
    naps(naps) ,
    maxClients(maxClients) ,
    maxClientsR(maxClientsR)
{}

//--------------------------------------------------------------------------------
                                    // Getters

int Splice::getMaxClients()
{
    return this-> maxClients;
}

int Splice::getMaxClientsR()
{
    return this-> maxClientsR;
}

vector<Nap*> Splice::getNaps()
{
    return naps;
}

//--------------------------------------------------------------------------------
                                    // Setters


void Splice::setMaxClients(int oltTechnology)
{
    this->maxClients = oltTechnology * this->numberFibers;
}

//--------------------------------------------------------------------------------
                                    // Adittionals

void Splice::addNap(vector<Nap*> naps)
{
    for (Nap* nap : naps)
    {
        this->naps.push_back(nap);
    }
}

vector<Nap*> Splice::addNap(int maxClients)
{
    int napCapacity; // Variable para almacenar capacidad de cada NAP
    while (true) // Pregunta la capacidad de todas las NAPs
    {
        cout << "Ingrese la capacidad de clientes para cada NAP (8,16,32): ";
        cin >> napCapacity;
        if (napCapacity == 8 || napCapacity == 16 || napCapacity == 32)
        {
            break;
        }
        else
        {
            cout << "Respuesta no válida. Por favor, ingrese 8, 16 o 32." << endl;
        }
    }
    int maxNaps = maxClients / napCapacity;
    int numNaps; // Variable para almacenar el número de NAPs deseado

    cout << "Según su capacidad deseada, el número de NAPs MÁXIMO posible es " << maxNaps << endl;

    while (true) // Validación de número de NAPs deseado
    {
        cout << "Ingrese el número de NAPs que desea agregar: ";
        cin >> numNaps;
        if (numNaps > 0 && numNaps <= maxNaps)
        {
        break;
        }
        else
        {
        cout << "Número de NAPs no válido. Por favor, ingrese un número entre 1 y " << maxNaps << "." << endl;
        }
    }
    // Banco de variables de constructor
    string IDbase, status, location, manufacturer, model;
    vector<Client*> emptyClients; // Todas las NAP inician vacias de clientes
    vector<Nap*> naps;
    
    
    
    char allSame; // Variable para almacenar si todas las NAPs son iguales
    while (true) // Pregunta si todas las naps son iguales
    {
        cout << "¿Todas las NAPs serán iguales? (S/N): ";
        cin >> allSame;
        if (allSame == 's' || allSame == 'S' || allSame == 'n' || allSame == 'N')
        {
            break;
        }
        else
        {
            cout << "Respuesta no válida. Por favor, ingrese 'S' o 'N'." << endl;
        }
    }
    // Variables limitantes
    if (allSame == 's' || allSame == 'S')
    {
        cout << "Ingrese la información para las NAPs" << endl;
        cout << "Se recomienda usar un mismo ID para la misma familia de NAPs. Ejemplo AA - 0X." << endl;
        cout << "ID base (ejemplo AA): ";
        cin >> IDbase;
        cout << "Status (Activo / Inactivo): ";
        cin >> status;
        cout << "Ubicación (URL colonia Google Maps): ";
        cin >> location;
        cout << "Modelo: ";
        cin >> model;
        cout << "Capacidad: ";
        cin >> napCapacity;
        
        for (int i = 1; i <= numNaps; i++)
        {
            int prefix = (i - 1) / 10;
            int suffix = (i - 1) % 10;
            
            string IDfinal = IDbase + " - " + to_string(prefix) + to_string(suffix); // Se define el nombre para todas las NAP. El resultado será AA - 01
            
            Nap* newNap = new Nap(IDfinal, status, location, manufacturer, model, emptyClients, napCapacity); // Se crea una NAP nueva
            naps.push_back(newNap);
            cout << "NAP " << IDfinal << " agregada exitosamente" << endl;
        }
    }
    else
    {
        for (int i = 1; i <= numNaps; ++i)
        {
            cout << "Ingrese la información para la NAP " << i << ": " << endl;
            cout << "ID: ";
            cin >> IDbase;
            cout << "Status (Activo / Inactivo): ";
            cin >> status;
            cout << "Ubicación (URL colonia Google Maps): ";
            cin >> location;
            cout << "Fabricante: ";
            cin >> manufacturer;
            cout << "Modelo: ";
            cin >> model;


            Nap* newNap = new Nap(IDbase, status, location, manufacturer, model, emptyClients, napCapacity); // Se crea una NAP nueva
            naps.push_back(newNap); // Se agrega la nueva NAP al vector
            cout << "NAP " << IDbase << " agregada exitosamente." << endl;
        }
    }
    return naps;
}


void Splice::showInfo()
{
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Información del cierre: " << ID << endl;
    cout << "Estatus: " << status << endl;
    cout << "Ubicación: " << location << endl;
    cout << "Fabricante: " << manufacturer << endl;
    cout << "Modelo: " << model << endl;
    cout << "Máximo de clientes: " << maxClients << endl;
    cout << "Total de NapS: " << naps.size() <<endl;
    cout << "--------------------------" << endl;
    cout << endl;

}

int Splice::getClientCount() const
{
    int totalClients = 0;
    for (const Nap* nap : naps)
    {
        totalClients += nap->getClientCount();
    }
    return totalClients;
}
