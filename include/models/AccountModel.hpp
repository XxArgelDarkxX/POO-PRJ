#pragma once
#include <iostream>
#include <string>
using namespace std;


class AccountModel {
private:
  int balance; // fondo
  int id;
  string owner_name; // nombre del propietario
  string accountNumber; //numero de cuenta
  string AccountType; // tipo de cuenta
  string expirate_Date; // fecha de expiracion
  

public:
  AccountModel(string id, string owner,string accountNumber,string type_account, float balance);
  AccountModel();
  float GetBalance(); //get_fondos
  int get_id(); //get_id
  string GetOwner();  //get_propietario
  string GetAccountNumber();  //get_numero_cuenta
  string GetExpirateDate(); //get_fecha_expiracion
  string getinfo(); //get_info
  void SetBalance(float balance); //set_fondos
  void SetOwner(string owner); //set_propietario
  void SetAccountNumber(string accountNumber); //set_numero_cuenta
  void SetType(string AccountType ); //set_tipo_Cuenta
  void SetExpirateDate(string expirate_Date); //set_fecha_expiracion
  
  string to_String(); //to_string
  
  //metodos crud
  void delete_account(string ); //eliminar_cuenta
  void update_account(string); //actualizar_cuenta


};
