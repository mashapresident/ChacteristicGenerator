#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Degree.h"
#include "Person.h"
namespace CharacteristicGenerator{
class Employee : public Person{
public:
    int experience;
    std::string position;
    Degree educ;
    Employee();
    ~Employee()override;
    virtual void set_inform() override;
    virtual std::string who_is() override;
    virtual std::string whom() override;
};
} 
#endif 
