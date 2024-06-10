//
//  Nap.hpp
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Nap_hpp
#define Nap_hpp


#include "NetworkElement.h"
#include "Client.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Nap : public NetworkElement
{
private:
    std::vector<Client*> clients;
    int capacity;
    
public:
//--------------------------------------------------------------------------------

                            // Constructors
        // Default
    Nap();
        // Parametirezed
    Nap(std::string, std::string, std::string, std::string, std::string, std::vector<Client*>, int);
    
//--------------------------------------------------------------------------------

                            // Getters
    int getCapacity();
    std::vector<Client*> getClients();
    
//--------------------------------------------------------------------------------

                            // Setters
    void setCapacity(int);

    
//--------------------------------------------------------------------------------

                            // Additionals
    
    Client* createClient();
    void addClient(Client*);
    void showInfo() override;
    
    int getClientCount() const override;
    
        // Operators
    Nap operator+(const Nap&);

};

#endif /* Nap_h */
