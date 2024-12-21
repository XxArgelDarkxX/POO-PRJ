#include "../../include/service/AccountService.hpp"
#include "../../include/view/AccounView.hpp"
#include "../../include/models/AccountModel.hpp"
#include <iostream>
#include <string>
using namespace std;
AccountView:: AccountView(){}

void AccountView::menu_account(){
    AccountService account_service;
    int option;
    string account_number;
    int ammount;
    do{
        cout<<"1. Crear cuenta"<<endl;
        cout<<"2.eliminar cuenta"<<endl;
        cout<<"3. Actualizar cuenta"<<endl;
        cout<<"4. Depositar"<<endl;
        cout<<"5. Retirar"<<endl;
        cout<<"6. Transferir"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>option;
        switch (option) {
        case 1:{
            cout<<"estas en crear cuenta"<<endl;
            account_service.CreateAccount();
            break;
            }
        case 2:{
        AccountModel account_;
            cout<<"Ingrese el numero de cuenta a eliminar: ";
            cin>>account_number;
            account_.delete_account(account_number);
            break;
            }
        case 3:{
            AccountModel account_;
            cout<<"Ingrese el numero de cuenta a actualizar: ";
            cin>>account_number;
            account_.update_account(account_number);
            break;
            }
        case 4:{
            cout<<"Ingrese el numero de cuenta: ";
            cin>>account_number;
            cout<<"Ingrese la cantidad a depositar: ";
            cin>>ammount;
            account_service.Deposit(account_number,ammount);
            break;
            }
        case 5:{
            cout<<"Ingrese el numero de cuenta: ";
            cin>>account_number;
            cout<<"Ingrese la cantidad a retirar: ";
            cin>>ammount;
            account_service.Withdraw(account_number,ammount);
            break;
            }
        case 6:{
            account_service.Transfer();
            break;
            }
        case 7:{
            cout<<"Saliendo..."<<endl;
            break;}
        default:
            cout<<"Opcion no valida"<<endl;
            break;
    
    }}while(option!=7);
        
}
