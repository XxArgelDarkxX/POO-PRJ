#pragma once
#include <iostream>
#include <string>

using namespace std;

class PersonModel {

private:
  string name;
  int age;
  string id;

public:
  PersonModel(string id,string name, int age);
  string GetName();
  int GetAge();
  string GetId();
  virtual string ToString();
};
