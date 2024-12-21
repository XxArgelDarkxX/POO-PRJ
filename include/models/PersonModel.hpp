#pragma once
#include <iostream>
#include <string>

class PersonModel {

private:
  std::string name;
  int age;
  int id;

public:
  PersonModel(int id,std::string name, int age);
  std::string GetName();
  int GetAge();
  int GetId();
  virtual std::string ToString();
};
