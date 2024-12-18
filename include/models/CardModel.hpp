#pragma once
#include "../utils.hpp"
#include <iostream>
#include <string>

using namespace std;

class CardModel {

private:
  string expire_date = "12/12/2030"; // fecha de expiracion
  string number;                     // numero de la tarjeta
  string cvv;                        // pin de la cuenta
  int balance;                       // dinero de la cuenta
  string name;
  string id_client;

public:
  CardModel(int balance, string id_client, string name);
  CardModel(string line);
  string GetNumber();
  string GetCvv();
  int GetBalance();
  string GetExpireDate();
  string GetIdClient();
  string ToString();
  void ShowInfo();

  void LowerBalance(int amount); // subir valor
  void UpperBalance(int amount); // bajar valor
};

