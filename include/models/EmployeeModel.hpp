#pragma once
#include <iostream>
#include "PersonModel.hpp"




class EmployeeModel:public PersonModel{
private:
    float wage; // salario
    std::string timetable; // horario
    int dni; // la cedula del  del empleado
    static int id_counter;
  
public:
    EmployeeModel(std::string,int,float,std::string,int);
    float get_wage(); // get_salario
    int get_dni(); // get_cedula
    std::string get_timetable(); //get_horario
    void set_wage(float );
    void set_timetable(std::string);
    //int load_id();
   std:: string ToString() override;
   


};
