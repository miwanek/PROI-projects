#include "weapon.h"
#include <iostream>

void clean();
int weapon::temp=20;

// pierwszy najbardziej ogólny konstruktor
weapon::weapon(unsigned int range1, float weight1, float caliber1, unsigned int accuracy1,
               unsigned int firerate1, std::string name1, bool full_auto1,
                unsigned int magazine_size1, std::string magazine_type1, bool silencer_allowed1, bool tripod_allowed1, bool tripod1, bool silencer1):

    magazynek( magazine_size1 , magazine_type1 ),
    range( range1 ),
    weight( weight1 ),
    caliber( caliber1 ),
    current_temp( temp ),
    silencer_allowed( silencer_allowed1 ),
    silencer( silencer1 ),
    tripod_allowed( tripod_allowed1 ),
    tripod( tripod ),
    accuracy( accuracy1 ),
    firerate( firerate1 ),
    name( name1 ),
    full_auto( full_auto1 )
{

    std::cout<< "Tworzymy nowy obiekt\n";

    std::cout<<"Proces zakończony sukcesem\n";
    return;

}

/* weapon::weapon(unsigned int range1, float weight1, float caliber1, unsigned int accuracy1,
               unsigned int firerate1, std::string name1, bool full_auto1,
                unsigned int magazine_size1, std::string magazine_type1, bool silencer_allowed1, bool tripod_allowed1, bool tripod1, bool silencer1 ):

    magazynek( magazine_size1 , magazine_type1 ),
    range( range1 ),
    weight( weight1 ),
    caliber( caliber1 ),
    current_temp( temp ),
    silencer_allowed( silencer_allowed1 ),
    silencer( silencer1 ),
    tripod_allowed( tripod_allowed1 ),
    tripod( tripod1 ),
    accuracy( accuracy1 ),
    firerate( firerate1 ),
    name( name1 ),
    full_auto( full_auto1 )
{

    std::cout<< "Tworzymy nowy obiekt\n";

    std::cout<<"Proces zakończony sukcesem\n";
    return; */

//}
weapon::magazine::magazine( int magazine_size1, std::string magazine_type1)
{
            std::cout<<"Dodajemy magazynek\n";
            magazine_type= magazine_type1;
            magazine_size= magazine_size1;
            ammo= magazine_size1;

}


weapon::magazine::~magazine()
{
            std::cout<<"Usuwamy magazynek\n";
}
void weapon::magazine::show2()
{
    std::cout<<"Rodzaj magazynka: "<< magazine_type <<std::endl;
    std::cout<<"Rozmiar magazynka: "<< magazine_size <<std::endl;
    std::cout<<"Obecnie liczba kul w magazynku: "<< ammo <<std::endl;
}
void weapon::show()
{
    std::cout<<"Parametry wybranej broni to: \n";
    std::cout<<"Nazwa:"<< name <<std::endl;
    magazynek.show2();
    std::cout<<"Temperatura lufy: "<<current_temp <<std::endl;
    std::cout<<"Zasieg skuteczny: "<< range <<std::endl;
    std::cout<<"Kaliber broni: "<< caliber <<std::endl;
    std::cout<<"Waga: "<< weight <<std::endl;
    std::cout<<"Szybkostrzelnosc na minute: "<< firerate <<std::endl;
    std::cout<<"Celnosc: "<< accuracy << std::endl;

    if(full_auto==true) std::cout<<"Bron moze strzelac ogniem automatycznym"<<std::endl;

    else std::cout<<"Bron nie  moze strzelac ogniem automatycznym"<<std::endl;

    if(tripod_allowed==true) std::cout<< "Mozna zamontowac trojnog" << std::endl;

    else  std::cout<< "Nie mozna zamontowac trojnog" << std::endl;

    if(tripod==true)  std::cout<< "Trojnog jest juz zamontowany" << std::endl;

    if(tripod==false && tripod_allowed==true)  std::cout<< "Trojnog nie jest jeszcze zamontowany" << std::endl;

    if(silencer_allowed == true) std::cout<< "Mozna zamontowac tlumik" << std::endl;

    else  std::cout<< "Nie mozna zamontowac tlumika" << std::endl;

    if(silencer==true)  std::cout<< "Tlumik jest juz zamontowany" << std::endl;

    if(silencer==false && silencer_allowed==true)  std::cout<< "Tlumik nie jest jeszcze zamontowany" << std::endl;

}

void weapon::magazine::reload()
{
    ammo=magazine_size;
    std::cout<<"Udało się uzupełnić magazynek"<<std::endl;

}
void weapon::cool()
{
    current_temp=temp;
    std::cout<<"Lufa karabinu schlodzona do tempretury pokojowej"<<std::endl;

}

void weapon::current_temperature()
{
    std::cout<<"Obecna temperatura otoczenia to: "<<temp<<" stopni/stopnie Celcjusza"<<std::endl;
}
void weapon::change_temperature(int celc)
{

    temp=celc;
    std::cout<< "Operacja zakonczona sukcesem"<<std::endl;

}



weapon::~weapon()
{
    std::cout<<"Uwaga, uwaga podana bron zostanie wlasnie usunieta\n";
}

void weapon::operator--(int)
{
     if(silencer==true)
     {
         silencer=false;
         std::cout<<"Wlasnie zdjales tlumik"<<std::endl;
     }
     else
     {
         std::cout<<"Bron nie ma tlumika, ktory można byłoby zdjąć"<<std::endl;
     }

}

void weapon::operator++(int)
{

     if(silencer==true )
     {
         std::cout<<"Bron ma juz zalozony tlumik"<<std::endl;
     }

     if(silencer==false && silencer_allowed==true)
     {
         silencer=true;
         std::cout<<"Wlasnie zalozyles tlumik"<<std::endl;
     }

    if(silencer==false && silencer_allowed==false)
     {
         std::cout<<"Nie mozna zalozyc tlumika"<<std::endl;
     }

}
void weapon::operator!()
{

    if(tripod==true )
     {
         std::cout<<"Bron ma już rozłożony trójnóg"<<std::endl;
     }


    if(tripod==false && tripod_allowed==true)
     {
         tripod=true;
         std::cout<<"Wlasnie rozłożyłeś trójnóg"<<std::endl;
     }

    if(tripod==false && tripod_allowed==false)
     {
         std::cout<<"Nie mozna rozłożyć trójnogu"<<std::endl;
     }

}
void weapon::operator&()
{
      if(tripod==true)
     {
         tripod=false;
         std::cout<<"Wlasnie zlożyłeś trójnóg"<<std::endl;
     }
     else
     {
         std::cout<<"Bron nie ma trójnogu, ktory można byłoby złożyć"<<std::endl;
     }

}

