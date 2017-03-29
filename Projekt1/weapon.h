#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include <cassert>


class weapon
{
    public:

        void show();
        void cool();
        bool mode_check();
        static void change_temperature(int celc);
        static void current_temperature();
        int fire(unsigned int bullet, unsigned int distance, bool autofire= false );
        void operator--(int);
        void operator++(int);
        void operator!();
        void operator&();
        void operator+(  weapon &x);

         #ifdef _DEBUG
        static void tests();
        static void test_T();
        static void test_K();
        static void test_O(); //test operatorów
        static void test_S(); //test strzelania


        #endif


        std:: string name;

        class Magazine
            {

            public:
                void reload();
                void show2();
                std::string get_type();
                unsigned int get_size();
                unsigned int get_ammo();
                void reduce_ammo();
                // liczba kul w obecnym magazynku

                Magazine( int magazine_size1, std::string magazine_type1);
                ~Magazine();

            private:
                std::string magazine_type;
                unsigned int magazine_size;
                unsigned int ammo;  // liczba kul w obecnym magazynku
            };
        Magazine magazine;


        weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
              unsigned int firerate1, std::string name1, bool full_auto1,
               unsigned int magazine_size1, std::string magazine_type1, bool silencer_allowed1, bool tripod_allowed1, bool tripod1, bool silencer1);

        weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
              unsigned int firerate1, std::string name1, bool full_auto1,
               bool silencer_allowed1, bool tripod_allowed1, bool tripod1, bool silencer1);

        weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
              unsigned int firerate1, std::string name1, bool full_auto1 );

        weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
              unsigned int firerate1, std::string name1, bool full_auto1,
               unsigned int magazine_size1, std::string magazine_type1);




        ~weapon();

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
