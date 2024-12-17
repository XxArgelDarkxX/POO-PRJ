#include "../../include/models/ClientModel.hpp"
using namespace std;

ClientModel::ClientModel(string id, string name, int age)
    : PersonModel(id, name, age) {}

ClientModel::ClientModel(string id, string name, int age,
                         vector<AccountModel> accounts, vector<CardModel> cards)
    : PersonModel(id, name, age), accounts(accounts), cards(cards) {}

string ClientModel::ToString() { return PersonModel::ToString(); }

void ClientModel::ShowInfo() {
  cout << "nombre:" << GetName() << endl;
  cout << "edad:" << GetAge() << endl;
  cout << "id:" << GetId() << endl;
}

vector<AccountModel> ClientModel::GetAccounts() { return accounts; }

vector<CardModel> ClientModel::GetCards() { return cards; }

