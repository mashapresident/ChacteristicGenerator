#include "Employee.h"
#include "Person.h"
#include "Characteristic.h"
#include "Degree.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits> // для numeric_limits
using namespace std;
namespace CharacteristicGenerator {
    Employee::~Employee() {}
    Employee::Employee() {}
    void Employee::set_inform() {
        int e;
        string educat, pos;
        if (this->is_male()) {
            cout << "Введіть досвід роботи у роках працівника ";
        } else {
            cout << "Введіть досвід роботи у роках працівниці ";
        }
        cout << this->get_fullname() << " : ";
        cin >> e;
        while (cin.fail() || e < 0 || e > this->get_age()) {
            cout << "От халепа! Щось пішло не так. Спробуйте ще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (is_male()) {
            cout << "Введіть досвід роботи у роках працівника ";
            } else {
               cout << "Введіть досвід роботи у роках працівниці ";
            }
            cout << this->get_fullname() << " : ";
            cin >> e;
        }
        experience = e;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Parser p;
        while (true) {
            cout << this->get_fullname() << " має освіту...\n"
                 << "(Старша школа/Бакалавр/Магістр/Доктор наук)\n";
            getline(cin, educat);
            if (p.parse_degree(educat, educ)) break;
            cout << "Спробуйте ще раз\n";
        }

        cout << get_fullname() << " працює на посаді : ";
        getline(cin, pos);
        position = pos;

        cout << "\nПерсональні дані успішно збережені!\n";
        this->charact.set_charact();
    }

    string Employee::who_is() {
        return is_male() ? "Працівник" : "Працівниця";
    }
    string Employee::whom() {
        return is_male() ? "Працівника" : "Працівниці";
    }

}
