#include "weapon.h"
#include <iostream>

void clean();
int weapon::temp=20;

weapon::weapon()
{
    std::cout<< "Tworzymy nowy obiekt\n";
    magazine_type= "bebenowy";
    magazine_size= 30;
    range= 200;
    weight= 3;
    ammo= 20;
    caliber=7.6;
    current_temp=21;
    silencer_allowed= true;
    silencer= true;
    tripod_allowed= true;
    tripod= true;
    accuracy= 40;
    firerate= 500;
    name="bron";
    full_auto==true;


    std::cout<<"Proces zakończony sukcesem\n";
    return;

}
void weapon::show()
{
    std::cout<<"Parametry wybranej broni to: \n";
    std::cout<<"Nazwa:"<< name <<std::endl;
    std::cout<<"Rodzaj magazynka: "<< magazine_type <<std::endl;
    std::cout<<"Rozmiar magazynka: "<< magazine_size <<std::endl;
    std::cout<<"Obecnie liczba kul w magazynku: "<< ammo <<std::endl;
    std::cout<<"Temperatura lufy: "<<current_temp <<std::endl;
    std::cout<<"Zasieg skuteczny: "<< range <<std::endl;
    std::cout<<"Kaliber broni: "<< caliber <<std::endl;
    std::cout<<"Waga: "<< weight <<std::endl;
    std::cout<<"Szybkostrzelnosc na minute: "<< firerate <<std::endl;
    std::cout<<"Celnosc: "<< accuracy << std::endl;

    if(tripod_allowed==true) std::cout<< "Mozna zamontowac trojnog" << std::endl;

    else  std::cout<< "Nie mozna zamontowac trojnog" << std::endl;

    if(tripod==true)  std::cout<< "Trojnog jest juz zamontowany" << std::endl;

    if(tripod==false && tripod_allowed==true)  std::cout<< "Trojnog nie jest jeszcze zamontowany" << std::endl;

    if(silencer_allowed == true) std::cout<< "Mozna zamontowac tlumik" << std::endl;

    else  std::cout<< "Nie mozna zamontowac tlumika" << std::endl;

    if(silencer==true)  std::cout<< "Tlumik jest juz zamontowany" << std::endl;

    if(silencer==false && silencer_allowed==true)  std::cout<< "Tlumik nie jest jeszcze zamontowany" << std::endl;

}

void weapon::reload()
{
    ammo=magazine_size;
    std::cout<<"Udało się uzupełnić magazynek"<<std::endl;

}

void weapon::current_temperature()
{
    std::cout<<"Obecna temperatura otoczenia to: "<<temp<<" stopni/stopnie Celcjusza"<<std::endl;
}
void weapon::change_temperature()
{
    int celc=-100;
    bool start=true;
    do
    {
        if(start==false)
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        std::cout<< "Podaj obecna temperature otoczenia z zakresu +-50 stopni celcjusza"<< std::endl;
        std::cin>>celc;
        start=false;
    }
    while(celc>50||celc<-50||std::cin.fail());
    temp=celc;
    std::cout<< "Operacja zakonczona sukcesem"<<std::endl;

}



weapon::~weapon()
{
    std::cout<<"Uwaga, uwaga podana bron zostanie wlasnie usunieta\n";
}



