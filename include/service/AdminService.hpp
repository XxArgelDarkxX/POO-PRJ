#pragma once
#include <string>
#include <iostream>

class AdminService {
    public:
        AdminService();
        bool Login(std::string username, std::string password);
        void Add(std::string/*Clase empleado*/);
        void Update(/*Id del empleado*/);
        void Delete(/*Id del empleado*/);
        void ReadEmployees();
        void ReadHistory();
        void ReadProfits();
};
    