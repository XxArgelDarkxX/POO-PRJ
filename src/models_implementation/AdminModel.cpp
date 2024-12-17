#include "../../include/models/AdminModel.hpp"
#include <iostream>

AdminModel::AdminModel() {}

std::string AdminModel::getUsername() {
    return username;
}

std::string AdminModel::getPassword() {
    return password;
}
