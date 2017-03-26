#include "weapon.h"
#include <iostream>

weapon::weapon()
{
    std::cout<<"Tworzymy nowy obiekt\n";
    magazine_type="bebenowy";
    magazine_size=1;
    range=2;
    weight=3;
    accuracy=4;
    firerate=5;
    name="bron";


    std::cout<<"Proces zakończony sukcesem\n";
    return;

}
void weapon::show()
{
    std::cout<<"Parametry wybranej broni to: \n";
    std::cout<<"Nazwa:"<<name<<std::endl;
    std::cout<<"Rodzaj magazynka: "<<magazine_type<<std::endl;
    std::cout<<"Rozmiar magazynka: "<<magazine_size<<std::endl;
    std::cout<<"Zasieg skuteczny: "<<range<<std::endl;
    std::cout<<"Waga: "<<weight<<std::endl;
    std::cout<<"Szybkostrzelnosc na minute: "<<firerate<<std::endl;
    std::cout<<"Celnosc: "<<accuracy<<std::endl;


}



weapon::~weapon()
{
    std::cout<<"Uwaga, uwaga podana bron zostanie wlasnie usunieta\n";

}
