//
//  Client.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Client_h
#define Client_h

#include <iostream>
#include <string>


class Client { //Abstract Class
protected:
    int idc;
    std::string serviceOwner;
    std::string address;
    int phoneNumber;
    float fee;
    bool status;
    int bandwidth;
    
public:
    //Constructors
    Client();
    Client(int, std::string, std::string, int, float, bool, int);
    
    //Getters
    int getIDC() const;
    std::string getServiceOwner() const;
    std::string getAddress() const;
    int getPhoneNumber() const;
    float getFee() const;
    bool getStatus() const;
    int getBandwidth() const;
    
    //Setters
    void setIDC(int);
    void setServiceOwner(std::string);
    void setAddress(std::string);
    void setPhoneNumber(int);
    void setFee(float);
    void setStatus(bool);
    void setBandwidth(int);
    
    // Additionals
    virtual void showInfo() = 0;
};



#endif /* NetworkElement_h */
