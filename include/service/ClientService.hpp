#pragma once
#include "../models/ClientModel.hpp"
#include "AccountService.hpp"
#include "CardService.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ClientService{
public:
  string filename = "db/clientes.csv";
  ClientService();
  bool Find(string id);
  void Remove(string id);
  void Update(ClientModel client);
  void Read();
  void Add(ClientModel client);
  ClientModel LoadData(string id);
};
