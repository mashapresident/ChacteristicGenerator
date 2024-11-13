#ifndef USER_H
#define USER_H
#include <string>
#include <sstream>
namespace CharacteristicGenerator {
class User {
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string password;
    std::string nickname;
public:
    User(const std::string& line);
    std::string get_name() const;
    std::string get_surname() const ;
    std::string get_patronymic() const;
    std::string get_password() const ;
    std::string get_nickname() const;
};
}
#endif 
