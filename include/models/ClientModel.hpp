#pragma once
#include "PersonModel.hpp"
#include "AccountModel.hpp"
#include "CardModel.hpp"
#include <string>
#include <vector>

using namespace std;

class ClientModel : public PersonModel {

private:

  vector<AccountModel> accounts;
  vector<CardModel> cards;

public:
  ClientModel(string id,string name, int age);
  ClientModel(string id, string name, int age, vector<AccountModel> accounts, vector<CardModel> cards);


  string ToString() override;
  void ShowInfo();
  vector<AccountModel> GetAccounts();
  vector<CardModel> GetCards();
};
