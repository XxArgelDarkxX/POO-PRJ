#include "../../include/utils.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <random>

using namespace std;

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string gen_number(int digits){
  std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 9);

    std::string numero = "";
    for (int i = 0; i < digits; ++i) {
        numero += std::to_string(distrib(gen));
    }
    return numero;
}

