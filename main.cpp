//
//  main.cpp
//  ProjectNAP_Client_Control_Classes
//
//

#include <iostream>
#include <vector>
#include "Client.h"
#include "Domestic.h"
#include "Company.h"
#include "Nap.hpp"
#include "Splice.h"
#include "Rack.hpp"
#include <algorithm>

using namespace std;

// Variables globales de almacenamiento
vector<Rack*> racks;



//--------------------------------------------------------------------------------
                                //Menu
void showMenu();

void showMenu() 
{
    cout << endl;
    cout << "***** Menú *****" << endl;
    cout << endl;
    cout << "1. Crear Rack" << endl;
    cout << "2. Añadir elementos a la red" << endl;
    cout << "3. Unir dos NAP" << endl;
    cout << "4. Calcular todos los clientes en la red" << endl;
    cout << "5. Mostrar elementos de un Rack" << endl;
    cout << "6. Salir" << endl;
}
//--------------------------------------------------------------------------------
                                //mostrar lista racks SOLO PARA LA OPCION 1
void listaRacks();
void listaRacks()
{
    // Mostrar lista de racks existentes
    if (racks.empty())
    {
        cout << "No hay racks creados aún." << endl;
    }
    else
    {
        cout << "Racks existentes:" << endl;
        for (size_t i = 0; i < racks.size(); ++i) {
            cout << i + 1 << ". ID: " << racks[i]->getID() << endl;
        }
    }
}
//--------------------------------------------------------------------------------
                                //mostrar lista racks DEMAS OPCIONES
Rack* selectRack();
Rack* selectRack()
{
    // Mostrar lista de racks existentes
    if (racks.empty()) {
        cout << "No hay racks creados aún." << endl;
        return nullptr; // Si no hay racks disponibles, devolver nullptr
    }

    cout << "Racks existentes:" << endl;
    for (size_t i = 0; i < racks.size(); ++i) {
        cout << i + 1 << ". ID: " << racks[i]->getID() << endl;
    }

    // Pedir al usuario que seleccione un rack
    int choice;
    cout << "Seleccione el número correspondiente al rack: ";
    cin >> choice;

    // Validar la selección del usuario
    if (choice < 1 || choice > racks.size()) {
        cout << "Selección inválida. Volviendo al menú anterior." << endl;
        return nullptr; // Si la selección es inválida, devolver nullptr
    }

    // Devolver el rack seleccionado
    return racks[choice - 1];
}
//--------------------------------------------------------------------------------
                                //mostrar lista Splices
Splice* selectSplice();
Splice* selectSplice()
{
    Rack* selectedRack = selectRack();
    if (!selectedRack) 
    {
            return nullptr;
    }
    const vector<Splice*>& splices = selectedRack->getSplices();
        if (splices.empty()) {
            cout << "El rack seleccionado no tiene splices." << endl;
            return nullptr;
        }

        cout << "Seleccione un cierre para añadir NAPs:" << endl;
        for (int i = 0; i < splices.size(); ++i)
        {
            cout << i + 1 << ". Cierre ID: " << splices[i]->getID() << endl;
        }

        int spliceIndex;
        cout << "Ingrese el número del Splice: ";
        cin >> spliceIndex;
        if (spliceIndex < 1 || spliceIndex > splices.size()) 
        {
            cout << "Número de Splice inválido." << endl;
            return nullptr;
        }

        return splices[spliceIndex - 1];
}

//--------------------------------------------------------------------------------
                                //mostrar lista Naps
Nap* selectNap();
Nap* selectNap()
{
    Splice* spliceObjective = selectSplice();
    vector<Nap*> allNaps = spliceObjective->getNaps();
    if (allNaps.empty()) {
            cout << "No hay NAPs disponibles." << endl;
            return nullptr;
        }

        cout << "Seleccione una NAP de la lista: " << endl;
        for (size_t i = 0; i < allNaps.size(); ++i) {
            cout << i + 1 << ". " << allNaps[i]->getID() << endl;
        }

        int choice;
        cin >> choice;

        if (choice < 1 || choice > allNaps.size()) {
            cout << "Selección no válida." << endl;
            return nullptr;
        }

        return allNaps[choice - 1];
}

//--------------------------------------------------------------------------------
                                //opción 1
void createRack();

