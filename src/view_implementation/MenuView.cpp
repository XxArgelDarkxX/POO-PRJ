#include "MenuView.hpp"
#include "Customer.hpp"


#include <iostream>
#include <string>
using namespace std; 

void MenuView::showMenu() {
    int opcion; 
    cout << "1. Cliente" << endl; 
    cout << "2. Empleado" << endl; 
    cout << "3. Administrador" << endl; 
    cout << "5. salir" << endl; 
    cout<<"_"<<endl;
    cout << "Elija su opcion: " << endl; cin>>  opcion; 
    cout<<"_"<<endl;
    switch (opcion) {
        case 1: {
            cout << "Menu cliente" << endl;
            MenuCustomerView myCustomer;  
            myCustomer.showCustomerMenu();
            break; 
        }
        case 2: {
            cout << "Menu empleado" << endl;
            break; 
        }
        case 3: {
            cout << "Menu administrador" << endl;
            break; 
        }
        case 5: {
            cout << "Saliendo del sistema" << endl;
            break; 
        }
        default: {
            cout << "Elija una opcion correcta mlp" << endl;
            break; 
        }
}}