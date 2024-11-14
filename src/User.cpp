#include "User.h"
#include <sstream>
namespace CharacteristicGenerator{
User::User(const std::string& line) {
    std::istringstream ss(line);
    ss >> name >> surname >> patronymic >> password >> nickname;
}
std::string User::get_name() const { return name; }
std::string User::get_surname() const { return surname; }
std::string User::get_patronymic() const { return patronymic; }
std::string User::get_password() const { return password; }
std::string User::get_nickname() const { return nickname; }
}