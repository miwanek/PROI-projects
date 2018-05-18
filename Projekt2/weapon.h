#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include <cassert>
/*! \file */

class weapon
{
    public:

        void show(); /// pokazanie parametrów
        void cool(); ///schłodzenie lufy
        bool mode_check();
        static void change_temperature(int celc); /// zmiana temperatury otoczenia
        static void current_temperature();
        int fire(unsigned int bullet, unsigned int distance, bool autofire= false ); ///< strzelanie do celu
        void operator--(int); ///< zdjęcie tłumika
        void operator++(int); ///< zamontowanie tłumika
        void operator!(); ///< rozłożenie trójnogu
        void operator&(); ///< złożenie trójnogu
        void operator+(  weapon &x);

         //#ifdef _DEBUG
        static void tests();
        static void test_T();
        static void test_K();
        static void test_O(); ///< test operatorów
        static void test_S(); ///< test strzelania


       // #endif


        std:: string name;

        class Magazine
            {

            public:
                void reload(); ///< przeładowanie magazynka
                void show2();
                std::string get_type();
                unsigned int get_size(); ///< funkcje zwracające wartość odpowienich parametrów
                unsigned int get_ammo();
                void reduce_ammo(); ///< liczba kul w obecnym magazynku

                Magazine( int magazine_size1=30, std::string magazine_type1="standardowy"); ///< konstruktor
                ~Magazine();

            private:
                std::string magazine_type;
                unsigned int magazine_size;
                unsigned int ammo;  ///< liczba kul w obecnym magazynku
            };
        Magazine magazine;

        /// konstruktor z parametrami domyślnymi

        weapon(unsigned int range1=300, unsigned int weight1=660, unsigned int caliber1=56, unsigned int accuracy1=80,
              unsigned int firerate1=300, std::string name1="karabin generyczny", bool full_auto1=true,
               unsigned int magazine_size1=30, std::string magazine_type1="standardowy", bool silencer_allowed1=false, bool tripod_allowed1=false, bool tripod1=false, bool silencer1=false);



        ~weapon(); //destruktor

    private:

    int current_temp; //temperatura lufy
    unsigned int caliber; //kaliber broni
    unsigned int range;
    unsigned int weight;
    unsigned int accuracy;
    unsigned int firerate;
    static int temp;
    bool silencer; //tłumik
    bool silencer_allowed;
    bool tripod;
    bool tripod_allowed; //trójnóg
    bool full_auto; //czy bron moze strzelac w trybie automatycznym

};

#endif // WEAPON_H
