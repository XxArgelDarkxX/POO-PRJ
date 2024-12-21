#include "../../include/service/AccountService.hpp"
#include "../../include/models/AccountModel.hpp"
#include "../../include/utils.hpp"
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// se inicializa la variable permiss para saber si se generar la transferencia
bool permiss = false;

AccountService::AccountService() {}

bool AccountService::Find(string find_) {
  string data, id, accountNumber, balance, expirate_date, name;

  bool dni_find = false;
  ifstream registers("cuentas.csv", ios::in);
  if (!registers) {
    cout << "documento no abierto" << endl;
    return false;
  }
  while (getline(registers, data)) {
    stringstream registers(data);
    getline(registers, id, ',');
    getline(registers, name, ',');
    getline(registers, accountNumber, ',');
    getline(registers, balance, ',');
    getline(registers, expirate_date, ',');

    if (accountNumber == find_) {

      return true;
    }
  }
  return false;
}


void AccountService::CreateAccount() {
  string owner;
  AccountModel account;
  string id = to_string(account.get_id());
  string accountNumber = gen_number(10);
  string balance = "0"; // Convertir el entero a cadena
  string expirate_date = "12/12/2030";

  cout << "Creando cuenta..." << endl;
  cout << "Ingrese el nombre del propietario: ";
  cin >> owner;

  ofstream doc_accounts("cuentas.csv", ios::app);
  if (!doc_accounts) {
    cerr << "No se pudo abrir el archivo cuentas.csv" << endl;
  } else {
    doc_accounts << id << "," << owner << "," << accountNumber << "," << balance
                 << "," << expirate_date << endl;
    doc_accounts.close();
  }
}

void AccountService::Deposit(string account_number, int _ammount) {
  int new_amount; // cantidad
  string data, id, name, find_account, ammount, expirate_date;
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
      getline(registers, ammount, ',');
      getline(registers, expirate_date, ',');

      if (find_account == account_number) {
        cout << "Cuenta encontrada" << endl;
        found = true;

        int new_amount_ = stoll(ammount);
        int new_balance = new_amount_ + _ammount;
        outfile << id << "," << name << "," << find_account << ","
                << to_string(new_balance) << "," << expirate_date << endl;

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

void AccountService::Withdraw(string account_number, int _ammount) {

  string data, id, name, find_account, ammount, expirate_date;
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
      getline(registers, ammount, ',');
      getline(registers, expirate_date, ',');

      if (find_account == account_number) {
        cout << "Cuenta encontrada" << endl;
        found = true;
        int new_amount_ = stoll(ammount);
        int new_balance = new_amount_ - _ammount;
        if (new_balance < 0) {
          cout << "Fondos insuficientes" << endl;
          permiss = false;
          return;
        }
        outfile << id << "," << name << "," << find_account << ","
                << to_string(new_balance) << "," << expirate_date << endl;

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
    permiss = true;
    cout << "retiro exitoso" << endl;
  } else {
    remove("cuentas_temp.csv");
    cout << "Cuenta no encontrada" << endl;
  }
}

void AccountService::Transfer() {
  string account_origin;
  cout << "digite su numero de cuenta: " << endl;
  cin >> account_origin;
  if (Find(account_origin)) {
    string account_destiny;
    cout << "digite el numero de cuenta al que quiere transferir: " << endl;
    cin >> account_destiny;
    if (Find(account_destiny)) {
      int amount;
      cout << "digite la cantidad que quiere transferir: " << endl;
      cin >> amount;
      Withdraw(account_origin, amount);
      if (permiss) {
        Deposit(account_destiny, amount);
      } else {
        cout << "Fondos insuficientes" << endl;
      }

    } else {
      cout << "Cuenta destino no encontrada" << endl;
    }
  }
}

vector<AccountModel> AccountService::LoadData(string number) {

  if(!Find(number)){
    cout << "no se encontro ninguna cuenta con el cliente" << endl;
    return {};
  }
  ifstream file("cuentas.csv");
  string line;
  vector<AccountModel> vec;
  while(getline(file,line)){
    auto data = split(line,',');
    if(data[0] == number){
    AccountModel account(line);
    vec.push_back(account);
    }
  }
  return vec;
}

