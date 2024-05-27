//
//  Wire.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Wire_h
#define Wire_h
#include "NetworkElement.h"
#include <iostream>
#include <string>

class Wire : public NetworkElement
{
private:
    float length;
    
public:
    //Constructors
    Wire();
    Wire(int, std::string, std::string, std::string, std::string, std::string, float);
    
    //Getters
    float getLenght();
    
    //Setters
    void setLenght(float);
    
};

#endif /* Wire_h */
