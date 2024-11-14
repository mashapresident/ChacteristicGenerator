#ifndef PARSER_H
#define PARSER_H
#include "Subject.h"
#include "Degree.h"
#include "Person.h"
#include "Employee.h"
#include "Schoolkid.h"
#include <string>
#include "Point.h"
#include <vector>
using namespace std;
namespace CharacteristicGenerator {
class Parser {
    string get_degree(Employee *em);
    string get_subject(Schoolkid *kid);
public:
    Parser();
    ~Parser();
    bool parse_subject(const string& spec, Subject &grade);
    bool parse_degree(const string& educ , Degree &education);
    string get_string(Person *p);
    vector<string> split(const string& input);
    bool get_point(string p, Point &point);
};
}
#endif
