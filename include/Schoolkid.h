#ifndef SCHOOLKID_H
#define SCHOOLKID_H
#include "Person.h"
#include "Subject.h"
#include <string>
using namespace std;
namespace CharacteristicGenerator {
class Schoolkid : public Person {
public:
    Subject grade;
    double mark;
    Schoolkid();
    ~Schoolkid()override;
    virtual void set_inform() override;
    virtual std::string who_is() override;
    virtual std::string whom() override;
};
} 
#endif 
