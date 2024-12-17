#include "../../include/service/AdminService.hpp"
#include "../../include/models/AdminModel.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
AdminModel adminModel;

AdminService::AdminService() {}

bool AdminService::Login(std::string username_, std::string password_) {
    if (username_ == adminModel.getUsername() && password_ == adminModel.getPassword()) {
        return true;
    }
    return false;
}

void AdminService::Add(std::string filename /*Clase empleado*/) {
    std::cout << "Add" << std::endl;
    std::ofstream file(filename, std::ios::app);
    file << "Poner To string" << std::endl;
}

void AdminService::Update(/*Clase empleado*/) {
    std::cout << "Update" << std::endl;
    
}

void AdminService::Delete(/*Id del empleado*/) {
    std::cout << "Delete" << std::endl;
}

void AdminService::ReadEmployees() {
    std::cout << "ReadEmployees" << std::endl;
}

void AdminService::ReadHistory() {
    std::cout << "ReadHistory" << std::endl;
}

void AdminService::ReadProfits() {
    std::cout << "ReadProfits" << std::endl;
}

