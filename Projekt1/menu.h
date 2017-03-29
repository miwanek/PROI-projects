
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

#include "weapon.h"



class Menu
{
    public:

        static void Mainmenu();
        static void Info1();
        static void clean();
        static void Info2();
        static void Info3();
        static void add();
        static void look();



        static void aim(bool fire_mode);

        static std::vector<weapon*> weapon_tab;
        static weapon* pom;

        static int weapon_nr;
        static int celc;
        static bool bylo;
        static bool start;


    private:


};


#endif // MENU_H_INCLUDED
