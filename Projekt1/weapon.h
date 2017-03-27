#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>


class weapon
{
    public:
        void show();
        void reload();
        void cool();
        static void change_temperature();
        static void current_temperature();
        int fire();
        int autofire();

        std:: string name;

        weapon();
        ~weapon();

    private:
    std:: string magazine_type;
    int current_temp; //temperatura lufy
    float caliber; //kaliber broni
    unsigned int ammo; // liczba kul w obecnym magazynku
    unsigned int magazine_size;
    unsigned int range;
    float weight;
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
