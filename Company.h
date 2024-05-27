//
//  Company.h
//  ProjectNAP_Client_Control_Classes
//
//

#ifndef Company_h
#define Company_h
#include <iostream>
#include "Client.h"
#include <string>

class Company : public Client {
private:
    std::string companyName;
    bool techsupportad;
    
public:
    //Constructors
    Company();
    Company(int,std::string,std::string, int, float,bool, int, std::string, bool);
    
    //New Getters
    std::string getCompanyName();
    bool getTechsupportad();
    
    //New Setters
    void setCompanyName(std::string);
    void setTechsupportad(bool);

};

#endif /* Company_h */