void createRack() 
{
    listaRacks();

    // Almacén de variables
    std::string ID;
    std::string status;
    std::string location;
    std::string manufacturer;
    std::string model;
    int numberFibers;
    int techCapacity;
    vector<Splice*> splices;

    cout << "Indica la información para el nuevo Rack" << endl;

    cout << "ID: ";
    cin >> ID;

    cout << "Estado (activo/inactivo): ";
    cin >> status;

    cout << "Ubicación: ";
    cin.ignore();
    getline(cin, location);

    cout << "Fabricante: ";
    cin >> manufacturer;

    cout << "Modelo: ";
    cin >> model;

    cout << "Número de fibras: ";
    cin >> numberFibers;

    cout << "Seleccione la tecnología de OLT (1: EPON (64 clientes), 2: GPON (128 clientes), 3: XGPON(256 clientes)): ";
    cin >> techCapacity;

    int oltTechnology;
        switch (techCapacity)
        {
            case 1:
                oltTechnology = 64;
                break;
            case 2:
                oltTechnology = 128;
                break;
            case 3:
                oltTechnology = 256;
                break;
            default:
                cout << "Opción de tecnología inválida. Usando GPON por defecto." << endl;
                oltTechnology = 128;
        }
    
    
    // Confirmar la creación del rack
    char confirm;
    do {
        cout << endl;
        cout << "ATENCIÓN ¿Desea crear el rack con los siguientes datos? (S/N)" << endl;
        cout << "ID: " << ID << endl;
        cout << "Estado: " << status << endl;
        cout << "Ubicación: " << location << endl;
        cout << "Fabricante: " << manufacturer << endl;
        cout << "Modelo: " << model << endl;
        cout << "Número de fibras: " << numberFibers << endl;
        cout << "Tecnología de OLT: " << oltTechnology << endl;
        cout << endl;
        cout << "Confirmar: ";
        cin >> confirm;

        if (confirm == 'S' || confirm == 's')
        {
            // Crear un nuevo rack
            Rack* newRack = new Rack(ID, status, location, manufacturer, model, numberFibers, oltTechnology, splices);
            racks.push_back(newRack);
            cout << "Rack creado exitosamente." << endl;
        }
        else if (confirm == 'N' || confirm == 'n')
        {
            cout << "Creación de rack cancelada." << endl;
            return; // Salir de la función si la creación se cancela
        }
        else
        {
            cout << "Opción inválida. Por favor, ingrese 'S' o 'N'." << endl;
        }
    } while (confirm != 'S' && confirm != 's' && confirm != 'N' && confirm != 'n');
    
}

//--------------------------------------------------------------------------------
                                //opción 2

void option2();

