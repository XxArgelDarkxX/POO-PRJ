#include "../../include/service/CardService.hpp"

CardService::CardService() {}

bool CardService::Find(string number) {
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    auto data = split(line, ',');
    if (data[0] == number) {
      return true;
    }
  }
  return false;
}

void CardService::Add(CardModel card) {
  ofstream file(filename, ios::app);
  file << card.ToString() << endl;
}

void CardService::Remove(string number) {
  ifstream file(filename);
  string line;
  vector<string> vec;
  while (getline(file, line)) {
    auto data = split(line, ',');
    if (data[0] == number)
      continue;
    vec.push_back(line);
  }
  ofstream file_write(filename);
  for (auto line : vec) {
    file_write << line << endl;
  }
}

void CardService::Update(CardModel card) {
  if (!Find(card.GetNumber())) {
    cout << "no se ha encontrado esa tarjeta que iba a actualizar" << endl;
    return;
  }
  Remove(card.GetNumber());
  Add(card);
}

void CardService::Read() {
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }
}

vector<CardModel> CardService::LoadData(string number) {
  vector<CardModel> vec;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    auto data = split(line, ',');
    if (data[0] == number) {
      CardModel card(line);
      vec.push_back(card);
    }
  }
  return vec;
}

