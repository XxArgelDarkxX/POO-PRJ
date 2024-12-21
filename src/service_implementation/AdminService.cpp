#include "../../include/service/AdminService.hpp"
#include "../../include/models/AdminModel.hpp"
#include "../../include/service/EmployeeService.hpp"
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

void AdminService::Add(EmployeeModel empleado) {
    EmployeeService employeeService;
    employeeService.Add(empleado);
}

void AdminService::Update(EmployeeModel empleado) {
    EmployeeService employeeService;
    employeeService.Update(empleado.get_dni());
}

void AdminService::Delete(int id_empleado) {
    EmployeeService employeeService;
    employeeService.Remove(id_empleado);
}

void AdminService::ReadEmployees() {
    EmployeeService employeeService;
    employeeService.Read();
}

void AdminService::ReadHistory() {
    std::cout << "ReadHistory" << std::endl;
}

void AdminService::ReadProfits() {
    std::cout << "ReadProfits" << std::endl;
}