void option2()
{
    char choice;
    do {
        cout << "¿Qué elemento desea agregar a la red?" << endl;
        cout << "1. Cierre de empalme" << endl;
        cout << "2. NAP" << endl;
        cout << "3. Clientes" << endl;
        cout << "4. Regresar al menú principal" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        // Banco de variables
        std::string ID;
        std::string status;
        std::string location;
        std::string manufacturer;
        std::string model;
        int numberFibers;
        vector<Nap*> naps;
        int maxClients;

        switch (choice) 
        {
            case '1': 
            {
                Rack* rackObjective = selectRack();
                
                cout << "Indica la información para el nuevo Rack" << endl;

                cout << "ID: ";
                cin >> ID;

                cout << "Estado (activo/inactivo): ";
                cin >> status;

                cout << "Ubicación: ";
                cin.ignore();
                getline(cin, location);

                cout << "Fabricante: ";
                cin >> manufacturer;

                cout << "Modelo: ";
                cin >> model;

                int remainingFibers = rackObjective->calculateNumberFibersR();

                // Verificar si hay fibras restantes en el rack
                if (remainingFibers == 0) 
                {
                    cout << "Error: No hay fibras disponibles en el rack." << endl;
                    break;
                }

                // Mostrar al usuario cuántas fibras están disponibles
                cout << "Fibras restantes en el rack: " << remainingFibers << endl;

                // Solicitar al usuario el número de fibras para el cierre
                cout << "Ingrese el número de fibras que desea asignar al cierre: ";
                cin >> numberFibers;

                // Verificar si el número de fibras ingresado es válido
                if (numberFibers <= 0 || numberFibers > remainingFibers) 
                {
                    cout << "Error: Número de fibras inválido." << endl;
                    break;
                }

                // Conocer el número de clientes máximo que puede tener el cierre
                maxClients = numberFibers * rackObjective->getOltTechnology();

                string addNapsChoice;
                do 
                {
                    cout << "¿Desea agregar NAPs al cierre? (S/N): ";
                    cin >> addNapsChoice;
                    if (addNapsChoice == "s" || addNapsChoice == "S") 
                    {
                        Splice* temp = new Splice();
                        naps = temp->addNap(maxClients);
                        delete temp;
                        break;
                    } 
                    else if (addNapsChoice == "n" || addNapsChoice == "N")
                    {
                        naps = vector<Nap*>();
                        break;
                    } 
                    else
                    {
                        cout << "Respuesta no válida. Por favor, ingrese 'S' o 'N'." << endl;
                    }
                } while (true);

                int totalNapCapacity = 0;
                for (Nap* nap : naps)
                {
                    totalNapCapacity += nap->getCapacity();
                }
                int maxClientsR = maxClients - totalNapCapacity;

                Splice* newSplice = new Splice(ID, status, location, manufacturer, model, numberFibers, naps, maxClients, maxClientsR);

                rackObjective->addSplice(newSplice);
                break;
            }
            case '2':
            {
                Splice* spliceObjective = selectSplice();
                if (spliceObjective)
                {
                    vector<Nap*> newNaps = spliceObjective->addNap(spliceObjective->getMaxClientsR());
                    spliceObjective->addNap(newNaps);
                }
                break;
            }
            case '3':
            {
                Nap* napObjective = selectNap();
                
                // Verificar que napObjective no sea nullptr
                if (napObjective == nullptr) {
                    cout << "Error: No se pudo seleccionar la NAP." << endl;
                    break;
                }

                Client* newClient = napObjective->createClient();
                
                // Verificar que newClient no sea nullptr
                if (newClient == nullptr) {
                    cout << "Error: No se pudo crear el cliente." << endl;
                    break;
                }

                napObjective->addClient(newClient);
                cout << "Cliente añadido exitosamente a la NAP." << endl;
                break;
            }

                case '4':
                    cout << "Volviendo al menú principal." << endl;
                    return; // Salir de la función si el usuario elige regresar al menú principal
                default:
                    cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
            }
        } while (choice != '4');
    
}

//--------------------------------------------------------------------------------
                                //opción 3
void option3();
void option3()
{
    cout << "Esta opción permite unir la capacidad y los clientes de dos NAPs" << endl;
    
    cout << "Selecciona la primer NAP" << endl;
    Nap* nap1 = selectNap();
    
    if (nap1 == nullptr) {
        cout << "Error: No se pudo seleccionar la primera NAP." << endl;
        return;
    }
    
    cout << "Selecciona la segunda NAP" << endl;
    Nap* nap2 = selectNap();
    
    if (nap2 == nullptr) {
        cout << "Error: No se pudo seleccionar la segunda NAP." << endl;
        return;
    }
    
   // Usar el método
    *nap1 = *nap1 + *nap2;
    
    cout << "Las NAPs han sido combinadas exitosamente." << endl;
}

//--------------------------------------------------------------------------------
                                //opción 4
void option4(const vector<Rack*>&);
void option4(const vector<Rack*>& allRacks) 
{
    int totalClients = 0;

    for (const Rack* rack : allRacks) 
    { // Recorrer todos los racks en la red
        totalClients += rack->getClientCount();
    }

    cout << "El total de clientes en la red es: " << totalClients << endl;
}

//--------------------------------------------------------------------------------
                                //opción 5
void option5();
void option5()
{
    Rack* rackObjective = selectRack();
    rackObjective->showInfo();
}

//--------------------------------------------------------------------------------
                                // Main
int main(int argc, const char * argv[])
{
        
        // Bienvenida
        cout << "Bienvenido al sistema de gestión de clientes en redes de fibra óptica" << endl;
        cout << "By CUDA ツ" << endl;
        cout << endl;
        cout << "Antes de agregar clientes, debes tener por lo menos un Rack operando" << endl;
        
        // Despliegue de menu
        char option;
        do {
            showMenu();
            cout << "Ingrese su opción: ";
            cin >> option;
            
            switch(option)
            {
                case '1':
                    createRack();
                    break;
                case '2':
                    
                    option2();
                    break;
                case '3':
                    
                    option3();
                    break;
                case '4':
                    option4(racks);
                    break;
                case '5':
                    option5();
                    break;
                case '6':
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
            }
        } while(option != '6');
        
        
        
        
        for (Rack* rack : racks)
        {
            delete rack;
        }
        return 0;
}

