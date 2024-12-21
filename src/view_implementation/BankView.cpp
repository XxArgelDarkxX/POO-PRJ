#include  "../../include/view/BankView.hpp"
#include "../../include/models/BankModel.hpp"
#include <iostream>
using namespace std;
BankView::BankView()
{
}
 
void BankView::menu_bank()
{   int option;
    do
    {   BancoModel banco;
        cout << "1. Ver ganancias del banco" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;
        switch (option)
        {
        case 1:
            banco.get_ganancias();
            break;
        case 2:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (option != 2);
}