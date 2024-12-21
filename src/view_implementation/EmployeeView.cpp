#include "../../include/view/EmployeeView.hpp"
#include "../../include/service/EmployeeService.hpp"
#include "../../include/models/EmployeeModel.hpp"
EmployeeView::EmployeeView()
{
}

void EmployeeView::menu_employee(){

    EmployeeService employeeService;
    int opc;
    do{
        cout << "Menu empleado" << endl;
        cout << "1. añadir empleado" << endl;
        cout << "2. mostrar empleados" << endl;
        cout << "3. eliminar empleado" << endl;
        cout << "4. actualizar empleado" << endl;
        cout<<"0.salir"<<endl;
        
        
        cin >> opc;
        cin.ignore();
        switch(opc){
            case 1:{
                string name,timetable;
                int age,wage,dni;
                
                

                cout<<"ingrese el nombre del empleado"<<endl;
                getline(cin,name);
                cout<<"ingrese la edad del empleado"<<endl;
                cin>>age;
                cin.ignore();
                cout<<"ingrese el salario del empleado"<<endl;
                cin>>wage;
                cin.ignore();
                cout << "ingrese el horario del empleado" << endl;
                getline(cin,timetable);
                cout <<"ingrese la cedula del empleado" << endl;
                cin >> dni;
                cin.ignore();
                EmployeeModel employee(name,age,wage,timetable,dni);
                employeeService.Add(employee);
                break;}
            case 2:{
                employeeService.Read();
                break;
                }
            case 3:{
                int id_remove;
                cout << "Ingrese el id del empleado a eliminar" << endl;
                cin >> id_remove;
                cin.ignore();
                employeeService.Remove(id_remove);
                break;
                }   
            case 4:{
                int id;
                cout << "Ingrese el id del empleado a actualizar" << endl;
                cin >> id;
                cin.ignore();
                employeeService.Update(id);
                break;
            }
            case 0:{
                cout<<"saliendo de empleados..."<<endl;
                break;
            }
            default:
                cout << "Invalid input" << endl;
                break;
        
    }
    }while(opc!=0);
    }
