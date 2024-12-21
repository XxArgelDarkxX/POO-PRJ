#include "../../include/models/EmployeeModel.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;



int load_id(){
    ifstream file("empleados.csv",std::ios::in);
    string line;
    int count = 0;
  while(getline(file,line)) {
    count++;
  }
    return count;
}


int EmployeeModel::id_counter = 1;


EmployeeModel::EmployeeModel( string name, int age, float wage_, string timetable_, int dni_)
    : PersonModel(load_id(), name, age), wage(wage_), timetable(timetable_), dni(dni_) {
        

    

    
}


float EmployeeModel::get_wage() {
    return wage;
}

std::string EmployeeModel::get_timetable() {
    return timetable;
}

void EmployeeModel::set_wage(float wage_) {
    wage = wage_;
}

void EmployeeModel::set_timetable(std::string time_) {
    timetable = time_;
}

std::string EmployeeModel::ToString() {
    return PersonModel::ToString() + "," + to_string(wage) + "," + timetable + "," + to_string(dni);
}

 int::EmployeeModel::get_dni() {
    return dni;
}

