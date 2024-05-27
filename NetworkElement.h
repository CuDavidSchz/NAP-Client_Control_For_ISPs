//
//  NetworkElement.h
//  ProjectNAP_Client_Control_Classes
//
//  Created by David Cu Sánchez on 25/05/24.
//

#ifndef NetworkElement_h
#define NetworkElement_h
#include <iostream>
#include <string>

class NetworkElement{
protected:
    int idNE;
    std::string name;
    std::string location;
    std::string manufacturer;
    std::string model;
    bool status;
    int numberFibers;

public:
    //Constructors
    NetworkElement();
    NetworkElement(int, std::string, std::string, std::string, std::string, bool, int);
    
    //Getters
    int getIDNE() const;
    std::string getName() const;
    std::string getLocation() const;
    std::string getManufacturer() const;
    std::string getModel() const;
    bool getStatus() const;
    int getnumberFibers() const;
    
    //Setters
    void setIDNE(int);
    void setName(std::string);
    void setLocation(std::string);
    void setManufacturer(std::string);
    void setModel(std::string);
    void setStatus(bool);
    void setNumberFibers(int);
    
};


#endif /* NetworkElement_h */
