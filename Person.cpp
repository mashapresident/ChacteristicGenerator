#include "Person.h"
#include "Point.h"
#include "Parser.h"
#include <string>
#include <iostream>

using namespace std;
namespace CharacteristicGenerator{
Person::Person(){}
Person::~Person(){}
void Person::set_data(){
    Parser p;
    string input;
    cout << "Введіть ПІБ людини,для якої робимо характеристику : ";
    getline(cin, input);
    vector<string> parts = p.split(input);
    while(parts.size() != 3){
        cout << "Дані неправильно введено.Спробуйте ще раз\n";
        getline(cin, input);
        parts = p.split(input);
    }
    surname = parts[0];
    name = parts[1];
    patronymic = parts[2];
    int a;
    cout << "Введіть вік : ";
    cin >> a;
    while(a > 90 || a < 6){
        cout << "Дані неправильно введено.Спробуйте ще раз\n";
        cin >> a;
    }
    age = a;
    cin.ignore();
    Point mf;
    cout << "Введіть стать(Чоловік/Жінка) : ";
    getline(cin, input);
    while(!p.get_point(input, mf)){
        cout << "Дані неправильно введено.Спробуйте ще раз\n";
        getline(cin, input);
    }
    s = mf;

}    
bool Person::is_male(){
    return s == Point::male;
}
string Person::get_fullname() const {
    return surname + " " + name + " " + patronymic;
}
string Person::get_fullname_sk() const {
    return surname + name + patronymic;
}
string Person::get_name() const {
    return name;
}
string Person::get_surname_and_name() const {
    return surname + " " + name;
}
int Person::get_age() const {
    return age;
}
}