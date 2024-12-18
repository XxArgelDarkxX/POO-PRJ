#pragma once
#include <string>
#include <iostream>

class AdminModel { /*Heredar de Persona */
private:
    std::string username = "XxArgelDarkxX";
    std::string password = "1117018254An";
public:
    AdminModel();

    std::string getUsername();
    std::string getPassword();
};