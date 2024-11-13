#ifndef SAMPLE_H
#define SAMPLE_H
#include <fstream>
#include "Person.h"
#include "Schoolkid.h"
#include "Student.h"
#include "User.h"
#include "Employee.h"

namespace CharacteristicGenerator {
class Sample {
    std::ifstream kidSample;
    std::ifstream studSample;
    std::ifstream emplSample;
    void kid_fill(Schoolkid *kid, User &user);
    void stud_fill(Student *st, User &user);
    void empl_fill(Employee *empl, User &user);
public:
    Sample();
    ~Sample();
    void fillfile(Person *person, User &user);
};
} 
#endif 