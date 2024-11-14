#ifndef MENU_H
#define MENU_H
#include "User.h"
namespace CharacteristicGenerator {
    class Menu {
        void show_menu(User &user);
        void create_charact(User &user);
        void check_charact();
    public:
        Menu(); 
        void start_menu();  
    };
}
#endif 
