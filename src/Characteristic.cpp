#include "Characteristic.h"
#include "Person.h"
#include <iostream>
#include <string>
namespace CharacteristicGenerator {
    void Characteristic::set_charact(){
        int indicator;
        std::cout << "Оцініть від 1 до 10 наступні риси характеру\nВідповідальність : ";
        while (true){
            std::cin >> indicator;
            if(indicator < 1 || indicator > 10) std::cout << "Введіть число від 1 до 10\nВідповідальність : ";
            else break;
        }
        responsible = indicator;
        std::cout << "Працьовитість : ";
        while (true){
            std::cin >> indicator;
            if(indicator < 1 || indicator > 10) std::cout << "Введіть число від 1 до 10\nПрацьовитість : ";
            else break;
        }
        hardworking = indicator;
        std::cout << "Вміння керувати часом : ";
        while (true){
            std::cin >> indicator;
            if(indicator < 1 || indicator > 10) std::cout << "Введіть число від 1 до 10\nВміння керувати часом : ";
            else break;
        }
        timemanager = indicator;
        std::cout << "Вміння комунікувати : ";
        while (true){
            std::cin >> indicator;
            if(indicator < 1 || indicator > 10) std::cout << "Введіть число від 1 до 10\nВміння комунікувати : ";
            else break;
        }
        communicator = indicator;
        std::cout << "Цінність як члена команди : ";
        while (true){
            std::cin >> indicator;
            if(indicator < 1 || indicator > 10) std::cout << "Введіть число від 1 до 10\nЦінність як члена команди : ";
            else break;
        }
        quality = indicator;
        std::cout << "Схильність до пропусків : ";
        while (true){
            std::cin >> indicator;
            if(indicator < 1 || indicator > 10) std::cout << "Введіть число від 1 до 10\nСхильність до пропусків : ";
            else break;
        }
        skip = indicator;
    }
    Characteristic::Characteristic(){}
}