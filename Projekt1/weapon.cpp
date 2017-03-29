#include <iostream>
#include <ctime>
#include <cstdlib>


#include "weapon.h"


void clean();
int weapon::temp=20;

// pierwszy najbardziej ogólny konstruktor
weapon::weapon(unsigned int range1, float weight1, float caliber1, unsigned int accuracy1,
               unsigned int firerate1, std::string name1, bool full_auto1,
                unsigned int magazine_size1, std::string magazine_type1, bool silencer_allowed1, bool tripod_allowed1, bool tripod1, bool silencer1):

    magazine( magazine_size1 , magazine_type1 ),
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
    return;

}

// Standradowy magazynek i ekstra bajery
weapon::weapon(unsigned int range1, float weight1, float caliber1, unsigned int accuracy1,
               unsigned int firerate1, std::string name1, bool full_auto1,
                 bool silencer_allowed1, bool tripod_allowed1, bool tripod1, bool silencer1):

    magazine( 30 , "standardowy" ),
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
    return;

}

// Standradowy magazynek bez ekstra bajerów
weapon::weapon(unsigned int range1, float weight1, float caliber1, unsigned int accuracy1,
               unsigned int firerate1, std::string name1, bool full_auto1 ):

    magazine( 30 , "standardowy" ),
    range( range1 ),
    weight( weight1 ),
    caliber( caliber1 ),
    current_temp( temp ),
    silencer_allowed( 0 ),
    silencer( 0 ),
    tripod_allowed( 0 ),
    tripod( 0 ),
    accuracy( accuracy1 ),
    firerate( firerate1 ),
    name( name1 ),
    full_auto( full_auto1 )
{

    std::cout<< "Tworzymy nowy obiekt\n";

    std::cout<<"Proces zakończony sukcesem\n";
    return;

}

// Specjalny magazynek bez ekstra bajerów
weapon::weapon(unsigned int range1, float weight1, float caliber1, unsigned int accuracy1,
               unsigned int firerate1, std::string name1, bool full_auto1,
                unsigned int magazine_size1, std::string magazine_type1 ):

    magazine( magazine_size1 , magazine_type1 ),
    range( range1 ),
    weight( weight1 ),
    caliber( caliber1 ),
    current_temp( temp ),
    silencer_allowed( 0 ),
    silencer( 0 ),
    tripod_allowed( 0 ),
    tripod( 0 ),
    accuracy( accuracy1 ),
    firerate( firerate1 ),
    name( name1 ),
    full_auto( full_auto1 )
{

    std::cout<< "Tworzymy nowy obiekt\n";

    std::cout<<"Proces zakończony sukcesem\n";
    return;

}





weapon::Magazine::Magazine( int magazine_size1, std::string magazine_type1)
{
            std::cout<<"Dodajemy magazine\n";
            magazine_type= magazine_type1;
            magazine_size= magazine_size1;
            ammo= magazine_size1;

}


weapon::Magazine::~Magazine()
{
            std::cout<<"Usuwamy magazine\n";
}
void weapon::Magazine::show2()
{
    std::cout<<"Rodzaj magazynka: "<< magazine_type <<std::endl;
    std::cout<<"Rozmiar magazynka: "<< magazine_size <<std::endl;
    std::cout<<"Obecnie liczba kul w magazynku: "<< ammo <<std::endl;
}
void weapon::show()
{
    std::cout<<"Parametry wybranej broni to: \n";
    std::cout<<"Nazwa:"<< name <<std::endl;
    magazine.show2();
    std::cout<<"Temperatura lufy: "<<current_temp <<std::endl;
    std::cout<<"Zasieg skuteczny: "<< range <<std::endl;
    std::cout<<"Kaliber broni: "<< caliber <<std::endl;
    std::cout<<"Waga: "<< weight <<std::endl;
    std::cout<<"Szybkostrzelnosc na minute: "<< firerate <<std::endl;
    std::cout<<"Celnosc: "<< accuracy << std::endl;

    if(full_auto==true) std::cout<<"Bron moze strzelac ogniem automatycznym"<<std::endl;

    else std::cout<<"Bron nie  moze strzelac ogniem automatycznym"<<std::endl;

    if(tripod_allowed==true) std::cout<< "Mozna zamontowac trójnóg" << std::endl;

    else  std::cout<< "Nie mozna zamontowac trójnógu" << std::endl;

    if(tripod==true)  std::cout<< "Trójnóg jest juz zamontowany" << std::endl;

    if(tripod==false && tripod_allowed==true)  std::cout<< "Trójnóg nie jest jeszcze zamontowany" << std::endl;

    if(silencer_allowed == true) std::cout<< "Mozna zamontowac tłumik" << std::endl;

    else  std::cout<< "Nie mozna zamontowac tlumika" << std::endl;

    if(silencer==true)  std::cout<< "Tłumik jest juz zamontowany" << std::endl;

    if(silencer==false && silencer_allowed==true)  std::cout<< "Tłumik nie jest jeszcze zamontowany" << std::endl;

}

void weapon::Magazine::reload()
{
    ammo=magazine_size;
    std::cout<<"Udało się uzupełnić magazine"<<std::endl;

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

int weapon::fire ( unsigned int bullet, unsigned int distance, bool autofire  )
{
    int hit=0;
    unsigned int effective_accuracy=accuracy;
    unsigned int shoot;
    unsigned int effective_range=range;

    if(autofire==true)
    {
        effective_accuracy*=0.8;
    }

    if(silencer==true)
    {
        effective_range*=0.8;
    }

    if( distance > range && (range*2)>=distance)
    {
        effective_accuracy/=2;
    }

    if(tripod==true)
    {
        effective_accuracy+=10;
        if(effective_accuracy > 100 )
        {
            effective_accuracy=100;
        }

    }


    if( (range*2) < distance )
    {
        effective_accuracy=0;
    }


    std:: cout<< std:: endl <<"Efektywna celnosc to: "<< effective_accuracy << std::endl;

    std:: cout<< std:: endl <<"Efektywny zasieg to: "<< effective_range << std::endl;

    for(int i=0;i<bullet; i++)
    {
        if(current_temp>=100)
        {
            std:: cout<<"Przerywamy strzelanie, lufa przegrzana, trzeba ją schłodzić"<<std::endl;
            return hit;
        }
        if( magazine.ammo==0 )
        {
            std:: cout<<"Nie ma już pocisków w magazynku, przerywamy strzelanie"<<std::endl;
            return hit;
        }
        shoot= rand()%100 +1;
        if( shoot <= effective_accuracy)
        {
            hit++;
        }
        current_temp+= 1;
        magazine.ammo-=1;
    }
    return hit;


}


bool weapon::mode_check()
{
    return full_auto;
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

