#ifndef PERSON_H
#define PERSON_H
#include "Characteristic.h"
#include "Point.h"
#include <string>
using namespace std;
namespace CharacteristicGenerator{

class Person{
    std::string name, surname, patronymic;
    int age;
    Point s;
public:
    Characteristic charact;
    bool is_male();
    std::string get_name()const;
    std::string get_surname_and_name()const;
    std::string get_fullname()const;
    std::string get_fullname_sk()const;
    int get_age()const;
    Person();
    virtual ~Person() = 0;
    void set_data();      // для загальної інф(ПІБ вік стать)
    virtual void set_inform() = 0;  // для додаткової інф
    virtual std::string who_is() = 0;
    virtual std::string whom() = 0;

};
} 
#endif 
