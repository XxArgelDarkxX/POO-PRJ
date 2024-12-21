#pragma once
#include "../models/AccountModel.hpp"
#include "../utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class AccountService {

public:
  AccountService();
  void CreateAccount();             // crear cuenta
  void Deposit(string, int);        // depositar
  void Withdraw(string, int);       // retirar
  void Transfer();                  // transferir
  bool Find(string account_number); // buscar
  vector<AccountModel> LoadData(string number);
};
