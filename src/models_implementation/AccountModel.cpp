#include "../../include/models/AccountModel.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
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

AccountModel::AccountModel(string id_, string owner, string accountNumber,
                           float balance) {
  owner_name = owner;
  this->accountNumber = accountNumber;
  this->balance = balance;
  id_ = load_id();
}

AccountModel::AccountModel(){}

// id,nombre,numero_cuenta,fondo,expiracion,id_cliente
AccountModel::AccountModel(string line_file) {
  auto data = split(line_file, ',');
  id = stoi(data[0]);
  owner_name = data[1];
  accountNumber = data[2];
  balance = stoi(data[3]);
  expirate_Date = data[4];
  id_client = data[5];
}

int AccountModel::get_id() { return id; }

// metodos getters
float AccountModel::GetBalance() { return balance; }

string AccountModel::GetOwner() { return owner_name; }

string AccountModel::GetAccountNumber() { return accountNumber; }

string AccountModel::GetExpirateDate() { return expirate_Date; }

string AccountModel::getinfo() {
  return "Owner: " + owner_name + " Account Number: " + accountNumber +
         "Balance: " + to_string(balance);
}

// metodos setters

void AccountModel::SetBalance(float balance) { this->balance = balance; }

void AccountModel::SetOwner(string owner) { owner_name = owner; }

void AccountModel::SetAccountNumber(string accountNumber) {
  this->accountNumber = accountNumber;
}

void AccountModel::SetExpirateDate(string expirate_Date) {
  this->expirate_Date = expirate_Date;
}

