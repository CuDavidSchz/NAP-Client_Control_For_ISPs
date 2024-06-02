//
//  Splice.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Splice_h
#define Splice_h
#include "BackboneElement.h"
#include "Nap.h"
#include <iostream>
#include <string>
#include <vector>

class Splice : public BackboneElement
{
private:
    int capacity;
    std::vector<Nap*> naps;
    
public:
                        //Constructors
    Splice();
    Splice(std::string, std::string, std::string, std::string, std::string, int, std::vector<Nap*>);
    
                        //Getters
    int getCapacity();
    std::vector<Nap> getNaps();
    
                        //Setters
    void setCapacity(int);
    void setLevel(std::string);
    
                        //Adicionales
    void addNap(Nap);
    
};



#endif /* Splice_h */
