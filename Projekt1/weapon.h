#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>


class weapon
{
    public:
        void show();
        std:: string name;
        weapon();
        ~weapon();

    protected:

    private:
    std:: string magazine_type;
    unsigned int magazine_size;
    unsigned int range;
    float weight;
    unsigned int accuracy;
    unsigned int firerate;
};

#endif // WEAPON_H
