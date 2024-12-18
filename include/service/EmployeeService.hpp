#pragma once
#include "../models/EmployeeModel.hpp"
#include <iostream>

using namespace std;

class EmployeeService {
public:
  EmployeeService();
  bool Find(int);
  void Add(EmployeeModel employee);
  void Remove(int);
  void Update(int id);
  void Read();
};