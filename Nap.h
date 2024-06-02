//
//  Nap.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Nap_h
#define Nap_h
#include "NetworkElement.h"
#include "Client.h"
#include <iostream>
#include <string>
#include <vector>

class Nap : public NetworkElement
{
private:
    int idNap;
    std::vector<Client*> clients;
    int capacity;
    
public:
                            //Constructors
    
    Nap();
    Nap(std::string, std::string, std::string, std::string, std::string, int, std::vector<Client>, int);
    
    
                            //Getters
    int getCapacity();
    std::vector<Nap> getClients();
    int getID() override; //From superclass "NetworkElement"
    
    
                            //Setters
    void setCapacity(int);
    void setID(int) override; //From superclass "NetworkElement"
    
    
                            //Additionals
    void addClients(Client);
    void showInfo() override;
    
};

#endif /* Nap_h */
