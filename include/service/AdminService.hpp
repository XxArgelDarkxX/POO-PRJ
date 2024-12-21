#pragma once
#include <string>
#include <iostream>
#include "../models/EmployeeModel.hpp"

class AdminService {
    public:
        AdminService();
        bool Login(std::string username, std::string password);
        void Add(EmployeeModel);
        void Update(EmployeeModel);
        void Delete(int);
        void ReadEmployees();
        void ReadHistory();
        void ReadProfits();
};
    