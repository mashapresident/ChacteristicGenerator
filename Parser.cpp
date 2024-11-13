#include "Parser.h"
#include "Person.h"
#include "Employee.h"
#include "Student.h"
#include <string>
#include <sstream>
using namespace std;
namespace CharacteristicGenerator{
    string Parser::get_degree(Employee *em){
        if (em->educ == Degree::elemenrary) return "Старша школа";
        if (em->educ == Degree::bachelor) return "Вища неповна";
        if (em->educ == Degree::master) return "Вища";
        if (em->educ == Degree::doctoral) return "Доктор наук";
        return "";
    }
    string Parser::get_subject(Schoolkid* kid){
        if (kid->grade == Subject::biological) return "з нахилом на боілогію";
        if (kid->grade == Subject::phys_math) return "з нахилом на фізику та математику";
        if (kid->grade == Subject::economic) return "з нахилом на географію";
        if (kid->grade == Subject::inform_technology) return "з нахилом на інформатику";
        if (kid->grade == Subject::linguistic) return "з нахилом на мови";
        return "";
    }
    Parser::Parser(){}
    Parser::~Parser(){}
    bool Parser::parse_subject(const string& spec, Subject &grade) {
    if (spec == "Фізмат"){grade =  Subject::phys_math; return true;}
    if (spec == "Лінгвістичний"){grade =  Subject::linguistic; return true;}
    if (spec == "Біологічний"){grade =  Subject::biological; return true;}
    if (spec == "Економічний"){grade =  Subject::economic; return true;}
    if (spec == "Інформаційно-технологічний"){grade =  Subject::inform_technology; return true;}
    else return false;
    }

    bool Parser::parse_degree(const string& educ , Degree &education) {
        if (educ == "Старша школа"){education = Degree::elemenrary; return true;}
        if (educ == "Бакалавр"){education = Degree::bachelor; return true;}
        if (educ == "Магістр"){education = Degree::master; return true;}
        if (educ == "Доктор наук"){education = Degree::doctoral; return true;}
        return false;
    }
    string Parser::get_string(Person *p){
        Schoolkid* kid = dynamic_cast<Schoolkid*>(p);
        if (kid) return get_subject(kid);
        Employee *em = dynamic_cast<Employee *>(p);
        if (em) return get_degree(em);
        return "";   
    }
    vector<string> Parser::split(const string& input){
        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }
    bool Parser::get_point(string p, Point &point){
        if (p=="Чоловік"){point = Point::male ; return true;}
        else if(p=="Жінка"){point = Point::female; return true;}
        return false;
    }
}
