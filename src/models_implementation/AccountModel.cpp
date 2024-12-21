#include  "../../include/models/AccountModel.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
inline string load_id() {
    ifstream file("cuentas.csv");
    string line, last_id = "0";
    
    while (getline(file, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ',');
        last_id = id;
    }
    
    int new_id = stoi(last_id) + 1;
    return to_string(new_id);
}

AccountModel::AccountModel(string id_,string owner, string accountNumber,string type_account, float balance) {
    owner_name = owner;
    accountNumber = accountNumber;
    AccountType = type_account;
    balance = balance;
    id_ = load_id();
}   
AccountModel::AccountModel(){
    
    this->id = stoi(load_id()); // Asigna el nuevo id
}


int AccountModel::get_id() {
    return id;
}

//metodos getters
float AccountModel::GetBalance() {
    return balance;
}

string AccountModel::GetOwner() {
    return owner_name;
}

string AccountModel::GetAccountNumber() {
    return accountNumber;
}

string AccountModel::GetExpirateDate() {
    return expirate_Date;
}

string AccountModel::getinfo() {
    return "Owner: " + owner_name + " Account Number: " + accountNumber +  "Balance: " + to_string(balance);
}

//metodos setters

void AccountModel::SetBalance(float balance) {
    balance = balance;
}

void AccountModel::SetOwner(string owner) {
    owner_name = owner;
}

void AccountModel::SetAccountNumber(string accountNumber) {
    accountNumber = accountNumber;
}

void AccountModel::SetType(string AccountType) {
    AccountType = AccountType;
}

void AccountModel::SetExpirateDate(string expirate_Date) {
    expirate_Date = expirate_Date;
}


//implementacion de los metodos crud    

void AccountModel::delete_account(string accountNumber) {
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

            if (find_account == accountNumber) {
                cout << "Cuenta encontrada" << endl;
                found = true;
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
        cout << "Cuenta eliminada" << endl;
    } else {
        remove("cuentas_temp.csv");
        cout << "Cuenta no encontrada" << endl;
    }
}

void AccountModel::update_account(string accountNumber) {
    string data, id, name, find_account, ammount, expirate_date, account_type;
    bool found = false;
    ifstream doc_accounts("cuentas.csv", ios::in);
    ofstream outfile("cuentas_temp.csv");

    if (!doc_accounts) {
        cerr << "No se pudo abrir el archivo cuentas.csv" << endl;
        return;
    }

    while (getline(doc_accounts, data)) {
        stringstream registers(data);
        getline(registers, id, ',');
        getline(registers, name, ',');
        getline(registers, find_account, ',');
        getline(registers, account_type, ',');
        getline(registers, ammount, ',');
        getline(registers, expirate_date, ',');

        if (find_account == accountNumber) {
            found = true;
            cout << "Cuenta encontrada" << endl;
            cout << "Digite el nuevo nombre del propietario: " << endl;
            string new_name;
            cin.ignore(); // Ignorar el salto de línea pendiente
            getline(cin, new_name);
            cout << "Digite el nuevo tipo de cuenta (corriente o ahorros): " << endl;
            string new_account_type;
            getline(cin, new_account_type);
            outfile << id << "," << new_name << "," << find_account << "," << new_account_type << "," << ammount << "," << expirate_date << endl;
        } else {
            outfile << data << endl;
        }
    }

    doc_accounts.close();
    outfile.close();

    if (found) {
        remove("cuentas.csv");
        rename("cuentas_temp.csv", "cuentas.csv");
        cout << "Cuenta actualizada" << endl;
    } else {
        remove("cuentas_temp.csv");
        cout << "Cuenta no encontrada" << endl;
    }
}