#include "Student.h"
#include "Characteristic.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

namespace CharacteristicGenerator {
    Student::Student(){}
    Student::~Student(){}
    void Student::set_inform() {
        double gr;
        string spec;

        if (this->is_male()) {
            cout << "Введіть середній бал студента ";
        } else {
            cout << "Введіть середній бал студентки ";
        }
        cout << get_fullname() << " : ";
        cin >> gr;
        while (cin.fail() || gr < 60 || gr > 100) {
            cout << "Невірно введений бал. Будь ласка, введіть число в діапазоні від 0 до 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> gr;
        }
        grade = gr;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << get_fullname() << " вчиться на спеціальності : ";
        getline(cin, spec);
        specialization = spec;

        cout << "\nПерсональні дані успішно збережені!\n";
        charact.set_charact();
    }

    string Student::who_is() {
        return is_male() ? "Cтудент" : "Cтудентка";
    }
    string Student::whom() {
        return is_male() ? "Cтудента" : "Cтудентки";
    }
}
