#include "../../include/models/BankModel.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

BancoModel::BancoModel()
{
}

void BancoModel::get_ganancias(){
    ifstream doc_earnings("ganancias.csv", ios::in);
    if (!doc_earnings) {
        cerr << "No se pudo abrir el archivo cuentas.csv" << endl;
        return;
    }

    string data;
    float totalEarnings = 0.0; // Inicializa las ganancias en 0

    while (getline(doc_earnings, data)) {
        stringstream registers(data);
        string earnings;
       
        getline(registers,earnings, ',');
        totalEarnings += stof(earnings);
    }
    cout << "Las ganancias totales del banco son: " << totalEarnings << endl;
    doc_earnings.close();
}