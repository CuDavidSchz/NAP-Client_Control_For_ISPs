//
//  Nap.cpp
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 08/06/24.
//

#include "Nap.hpp"
#include "Client.h"
#include "Company.h"
#include "Domestic.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//--------------------------------------------------------------------------------
                                // Constructors
    // Default
Nap::Nap() : NetworkElement()
{
    clients = vector<Client*>();
    capacity = 0;
}
    // Parametrized
Nap::Nap(string ID, string status, string location, string manufacturer, string model, vector<Client*> clients, int capacity) :
    
    NetworkElement(ID, status, location, manufacturer, model) ,
    clients(clients) , 
    capacity(capacity)
{}

//--------------------------------------------------------------------------------
                                    // Getters
    // Obtener la capacidad de la NAP
int Nap::getCapacity()
{
    return this->capacity;
}
    // Obtener el vector de clientes
vector<Client*> Nap::getClients()
{
    return this-> clients;
}

//--------------------------------------------------------------------------------

                                    // Setter
    // Cambiar la capacidad de la NAP
void Nap::setCapacity(int _capacity)
{
    this->capacity = _capacity;
}

//--------------------------------------------------------------------------------
                                // Additionals

Nap Nap::operator+(const Nap& val) 
{
    Nap temp(*this);
    
    temp.clients.insert(temp.clients.end(), val.clients.begin(), val.clients.end());
    
    temp.capacity += val.capacity;
    
    return temp;
}


Client* Nap::createClient() // Añade un nuevo cliente
{
    // Almacén de variables
    int idc, phoneNumber, bandwidth;
    float fee;
    string serviceOwner, address, companyName;
    bool status;
    Client* newClient = nullptr; 

    // Formulario
    cout << "Ingrese los datos del cliente: " << endl;
    cout << "ID: ";
    cin >> idc;
    cin.ignore();

    cout << "Nombre del cliente: ";
    getline(cin, serviceOwner);

    cout << "Dirección (URL Google Maps): ";
    getline(cin, address);

    cout << "Número de teléfono: ";
    cin >> phoneNumber;

    cout << "Tarifa de servicio: ";
    cin >> fee;

    cout << "Estatus (0 si está inactivo y 1 si está activo): ";
    cin >> status;

    cout << "Ancho de banda: ";
    cin >> bandwidth;

    char choice;
    while (true)
    {
        cout << "¿El cliente es una empresa? S/N: ";
        cin >> choice;
        cin.ignore();

        if (choice == 'S' || choice == 's')
        {
            cout << "Nombre de la empresa: ";
            getline(cin, companyName);

            while (true)
            {
                cout << "¿Contrató soporte técnico avanzado? S/N: ";
                cin >> choice;
                cin.ignore();

                if (choice == 'S' || choice == 's' || choice == 'N' || choice == 'n')
                {
                    bool techSupportAdvanced = (choice == 'S' || choice == 's');

                    // Se crea el cliente nuevo tipo compañía
                    newClient = new Company(idc, serviceOwner, address, phoneNumber, fee, status, bandwidth, companyName, techSupportAdvanced);
                    clients.push_back(newClient);
                    cout << "Cliente añadido exitosamente." << endl;
                    return newClient; // Devolver el cliente creado
                }
                else
                {
                    cout << "Opción inválida. Por favor, introduzca S o N." << endl;
                }
            }
        }
        else if (choice == 'N' || choice == 'n')
        {
            // Se crea el cliente nuevo tipo doméstico
            newClient = new Domestic(idc, serviceOwner, address, phoneNumber, fee, status, bandwidth);
            clients.push_back(newClient);
            cout << "Cliente añadido exitosamente." << endl;
            return newClient; // Devolver el cliente creado
        }
        else
        {
            cout << "Opción inválida. Por favor, especifique si el cliente es o no una compañía (S/N)." << endl;
        }
    }

    // Si llegamos a este punto, no se ha creado ningún cliente
    return nullptr;
}

void Nap::addClient(Client* client)
{
    this->clients.push_back(client);
}


void Nap::showInfo() // Mostar información de la Nap
{
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Información de la Nap: " << ID << endl;
    cout << "Satus: " << status << endl;
    cout << "Location: " << location << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Model: " << model << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Clientes: " << clients.size() <<endl;
    cout << "--------------------------" << endl;
    if (clients.empty()) 
    {
            cout << "No existen clientes en NAP "<< ID << endl;
    }
    else
    {
        char choice;
        cout << "¿Desea conocer la información de los clientes? S/N: ";
        cin >> choice;
            if (choice == 's' || choice == 'S') 
            {
                for (int i = 0; i < clients.size(); ++i)
                {
                    cout << "Cliente " << i + 1 << ": ";
                    clients[i]->showInfo();
                }
            } 
            else if (choice != 'n' && choice != 'N')
            {
                cout << "Opción invalida. Por favor, introduzca S o N." << endl;
            }
    }
}

int Nap::getClientCount() const
{
    return this->clients.size();
}
