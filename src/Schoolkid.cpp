#include "Schoolkid.h"
#include <iostream>
#include <string>
#include "Parser.h"
#include "Characteristic.h"
using namespace std;
namespace CharacteristicGenerator{
Schoolkid::Schoolkid(){}
void Schoolkid::set_inform() {
        double mrk;
        string grd;

        if (is_male()) {
            cout << "Введіть середній бал учня ";
        } else {
            cout << "Введіть середній бал учениці ";
        }
        cout << get_fullname() << " : ";
        cin >> mrk;
        while (cin.fail() || mrk < 0 || mrk > 12) {
            cout << "Невірно введений бал. Будь ласка, введіть число в діапазоні від 0 до 12: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> mrk;
        }
        mark = mrk;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Parser p;
        while (true) {
            cout << get_fullname() << " вчиться в класі з нахилом...\n"
                 << "(Фізмат/Лінгвістичний/Біологічний/Економічний/Інформаційно-технологічний)\n";
            getline(cin, grd);
            if (p.parse_subject(grd, grade)) {
                break;
            }
            cout << "Спробуйте ще раз\n";
        }

        cout << "\nПерсональні дані успішно збережені!\n";
        this->charact.set_charact();
    }
string Schoolkid::who_is(){
    return is_male()? "Учень" : "Учениця";
}
string Schoolkid::whom(){
    return is_male()? "Учня" : "Учениці";
}
Schoolkid::~Schoolkid() {}
}