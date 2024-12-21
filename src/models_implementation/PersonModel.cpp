#include "../../include/models/PersonModel.hpp"

using namespace std;

PersonModel::PersonModel(string id, string name, int age)
    : name(name), age(age), id(id) {}

string PersonModel::GetName() { return name; }

int PersonModel::GetAge() { return age; }

string PersonModel::GetId() { return id; }

string PersonModel::ToString() {
  return id + "," + name + "," + to_string(age);
}