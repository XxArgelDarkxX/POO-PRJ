#include "../../include/service/EmployeeService.hpp"
#include "../../include/models/EmployeeModel.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
EmployeeService::EmployeeService(){
    
   
}



bool EmployeeService::Find(int find_){
    string data,dni,name,wage,timetable,id,age;

    bool dni_find = false;
    ifstream registers("empleados.csv",ios::in);
    if(!registers){
        cout<<"documento no abierto"<<endl;
        return false;
    }
        while(getline(registers,data)){
        stringstream registers(data);
            getline(registers,id,',');
            getline(registers,name,','); 
            getline(registers,age,',');
            getline(registers,wage,',');
            getline(registers,timetable,',');
            getline(registers,dni,',');
        
       
        

        if(stoi(dni) == find_){
            dni_find = true;
            return true;
        }
        
        }return false;

    }



void EmployeeService::Add(EmployeeModel empleado){
   
    if(Find(empleado.get_dni())){
        cout<<"el empleado ya existe"<<endl;
    }else{
    ofstream doc_employeed("empleados.csv",ios::app);
    if(!doc_employeed){
        cout<<"archivo no creado"<<endl;
    }else{
        
        doc_employeed<<empleado.ToString()<<endl;
    }
    }

}




void EmployeeService::Remove(int id_remove) {

  string data, id;
  bool find_employeed = false; // para confirmar si encontro el empleado
  ifstream doc_employeed("empleados.csv", ios::in);

  if (!doc_employeed) { // retorna y no necesitas else
    cout << "no se abrio el documento";
    return;
  }

  vector<string> remove_employeed;

  while (getline(doc_employeed, data)) {
    stringstream registers(data);  // convertimos en string
    getline(registers, id, ',');   // leamos los ids hasta las comas
                                   //
    if ((id_remove == stoi(id))) { // valida que id a elimar se encuentre y la
      find_employeed = true;
    } else {
      remove_employeed.push_back(data);
    }
  }

  if (!find_employeed) {
    cout << "la id no encontrado" << endl;
    return;
  }

  cout << "usuario eliminado";
  ofstream doc_delate("empleados.csv");   
  for (auto employee : remove_employeed) { 
    doc_delate << employee << endl; 
  }
}
void EmployeeService::Read(){
    string data,id,name,wage,timetable,dni,age;
    ifstream doc_employeed("empleados.csv",ios::in);
    if(!doc_employeed){
        cout<<"Error al tratar de abrir el documento csv"<<endl;
        return;
    }

        while(getline(doc_employeed,data)){
            stringstream registers(data); //convertimos la cadena de datos en un flujo de datos

            getline(registers,id,',');
            getline(registers,name,','); 
            getline(registers,age,',');
            getline(registers,wage,',');
            getline(registers,timetable,',');
            getline(registers,dni,',');

            cout<<"id del empleado: "<<id<<endl;
            cout<<"nombre del empleado: "<<name<<endl;
            cout <<"la edad del empleado : "<<age<<endl;
            cout<<"salario del empleado : "<<wage<<endl;
            cout <<"horario del empleado: "<<timetable<<endl;
            cout<<"id del banco: "<<dni<<endl;
        }
        doc_employeed.close();
    }


// revisar como se esta guardando en el archivo empleado hay ;y ,
// emplear metodo read

void EmployeeService::Update(int dni_){
    string data,name,wage,timetable,age,dni,id;
    bool find_employeed = false;
    ifstream doc_employeed("empleados.csv",ios::in);
    if(!doc_employeed){
        cout<<"no se abrio el documento";
        return;
    }
        vector<string>update_employeed;
        
        while(getline(doc_employeed,data)){
            stringstream registers(data); // convertimos en string
            getline(registers,id,','); // leamos los ids hasta las comas
            getline(registers,name,','); // leamos los ids hasta las comas
            getline(registers,age,',');
            getline(registers,wage,',');
            getline(registers,timetable,',');
            getline(registers,dni,',');
            if(dni_== stoi(dni)){
                find_employeed = true;
                cout<<"digite el nuevo nombre"<<endl;
                cin>>name;
                cout<<"digite la nueva edad"<<endl;
                cin>>age;
                cout<<"digite el nuevo salario"<<endl;
                cin>>wage;
                cout<<"digite el nuevo horario"<<endl;
                cin>>timetable;
                cout<<"digite el nuevo dni del banco"<<endl;
                cin>>dni;
                update_employeed.push_back(id+","+name+","+age+","+wage+","+timetable+","+dni);
            }else{
                update_employeed.push_back(data);
            }
        }
    doc_employeed.close();
    // si se encontro el empleado
    if(find_employeed){
        cout<<"usuario actualizado";
        ofstream doc_update("empleados.csv"); // creamos un nuevo documento
        for(int i=0; i<update_employeed.size();i++){ // leemos el vector
            doc_update<<update_employeed[i]<<endl;  // guardamos los nuevos datos en el documeto

        }doc_update.close();
    
        }else{
            cout<< "la id no encontrado"<<endl;
        }

}