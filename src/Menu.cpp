#include "Schoolkid.h"
#include "Student.h"
#include "Employee.h"
#include "Parser.h"
#include "Database.h"
#include "Sample.h"
#include "Menu.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
namespace CharacteristicGenerator {
Menu::Menu() {} 
void Menu::start_menu() {
    Database db;
    Parser p;
    cout << "Вітаємо в Генераторі характеристик!\nДля початку введіть логін та пароль з вашого акаунту через пробіл\n";
    string input;
    getline(cin, input);
    vector<string> credentials = p.split(input); 
    while (credentials.size() != 2 || !db.verify_user(credentials[0], credentials[1])) {
        cout << "Дані, що ви їх ввели є некоректними, спробуйте ще раз\n";
        getline(cin, input);  
        credentials = p.split(input); 
    }
    User user = db.get_user_by_nickname(credentials[0]);
    cout << "Верифікація пройшла успішно!\n";
    show_menu(user);
}

void Menu::show_menu(User &user) {
    int choice;
    while (true) {
        cout << "Меню\n   1.Створити характеристику\n   2.Переглянути характеристику\n   3.Завершити роботу\nВаш вибір (1/2/3) -> ";
        cin >> choice;
        cin.ignore(); 
        switch(choice) {
            case 1:
                create_charact(user);
                break;
            case 2:
                check_charact();
                break;
            case 3:
                cout << "Дякуємо за користуванням Генератором Характеристик!\n";
                exit(0);
            default:
                cout << "Дані неправильно введено. Спробуйте ще раз\n";
                break;
        }
    }
}

void Menu::create_charact(User &user) {
    Person *p = nullptr; 
    string choice;
    cout << "Для кого характеристика? (Школяр/Студент/Працівник): ";
    cin >> choice;
    cin.ignore(); 
    if (choice == "Школяр") {
        p = new Schoolkid();
    } else if (choice == "Студент") {
        p = new Student();
    } else if (choice == "Працівник") {
        p = new Employee();
    } else {
        cout << "Дані неправильно введено. Спробуйте ще раз\n";
        create_charact(user);
        return;
    }

    if (Schoolkid* schoolkid = dynamic_cast<Schoolkid*>(p)) {
        schoolkid->set_data();
        schoolkid->set_inform();
    } else if (Student* student = dynamic_cast<Student*>(p)) {
        student->set_data();
        student->set_inform();
    } else if (Employee* employee = dynamic_cast<Employee*>(p)) {
        employee->set_data();
        employee->set_inform();
    }
    Sample sam;
    sam.fillfile(p,user);
    delete p; 
}
void Menu::check_charact() {
    Parser p;
    string str;
    cout << "Введіть ПІБ людини, чию характеристику Ви хочете продивитись: ";
    getline(cin, str);
    vector<string> parts = p.split(str);
    
    while(parts.size() != 3) {
        cout << "Дані неправильно введено. Спробуйте ще раз\n";
        getline(cin, str);
        parts = p.split(str);
    }

    cout << "Чия це характеристика(Школяр/Студент/Працівник): ";
    getline(cin, str);

    string filename;
    while (!(str == "Школяр" || str == "Студент" || str == "Працівник")) {
        cout << "Дані неправильно введено. Спробуйте ще раз\n";
        cout << "Чия це характеристика(Школяр/Студент/Працівник): ";
        getline(cin, str);
    }

    if (str == "Школяр") {
        filename = parts[0] + parts[1] + parts[2] + "Ш.txt";
    } else if (str == "Студент") {
        filename = parts[0] + parts[1] + parts[2] + "С.txt";
    } else if (str == "Працівник") {
        filename = parts[0] + parts[1] + parts[2] + "П.txt";
    }

    ifstream file_to_check(filename);
    if (!file_to_check) {
        cout << "Файл не знайдено\n";
        return;
    }
    string line;
    while (getline(file_to_check, line)) {
        cout << line << '\n';
    }
    file_to_check.close();

    int choice;
    cout << "\n  1. Повернутись до меню\n  2. Видалити характеристику\nВаш вибір -> ";
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cout << "Спробуйте ще раз\n";
        cout << "\n  1. Повернутись до меню\n  2. Видалити характеристику\nВаш вибір -> ";
        cin >> choice;
    }

    switch (choice) {
        case 1:
            return;
        case 2:
            if (remove(filename.c_str()) != 0) {
                perror("Помилка видалення файлу");
            } else {
                cout << "Характеристика видалена\n";
            }
            break;
    }
    }
}