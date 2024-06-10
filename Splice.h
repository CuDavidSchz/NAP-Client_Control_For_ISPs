//
//  Splice.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Splice_h
#define Splice_h
#include "BackboneElement.h"
#include "Nap.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 


using namespace std;

class Splice : public BackboneElement
{
private:
    
    vector<Nap*> naps;
    int maxClients;
    int maxClientsR;
    
public:
//--------------------------------------------------------------------------------
                        //Constructors
    Splice();
    Splice(string, string, string, string, string, int, vector<Nap*>, int, int);
    
    
//--------------------------------------------------------------------------------
                        //Getters
    
    int getMaxClients();
    int getMaxClientsR();
    vector<Nap*> getNaps();
    
//--------------------------------------------------------------------------------
                        //Setters
    
    void setMaxClients(int);

//--------------------------------------------------------------------------------

                        //Adicionales
    void addNap(vector<Nap*>);
    vector<Nap*> addNap(int);

    void showInfo() override;
    int getClientCount() const override;
    
};



#endif /* Splice_h */
