#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <fstream>
#include <string>
#include "User.h"
namespace CharacteristicGenerator {
class Database {  
    std::vector<User> database;
    std::ifstream datafile;
    void load_users();
public:
    Database();
    ~Database();
    User &get_user_by_nickname(const std::string& nickname);
    bool verify_user(const std::string& nickname, const std::string& password);
};
}
#endif 
