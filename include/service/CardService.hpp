#pragma once
#include "../models/CardModel.hpp"
#include "../utils.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CardService {
public:
  string filename = "cards.csv";
  CardService();
  // devuelve valor booleano si encuentra la tarjeta
  bool Find(string number);
  void Add(CardModel card);
  void Remove(string number);
  void Update(CardModel card);
  void Read();
  vector<CardModel> LoadData(string number);
};

