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
    
    std::string ID;
    std::string status;
    std::string location;
    std::string manufacturer;
    std::string model;

public:
                            // Constructors
    NetworkElement();
    NetworkElement(std::string, std::string, std::string, std::string, std::string);
    
                            // Getters
    
    std::string getID() const;
    std::string getStatus() const;
    std::string getLocation() const;
    std::string getManufacturer() const;
    std::string getModel() const;

    
                            // Setters
    
    void setID(std::string);
    void setStatus(std::string);
    void setLocation(std::string);
    void setManufacturer(std::string);
    void setModel(std::string);
    
                            // Aditionals
    virtual void showInfo() = 0; //Reservation for subclasses
    virtual int getClientCount() const = 0;
    
};


#endif /* NetworkElement_h */
