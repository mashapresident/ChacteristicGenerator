#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Point.h"
using namespace std;
namespace CharacteristicGenerator{

class Student : public Person{
public:
    double grade;
    string specialization;
    Student();
    ~Student()override;
    virtual void set_inform() override;
    virtual std::string who_is() override;
    virtual std::string whom() override;
};
} 
#endif 
