#include "Customer.hpp"
#include <iostream>
using namespace std;

MenuCustomerView::MenuCustomerView() {
}


void MenuCustomerView::showCustomerMenu() {
    MenuCustomerView menuCustomerView; 
    int option = 0;
    cout << "Bienvenido a el banco la perra de rubio " << endl;
    cout << "1. Quiere registrarse en el banco?" << endl;
    cout << "2. Quiere salirse del banco?" << endl;
    cout << "3. Quiere saber tu estado en el banco" << endl;
    cout << "4. desea actualizar tus datos" << endl;
    cout << "0. Exit" << std::endl;
    cout << std::endl; 
    cout << "seleccione una opcion: "; cin >> option;
    cin.ignore();
    std::cout << std::endl;
    switch(option) {
        case 1:{
            cout << "Registrarse" << std::endl;
            break;
            }
        case 2:{
            cout << "Renunciando a nuestro servicios" << endl;
            break;
            }
        case 3:{
            
            cout << "Inicie tu seccion: " << endl;
            break;
            }
        case 4:{ 
            cout << "Actualizar datos" << endl;  
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
}
}