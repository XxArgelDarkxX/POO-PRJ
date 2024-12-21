#include "../../include/service/AccountService.hpp"
#include "../../include/models/AccountModel.hpp"
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
//se inicializa la variable permiss para saber si se generar la transferencia
bool permiss = false;   


AccountService::AccountService(){}

bool AccountService::find(string find_){
    string data,id,accountNumber,balance,expirate_date,name;

    bool dni_find = false;
    ifstream registers("cuentas.csv",ios::in);
    if(!registers){
        cout<<"documento no abierto"<<endl;
        return false;
    }
        while(getline(registers,data)){
        stringstream registers(data);
            getline(registers,id,',');
            getline(registers,name,','); 
            getline(registers,accountNumber,',');
            getline(registers,balance,',');
            getline(registers,expirate_date,',');
        
       
        

        if(accountNumber == find_){
        
            return true;
        }
        
        }return false;

    }



inline string gen_number(int digits=10) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, 9);

    string numero = "";
    for (int i = 0; i < digits; ++i) {
        numero += to_string(distrib(gen));
    }
    return numero;
}



void AccountService::CreateAccount(){
    string owner,account_type; // nombre del propietario y tipo de cuenta
    AccountModel account;
    string id = to_string(account.get_id());
    string accountNumber = gen_number();
    string balance = "0"; // Convertir el entero a cadena
    string expirate_date = "12/12/2030";
    cin.ignore();
    cout << "Creando cuenta..." << endl;
    cout << "Ingrese el nombre del propietario: "<<endl;
    getline(cin, owner);
    cout<<"ingrese el tipo de cuenta que quiere crear(corriente o ahorros): "<<endl;
    getline(cin,account_type);
   
    ofstream doc_accounts("cuentas.csv", ios::app);
    if (!doc_accounts){
        cerr << "No se pudo abrir el archivo cuentas.csv" << endl;
    } else {
        doc_accounts<<id<<"," << owner << "," << accountNumber << ","<<account_type<<"," << balance << "," << expirate_date << endl;
        doc_accounts.close(); 
    }
}

void AccountService::Deposit(string account_number, int _ammount) {
    int new_amount; // cantidad
    string data, id, name, find_account, ammount, expirate_date, account_type;
    bool found = false;

    ifstream doc_accounts("cuentas.csv", ios::in);
    ofstream outfile("cuentas_temp.csv");

    if (!doc_accounts) {
        cerr << "No se pudo abrir el archivo cuentas.csv" << endl;
    } else {
        while (getline(doc_accounts, data)) {
            stringstream registers(data);
            getline(registers, id, ',');
            getline(registers, name, ',');
            getline(registers, find_account, ',');
            getline(registers, account_type, ',');
            getline(registers, ammount, ',');
            getline(registers, expirate_date, ',');
            // Si la cuenta es de ahorros, se le aplica un interés del 5%
            if (find_account == account_number && account_type == "ahorros") {
                float interest = 0.05;
                cout << "Cuenta encontrada" << endl;
                found = true;

                int current_balance = stoi(ammount);
                int new_balance = current_balance + _ammount;
                new_balance += new_balance * interest; // Aplicar interés
                outfile << id << "," << name << "," << find_account << "," << account_type << "," << to_string(new_balance) << "," << expirate_date << endl;

            // Si la cuenta es corriente, no se le aplica interés
            } else if (find_account == account_number && account_type == "corriente") {
                cout << "Cuenta encontrada" << endl;
                found = true;

                int current_balance = stoi(ammount);
                int new_balance = current_balance + _ammount;
                outfile << id << "," << name << "," << find_account << "," << account_type << "," << to_string(new_balance) << "," << expirate_date << endl;

            } else {
                outfile << data << endl;
            }
        }
    }

    doc_accounts.close();
    outfile.close();

    if (found) {
        remove("cuentas.csv");
        rename("cuentas_temp.csv", "cuentas.csv");
        cout << "Deposito exitoso" << endl;
    } else {
        remove("cuentas_temp.csv");
        cout << "Cuenta no encontrada" << endl;
    }
}

void AccountService::Withdraw(string account_number,int _ammount){
    

    string data,id,name,find_account,ammount,expirate_date,account_type;
    bool found = false;
  
    
    ifstream doc_accounts("cuentas.csv", ios::in);
    ofstream outfile("cuentas_temp.csv");

    if (!doc_accounts){
        cerr << "No se pudo abrir el archivo cuentas.csv" << endl;
    } else {
     
        while (getline(doc_accounts, data)){
            stringstream registers(data);
            getline(registers,id,','); 
            getline(registers,name,',');
            getline(registers,find_account,','); 
            getline(registers,account_type,','); 
            getline(registers,ammount,',');
            getline(registers,expirate_date,',');

            if (find_account== account_number){
                cout<<"Cuenta encontrada"<<endl;
                found = true;
                int new_amount_ = stoll(ammount);
                int new_balance = new_amount_ - _ammount;
                if(new_balance<0){
                    cout<<"Fondos insuficientes"<<endl;
                    permiss = false;
                    return;
                }
                outfile << id << "," << name << "," << find_account<<","<<account_type<< "," <<to_string(new_balance)<<","<<expirate_date<<endl;
               
            }else{
                outfile << data << endl;
            }

        }
}doc_accounts.close();
outfile.close();
if(found){
    remove("cuentas.csv");
    rename("cuentas_temp.csv","cuentas.csv");
    permiss = true;
    cout<<"retiro exitoso"<<endl;
}else{
    remove("cuentas_temp.csv");
    cout<<"Cuenta no encontrada"<<endl;

}
    

}

void AccountService::Transfer(){
    string account_origin;
    cout<<"digite su numero de cuenta: "<<endl;
    cin>>account_origin;
    if(find(account_origin)){
        string account_destiny;
        cout<<"digite el numero de cuenta al que quiere transferir: "<<endl;
        cin>>account_destiny;
        if(find(account_destiny)){
            int amount;
            cout<<"digite la cantidad que quiere transferir: "<<endl;
            cin>>amount;
            Withdraw(account_origin,amount);
            if(permiss){
                 Deposit(account_destiny,amount);
                 int interest = 0.05;
                 //gananacias del banco
                int earnings = amount + amount * interest;
                ofstream doc_earnings("ganancias.csv", ios::app);
                doc_earnings << earnings << endl;
                doc_earnings.close();
            }else{
                cout<<"Fondos insuficientes"<<endl;
            }
           
        }else{
            cout<<"Cuenta destino no encontrada"<<endl;
        }}
    
    
    

}


