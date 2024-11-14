#include "Sample.h"
#include "Person.h"
#include "User.h"
#include "Schoolkid.h"
#include "Parser.h"
#include "Student.h"
#include "Employee.h"
#include "Sample.h"
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;
namespace CharacteristicGenerator{
    Sample::Sample(){
        kidSample.open("samples/Schoolkid_Sample.txt");
        studSample.open("samples/Student_Sample.txt");
        emplSample.open("samples/Employee_Sample.txt");
    }
    Sample::~Sample(){
        kidSample.close();
        studSample.close();
        emplSample.close();
    }


    void Sample::fillfile(Person *person, User &user) {
    Schoolkid* kid = dynamic_cast<Schoolkid*>(person);
    if (kid) kid_fill(kid, user); 

    Student* student = dynamic_cast<Student*>(person);
    if (student) stud_fill(student, user);

    Employee* employee = dynamic_cast<Employee*>(person);
    if (employee) empl_fill(employee, user);

    }
    
    void Sample::empl_fill(Employee *empl, User &user){
        char ch;                                           //символ що ми зчитуватимемо
        string replacement;                                //строка що ми вставлятимемо в пропуск
        int i = 0;                                         //порядковий номер пропуску
        time_t currentTime = time(nullptr);                //для дати
        tm* localTime = localtime(&currentTime);           //для дати
        stringstream ss;                                   //для дати
        string filename = empl->get_fullname_sk() + "П.txt";  //імʼям текстового файлу з характеристикою буде ПІБ людини ( п для позначки що це працівник)
        Parser p; 
        ofstream empl_file(filename);
        while (emplSample.get(ch)){
            if (ch != '_') empl_file.put(ch);
            else {
                if(i == 0)        replacement = empl->whom();
                else if (i == 1)  replacement = empl->get_fullname();
                else if (i == 2)  replacement = to_string(empl->get_age());
                else if (i == 3 || i == 9)  replacement = empl->position;
                else if (i == 4)  replacement = p.get_string(empl);
                else if (i == 5 || i == 7 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 22 || i == 35) replacement = empl->get_name();
                else if (i == 7 || i == 13) replacement = empl->is_male() ? "Він" : "Вона";
                else if (i == 25) replacement = empl->get_surname_and_name();
                else if (i == 8)  replacement = to_string(empl->experience); 
                else if(i == 27){
                    ss.str("");
                    ss << setfill('0') << setw(2) << localTime->tm_mday << "." 
                    << std::setw(2) << localTime->tm_mon + 1 << "." 
                    << localTime->tm_year + 1900;
                    replacement = ss.str();
                }
                else if(i == 28){replacement = user.get_surname() + " " + user.get_name() + " " + user.get_patronymic();}

                if (empl->charact.responsible <= 3){
                    if(i == 5)      replacement += empl->is_male() ? " є безвідповідальним працівником" : " є безвідповідальною працівницею";
                    else if(i == 6) replacement = "низький";
                    else if(i == 7) replacement += " несерйозно";
                    else if(i == 10) replacement += " ніколи не";
                    else if(i == 11) replacement = " низьку";
                    
                }
                else if(empl->charact.responsible > 3 && empl->charact.responsible <= 7){
                    if(i == 5)      replacement += empl->is_male() ? " є достатньо відповідальним працівником" : " є достатньо відповідальною працівницею";
                    else if(i == 6) replacement = "середній";
                    else if(i == 7) replacement += " достатньо серйозно";
                    else if(i == 10) replacement += " рідко";
                    else if(i == 11) replacement = "середню";
                }
                else if(empl->charact.responsible > 7){
                    if(i == 5)      replacement += empl->is_male() ? " є дуже відповідальним працівником" : " є дуже відповідальною працівницею";
                    else if(i == 6) replacement = "високий";
                    else if(i == 7) replacement += " дуже серйозно";
                    else if(i == 10) replacement += " завжди";
                    else if(i == 11) replacement = "високу";
                }
                
                if(empl->charact.hardworking <= 3){
                    if(i == 12) replacement += " демонструє низький";
                    else if(i == 13) replacement = "ніколи не";
                }
                else if(empl->charact.hardworking > 3 && empl->charact.hardworking <= 7){
                    if(i == 12) replacement += " демонструє середній";
                    else if(i == 13) replacement = "часто";
                }
                else if(empl->charact.hardworking > 7){
                    if(i == 12) replacement += " демонструє високий";
                    else if(i == 13) replacement = "завджи";
                }
                
                if(empl->charact.timemanager <= 3){
                    if(i == 14) replacement += " нераціонально";
                    else if(i == 15) replacement = "не";
                    else if(i == 16) replacement += " володіє поганими";
                    else if(i == 17) replacement = "не планує свій час, не";
                }
                else if(empl->charact.timemanager > 3 && empl->charact.timemanager <= 7){
                    if(i == 14) replacement += " достатньо раціонально";
                    else if(i == 15) replacement = "часто ";
                    else if(i == 16) replacement += " володіє достатньо непоганими";
                    else if(i == 17) replacement = "достатньо вміло планує свій час, іноді";
                }
                else if(empl->charact.timemanager > 7){
                    if(i == 14) replacement += " максимально раціонально";
                    else if(i == 15) replacement = "";
                    else if(i == 16) replacement += " володіє високими";
                    else if(i == 17) replacement = "вміло планує свій час, завжди";
                }
                if(empl->charact.communicator <= 3){
                    if(i == 18) replacement += " має погані";
                    else if(i == 19) replacement = "не вміє";
                    else if(i == 20) replacement = "взагалі не";
                    else if(i == 21) replacement = "заважає";
                }
                else if(empl->charact.communicator > 3 && empl->charact.communicator <= 7){
                    if(i == 18) replacement += " має непогані";
                    else if(i == 19) replacement = " іноді може";
                    else if(i == 20) replacement = "іноді";
                    else if(i == 21) replacement = "може сприяти";
                }
                else if(empl->charact.communicator > 7){
                    if(i == 18) replacement += " має чудові";
                    else if(i == 19) replacement = " вміє вдало";
                    else if(i == 20) replacement = "активно";
                    else if(i == 21) replacement = "активно сприяє";
                }
                
                if(empl->charact.quality <= 3){
                    if(i == 22) replacement += " не є цінним";
                    else if(i == 23) replacement = "мінімальний";
                    else if(i == 24) replacement = "демотивує"; 
                }
                else if(empl->charact.quality > 3 && empl->charact.quality <= 7){
                    if(i == 22) replacement += " є середнім по цінності";
                    else if(i == 23) replacement = "певний";
                    else if(i == 24) replacement = "може мотивувати";
                }
                else if(empl->charact.quality > 7){
                    if(i == 22) replacement += " є дуже цінним";
                    else if(i == 23) replacement = "значний";
                    else if(i == 24) replacement = "надихає та мотивує";
                }

                if(empl->charact.skip <= 3){
                    if(i == 25)  replacement = empl->is_male() ? " майже не пропускав робочі дні ,тому" : " майже не пропускала робочі дні ,тому";
                    if(i == 26)  replacement = "зовсім не";
                }
                else if(empl->charact.skip > 3 && empl->charact.skip <= 8){
                    if(i == 25)  replacement += empl->is_male() ? " іноді пропускав робочі дні ,тому" : " іноді пропускала робочі дні ,тому";
                    if(i == 26)  replacement = "майже не";
                }
                else if(empl->charact.skip > 7){
                    if(i == 25)  replacement += empl->is_male() ? " часто пропускав робочі дні ,тому" : " часто пропускала робочі дні ,тому";
                    if(i == 26)  replacement = "значно";
                }
            empl_file << replacement;
            i++;
            }
        }
        empl_file.close();
    }
    void Sample::stud_fill(Student *st, User &user){
        char ch;                                           //символ що ми зчитуватимемо
        string replacement;                                //строка що ми вставлятимемо в пропуск
        int i = 0;                                         //порядковий номер пропуску
        time_t currentTime = time(nullptr);                //для дати
        tm* localTime = localtime(&currentTime);           //для дати
        stringstream ss;                                   //для дати
        string filename = st->get_fullname_sk() + "С.txt";  //імʼям текстового файлу з характеристикою буде ПІБ людини ( с для позначки що це студент)
        ofstream st_file(filename);
        while (studSample.get(ch)){
            if (ch != '_') st_file.put(ch);
            else {
                if(i == 0)        replacement = st->whom();
                else if (i == 1)  replacement = st->get_fullname();
                else if (i == 2)  replacement = to_string(st->get_age());
                else if (i == 3)  replacement = st->specialization;
                else if (i == 4 || i == 7 || i == 10 || i == 12 || i == 16 || i == 19) replacement = st->get_name();
                else if (i == 5 || i == 13) replacement = st->is_male() ? "Він" : "Вона";
                else if (i == 21) replacement = st->get_surname_and_name();

                else if(i == 22){ss << fixed << setprecision(1) << st->grade; replacement = ss.str();}
                else if(i == 23){
                    ss.str("");
                    ss << setfill('0') << setw(2) << localTime->tm_mday << "." 
                    << std::setw(2) << localTime->tm_mon + 1 << "." 
                    << localTime->tm_year + 1900;
                    replacement = ss.str();
                }
                else if(i == 24){replacement = user.get_surname() + " " + user.get_name() + " " + user.get_patronymic();}

                if (st->charact.responsible <= 3){
                    if(i == 4)      replacement += st->is_male() ? " є безвідповідальним студентом, що не" : " є безвідповідальною студенткою, що не";
                    else if(i == 5) replacement += " несерйозно";
                    else if(i == 6) replacement = "майже ніколи не";
                    
                }
                else if(st->charact.responsible > 3 && st->charact.responsible <= 7){
                    if(i == 4)      replacement += st->is_male() ? " є достатньо відповідальним студентом, що іноді" : " є достатньо відповідальною студенткою, що іноді";
                    else if(i == 5) replacement += " достатньо серйозно";
                    else if(i == 6) replacement = "майже завжди";
                }
                else if(st->charact.responsible > 7){
                    if(i == 4)      replacement += st->is_male() ? " є дуже відповідальним студентом, що завжди" : " є дуже відповідальною студенткою, що завжди";
                    else if(i == 5) replacement += " дуже серйозно";
                    else if(i == 6) replacement = "завжди";
                }
                
                if(st->charact.hardworking <= 3){
                    if(i == 7)      replacement += " демонструє низький"; 
                    else if(i == 8) replacement = "Неохоче";
                    else if(i == 9) replacement = "ніколи не";
                }
                else if(st->charact.hardworking > 3 && st->charact.hardworking <= 7){
                    if(i == 7)      replacement += " демонструє середній"; 
                    else if(i == 8) replacement = "Охоче";
                    else if(i == 9) replacement = "іноді";
                }
                else if(st->charact.hardworking > 7){
                    if(i == 7)      replacement += " демонструє високий"; 
                    else if(i == 8) replacement = "Завжди охоче та завзято";
                    else if(i == 9) replacement = "активно";
                }
                
                if(st->charact.timemanager <= 3){
                    if(i == 10)      replacement += " володіє поганими";
                    else if(i == 11) replacement = "не планує свій час, не може";
                }
                else if(st->charact.timemanager > 3 && st->charact.timemanager <= 7){
                    if(i == 10)      replacement += " володіє достатньо непоганими";
                    else if(i == 11) replacement = "достатньо вміло планує свій час, може";
                }
                else if(st->charact.timemanager > 7){
                    if(i == 10)      replacement += " володіє високими";
                    else if(i == 11) replacement = "вміло планує свій час, завжди встигає";
                }
            
                if(st->charact.communicator <= 3){
                    if(i == 12) replacement += " має погані";
                    else if(i == 13) replacement += " не вміє";
                    else if(i == 14) replacement = "взагалі не";
                    else if(i == 15) replacement = "погіршенню";
                }
                else if(st->charact.communicator > 3 && st->charact.communicator <= 7){
                    if(i == 12) replacement += " має непогані";
                    else if(i == 13) replacement += " іноді може";
                    else if(i == 14) replacement = "іноді";
                    else if(i == 15) replacement = "нормалізації";
                }
                else if(st->charact.communicator > 7){
                    if(i == 12) replacement += " має чудові";
                    else if(i == 13) replacement += " вміє вдало";
                    else if(i == 14) replacement = "активно";
                    else if(i == 15) replacement = "поліпшенню";
                }
                
                if(st->charact.quality <= 3){
                    if(i == 16) replacement += " не є цінним";
                    else if(i == 17) replacement = "мінімальний";
                    else if(i == 18) replacement = "демотивує"; 
                }
                else if(st->charact.quality > 3 && st->charact.quality <= 7){
                    if(i == 16) replacement += " є середнім по цінності";
                    else if(i == 17) replacement = "певний";
                    else if(i == 18) replacement = "може мотивувати";
                }
                else if(st->charact.quality > 7){
                    if(i == 16) replacement += " є дуже цінним";
                    else if(i == 17) replacement = "значний";
                    else if(i == 18) replacement = "надихає та мотивує";
                }

                if(st->charact.skip <= 3){
                    if(i == 19)  replacement += st->is_male() ? " майже не пропускав навчальні дні ,тому" : " майже не пропускала навчальні дні ,тому";
                    if(i == 20)  replacement = "зовсім не";
                }
                else if(st->charact.skip > 3 && st->charact.skip <= 8){
                    if(i == 19)  replacement += st->is_male() ? " іноді пропускав навчальні дні ,тому" : " іноді пропускала навчальні дні ,тому";
                    if(i == 20)  replacement = "майже не";
                }
                else if(st->charact.skip > 7){
                    if(i == 19)  replacement += st->is_male() ? " часто пропускав навчальні дні ,тому" : " часто пропускала навчальні дні ,тому";
                    if(i == 20)  replacement = "значно";
                }
            st_file << replacement;
            i++;
            }
        }
        st_file.close();
    }
    void Sample::kid_fill(Schoolkid *kid, User &user){
        char ch;                                           //символ що ми зчитуватимемо
        string replacement;                                //строка що ми вставлятимемо в пропуск
        int i = 0;                                         //порядковий номер пропуску
        time_t currentTime = time(nullptr);                //для дати
        tm* localTime = localtime(&currentTime);           //для дати
        stringstream ss;                                     //для отримання нахилу класу
        string filename = kid->get_fullname_sk() + "Ш.txt"; // ш для позначки що це школяр
        ofstream kid_file(filename);
        Parser p;
        while (kidSample.get(ch)){
            if (ch != '_') kid_file.put(ch);
            else {
                if(i == 0)        replacement = kid->whom();
                else if (i == 1)  replacement = kid->get_fullname();
                else if (i == 2)  replacement = to_string(kid->get_age());
                else if (i == 4)  {replacement = kid->is_male() ? "закінчив клас " : "закінчила клас ";replacement += p.get_string(kid);}
                else if (i == 5){ss << fixed << setprecision(1) << kid->mark; replacement = ss.str();}
                else if (i == 3 || i == 9 || i == 12 || i == 14 || i == 19 || i == 23) replacement = kid->get_name();
                else if (i == 6 || i == 17 || i == 21) replacement = kid->is_male() ? "Він" : "Вона";
                else if (i == 5 || i == 13) replacement = kid->is_male() ? "Він" : "Вона";
                else if(i == 25){
                    ss.str("");
                    ss << setfill('0') << setw(2) << localTime->tm_mday << "." 
                    << std::setw(2) << localTime->tm_mon + 1 << "." 
                    << localTime->tm_year + 1900;
                    replacement = ss.str();
                }
                else if(i == 26){replacement = user.get_surname() + " " + user.get_name() + " " + user.get_patronymic();}
                if (kid->charact.responsible <= 3){
                    if(i == 3)      replacement += kid->is_male() ? " є безвідповідальним учнем" : " є безвідповідальною ученицею";
                    else if(i == 6) replacement += " ніколи не";
                    else if(i == 7) replacement = "безвідповідально";
                    else if(i == 8) replacement = "ніколи не";
                }
                else if(kid->charact.responsible > 3 && kid->charact.responsible <= 7){
                    if(i == 3)      replacement += kid->is_male() ? " є достатньо відповідальним учнем" : " є достатньо відповідальною ученицею";
                    else if(i == 6) replacement += " іноді";
                    else if(i == 7) replacement = "достатньо відповідально";
                    else if(i == 8) replacement = "рідко";
                }
                else if(kid->charact.responsible > 7){
                    if(i == 3)      replacement += kid->is_male() ? " є дуже відповідальним учнем" : " є дуже відповідальною ученицею";
                    else if(i == 6) replacement += " часто";
                    else if(i == 7) replacement = "дуже відповідально";
                    else if(i == 8) replacement = "завжди";
                }
                if(kid->charact.hardworking <= 3){
                    if(i == 10)     replacement = "низький"; 
                    else if(i == 11) replacement = "мінімальних";
                }
                else if(kid->charact.hardworking > 3 && kid->charact.hardworking <= 7){
                    if(i == 10)     replacement = "середній"; 
                    else if(i == 11) replacement = "достатньо";
                }
                else if(kid->charact.hardworking > 7){
                    if(i == 10)     replacement = "високий"; 
                    else if(i == 11) replacement = "максимальну кількість";
                }
                
                if(kid->charact.timemanager <= 3){
                    if(i == 12)      replacement += " володіє жахливими";
                    else if(i == 13) replacement = "взагалі не вміє";
                }
                else if(kid->charact.timemanager > 3 && kid->charact.timemanager <= 7){
                    if(i == 12)      replacement += " володіє середніми";
                    else if(i == 13) replacement = "може";
                }
                else if(kid->charact.timemanager > 7){
                    if(i == 12)      replacement += " володіє чудовими";
                    else if(i == 13) replacement = "вміє професіонально";
                }
            
                if(kid->charact.communicator <= 3){
                    if(i == 14) replacement += " має погані";
                    else if(i == 15) replacement = "не вміє";
                    else if(i == 16) replacement = "взагалі не";
                    else if(i == 17) replacement = kid->is_male() ? "ніколи не готовий" : "ніколи не готова";
                    else if(i == 18) replacement = "не товаришує";
                }
                else if(kid->charact.communicator > 3 && kid->charact.communicator <= 7){
                    if(i == 14) replacement += " має непогані";
                    else if(i == 15) replacement = "іноді може";
                    else if(i == 16) replacement = "іноді";
                    else if(i == 17) replacement = "іноді може";
                    else if(i == 18) replacement = "може контактувати";
                }
                else if(kid->charact.communicator > 7){
                    if(i == 14) replacement += " має чудові";
                    else if(i == 15) replacement = " вміє вдало";
                    else if(i == 16) replacement = "активно";
                    else if(i == 17) replacement = kid->is_male() ? "завжди готовий" : "завжди готова";
                    else if(i == 18) replacement = "активно спілкується";
                }
                
                if(kid->charact.quality <= 3){
                    if(i == 19) replacement += " не є";
                    else if(i == 20) replacement = "демотивує";
                    else if(i == 21) replacement = "ніколи не"; 
                    else if(i == 22) replacement = "негативно"; 
                }
                else if(kid->charact.quality > 3 && kid->charact.quality <= 7){
                    if(i == 19) replacement += " є частково";
                    else if(i == 20) replacement = "може мотивувати";
                    else if(i == 21) replacement = "іноді"; 
                    else if(i == 22) replacement = "нейтрально"; 
                }
                else if(kid->charact.quality > 7){
                    if(i == 19) replacement += " є дуже ";
                    else if(i == 20) replacement = "надихає та мотивує";
                    else if(i == 21) replacement = "завжди"; 
                    else if(i == 22) replacement = "позитивно"; 
                }

                if(kid->charact.skip <= 3){
                    if(i == 23)  replacement += kid->is_male() ? " майже не пропускав навчальні дні ,тому" : " майже не пропускала навчальні дні ,тому";
                    if(i == 24)  replacement = "зовсім не";
                }
                else if(kid->charact.skip > 3 && kid->charact.skip <= 8){
                    if(i == 23)  replacement += kid->is_male() ? " іноді пропускав навчальні дні ,тому" : " іноді пропускала навчальні дні ,тому";
                    if(i == 24)  replacement = "майже не";
                }
                else if(kid->charact.skip > 7){
                    if(i == 23)  replacement += kid->is_male() ? " часто пропускав навчальні дні ,тому" : " часто пропускала навчальні дні ,тому";
                    if(i == 24)  replacement = "значно";
                }
            kid_file << replacement;
            i++;
            }
        }
        kid_file.close();
    }
}
