#include "../../include/service/ClientService.hpp"
#include "../../include/utils.hpp"
#include <iostream>
using namespace std;

// constructor
ClientService::ClientService() {}

/*metodo de busqueda de un cliente
 * @param string id: el id del cliente que se va a buscar
 * @return bool*/
bool ClientService::Find(string id) {
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    auto data = split(line, ',')[0];
    if (data == id) {
      return true;
    }
  }
  return false;
}

/* metodo de agregar a un cliente a la db
 * @param ClientModel client: este es un modelo de cliente
 * @return void*/
void ClientService::Add(ClientModel client) {
  if (Find(client.GetId())) {
    cout << "el cliente ya existe no es posible que sea agregado" << endl;
    return;
  }
  ofstream file(filename, ios::app);
  file << client.ToString() << endl;
}

void ClientService::Update(ClientModel client) {
  if (Find(client.GetId())) {
    Remove(client.GetId());
    Add(client);
  } else {
    cerr << "no se encontro el cliente a actualizar" << endl;
  }
}

/* metodo de eliminacion de un cliente de la db
 * @param string id: el id del cliente que se va a eliminar
 * @return void*/
void ClientService::Remove(string id) {
  ifstream file_read(filename);
  string line;
  vector<string> lines;
  while (getline(file_read, line)) {
    auto data = split(line, ',')[0];
    if (data != id) {
      lines.push_back(line);
    }
  }
  ofstream file_write(filename);
  for (auto line : lines) {
    file_write << line << endl;
  }
}

/* metodo de lectura de la db
 * @return void*/
void ClientService::Read() {
  ifstream file(filename);
  string line;
  getline(file, line);
  cout << line << endl;
  cout << "__________________________" << endl;
  while (getline(file, line)) {
    auto data = split(line, ',');
    string id, name, age;
    id = data[0];
    name = data[1];
    age = data[2];
    cout << "id: " << id << " name: " << name << " age: " << age << endl;
  }
  cout << "__________________________" << endl;
}

/* carga los datos de algun cliente a tiempo de ejecucion
 * se debe de utilizar el find para verificar si el cliente existe
 * antes de usar este metodo
 * @param int id: el id del cliente del cual se cargan los datos
 * @return ClientModel un modelado del cliente con los datos del db*/
ClientModel ClientService::LoadData(string id) {
  AccountService account_service;
  CardService card_service;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    auto data = split(line, ',');
    if (data[0] == id) {
      string id = data[0];
      string name = data[1];
      int age = stoi(data[2]);
      // meter que cargue los vectores
      vector<AccountModel> accounts = account_service.LoadData(id);
      vector<CardModel> cards = card_service.LoadData(id);
      return ClientModel(id, name, age, accounts, cards);
    }
  }
}
