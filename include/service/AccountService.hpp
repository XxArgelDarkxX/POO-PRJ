#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;



class AccountService{

public:
    AccountService();
    void CreateAccount(); // crear cuenta
    void Deposit(string,int); // depositar
    void Withdraw(string,int); // retirar
    void Transfer(); // transferir
    bool find(string account_number); // buscar
    

   
};


