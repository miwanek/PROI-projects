
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
#include "new_vector.h"
/*! \file */



class Menu
{
    public:

        static void Mainmenu();
        static void Info1();
        static void clean();
        static void Info2(); // funkcje zarządzające interfejsem użytkownika
        static void Info3();
        static void add();  //podajemy parametry broni do dodania
        static void look(); // podajemy parametry broni do połączenia



        static void aim(bool fire_mode);

        static New_vector<weapon*> weapon_tab;
        static weapon* pom;

        static int weapon_nr; // numer wskazywanej broni
        static int celc;
        static bool bylo; //flaga czy w ogóle jeest taka broń w składzie
        static bool start;


    private:


};


#endif // MENU_H_INCLUDED
