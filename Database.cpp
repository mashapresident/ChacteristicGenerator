#include "Database.h"
#include "User.h"
#include <iostream>
#include <string>
namespace CharacteristicGenerator {
Database::Database() : datafile("user_database.txt", std::ios::in) {
    if (!datafile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    load_users();
}
Database::~Database() {
    if (datafile.is_open()) {
        datafile.close();
    }
}
void Database::load_users() {
    std::string line;
    while (std::getline(datafile, line)) {
        User user(line);
        database.push_back(user);
    }
}
User &Database::get_user_by_nickname(const std::string& nickname) {
    for (User& user : database) {
        if (user.get_nickname() == nickname) {
            return user;
        }
    }
    throw std::runtime_error("User not found");
}
bool Database::verify_user(const std::string& nickname, const std::string& password) {
    try {
        User to_check = get_user_by_nickname(nickname);
        return to_check.get_password() == password;
    } catch (const std::runtime_error& e) {
        return false;
    }
}
} 
