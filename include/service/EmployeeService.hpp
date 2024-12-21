#pragma once
#include <iostream>
#include "../models/EmployeeModel.hpp"
using namespace std;



class EmployeeService{

public:
    EmployeeService();
    bool Find(string);
    void Add(EmployeeModel employee);
    void Remove(int);
    void Update(int id);
    void Read();
   
    
    
};




