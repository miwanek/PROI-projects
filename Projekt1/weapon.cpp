#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>


#include "weapon.h"
#include "menu.h"


void clean();
int weapon::temp=20;

// pierwszy najbardziej ogólny konstruktor
weapon::weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
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
weapon::weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
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
weapon::weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
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
weapon::weapon(unsigned int range1, unsigned int weight1, unsigned int caliber1, unsigned int accuracy1,
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



//konstruktor magazynka

weapon::Magazine::Magazine( int magazine_size1, std::string magazine_type1)
{
            std::cout<<"Dodajemy magazynek\n";
            magazine_type= magazine_type1;
            magazine_size= magazine_size1;
            ammo= magazine_size1;

}

//destruktor magazynka
weapon::Magazine::~Magazine()
{
            std::cout<<"Usuwamy magazine\n";
}

void weapon::Magazine::show2() //parametry magazynka
{
    std::cout<<"Rodzaj magazynka: "<< magazine_type <<std::endl;
    std::cout<<"Rozmiar magazynka: "<< magazine_size <<std::endl;
    std::cout<<"Obecnie liczba kul w magazynku: "<< ammo <<std::endl;
}

void weapon::show() //parametry broni
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

    else  std::cout<< "Nie mozna zamontowac trójnogu" << std::endl;

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

std::string weapon::Magazine::get_type()
{
    return magazine_type;
}

unsigned int weapon::Magazine:: get_size()
{
    return magazine_size;
}

 unsigned int weapon::Magazine::get_ammo()
 {
     return ammo;
 }
void weapon::Magazine::reduce_ammo()
{
    ammo-=1;
}


void weapon::cool()
{
    current_temp=temp;
    std::cout<<"Lufa karabinu schlodzona do temperatury pokojowej"<<std::endl;

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

void weapon::operator--(int) //zdejmowanie tłumika
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

int weapon::fire ( unsigned int bullet, unsigned int distance, bool autofire  ) //na początek zakładamy, ze udało się wystrzelić 0 kul
{
    int hit=0;
    unsigned int effective_accuracy=accuracy;
    unsigned int shoot;
    unsigned int effective_range=range;

    if(autofire==true) // jeśli ogień automatyczny to zmniejszamy efektywną celność
    {
        effective_accuracy*=0.8;
    }

    if(silencer==true)  // jeśli tłumik jest założony to zmniejszamy efektywny zasięg
    {
        effective_range*=0.9;
    }

    if( distance > range && (range*2)>=distance)  // jeśli efektywny zasięg przekroczony to zmniejszamy celność
    {
        effective_accuracy/=2;
    }

    if(tripod==true) //jeśli trójnóg zamontowany to zwiększamy celność ostrzału
    {
        effective_accuracy+=10;
        if(effective_accuracy > 100 )
        {
            effective_accuracy=100;
        }

    }


    if( (range*2) < distance ) // jeśli przekroczymy zasięg dwukrotnie to celność spada do zera
    {
        effective_accuracy=0;
    }

    #ifdef _DEBUG
    std:: cout<< std:: endl <<"Efektywna celnosc to: "<< effective_accuracy << std::endl;

    std:: cout<< std:: endl <<"Efektywny zasieg to: "<< effective_range << std::endl;

    #endif // Debug

    for(int i=0;i<bullet; i++) // właściwe strzelanie
    {
        if(current_temp>=100)
        {
            std:: cout<<"Przerywamy strzelanie, lufa przegrzana, trzeba ją schłodzić"<<std::endl;
            return hit;
        }
        if( magazine.get_ammo() == 0 )
        {
            std:: cout<<"Nie ma już pocisków w magazynku, przerywamy strzelanie"<<std::endl;
            return hit;
        }
        shoot= rand()%100 +1; // losujemy liczbe z zakresu 1-100
        if( shoot <= effective_accuracy) // jeśli nalezy do zakresu celności broni to zaliczamy trafienie
        {
            hit++;
        }
        current_temp+= 1; // podwyższamy temperature lufy
        magazine.reduce_ammo(); // wywołujemy funkcję usuwającą łuski z broni
    }
    return hit;


}


bool weapon::mode_check() // sprawdza czy tryb automatyczny jest dozwolony
{
    return full_auto;
}



void weapon::operator++(int) //zakładanie tłumika
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
void weapon::operator!()  //rozkładanie trójnogu
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

void weapon::operator&()  //składanie trójnogu
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

void weapon::operator+( weapon &x ) // tworzenie nowego obiektu wybierając lepsze elemnty z 2 broni
{
    unsigned int weight1, caliber1;
    unsigned int accuracy1, firerate1, range1;
    std::string name1;
    bool full_auto1=false, silencer_allowed1=false, silencer1=false, tripod_allowed1=false, tripod1=false;

    name1= name + "-" + x.name;

    if( accuracy > x.accuracy)
    {
        accuracy1= accuracy;
    }
    else accuracy1= x.accuracy;

    if( firerate > x.firerate)
    {
        firerate1=  firerate;
    }
    else firerate1= x.firerate;

    if( range > x.range)
    {
        range1= this->range;
    }
    else range1= x.range;

    if( weight < x.weight)
    {
        weight1= weight;
    }
    else weight1= x.weight;

    if( caliber > x.caliber)
    {
        caliber1= caliber;
    }
    else caliber1= x.caliber;

    if( tripod_allowed || x.tripod_allowed )
    {
        tripod_allowed1= true;
    }

    if( tripod|| x.tripod)
    {
        tripod1= true;
    }

    if( silencer_allowed || x.silencer_allowed)
    {
        silencer_allowed1= true;
    }

    if( silencer || x.silencer)
    {
        silencer1= true;
    }

    if( full_auto || x.full_auto)
    {
        full_auto1= true;
    }

    Menu::pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                    firerate1,  name1,  full_auto1,
                    silencer_allowed1,  tripod_allowed1,  tripod1,  silencer1);

    std::cout<< "Stworzono nową broń" << std::endl;
    Menu::weapon_tab.push_back(Menu::pom);


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Testy
 #ifdef _DEBUG

void weapon::tests()
{
    test_T();
    test_K();
    test_O(); //test operatorów
    test_S();
    std::cout<<"Testy zakończone pomyślnie"<< std:: endl;
    std::cin.get();
    Menu::clean();

}

void weapon::test_T()
{
    //test temperatury
    assert(weapon::temp==20);
    weapon::change_temperature(-50);
    assert(weapon::temp==-50);
    weapon::change_temperature(50);
    assert(weapon::temp==50);
}

void weapon::test_K()
{

    //test konstruktorów
    Menu::pom= new weapon(  100,  100,  12,   12, 222 ,  "Kar98",  0,
                  30,  "kołowy", 1,  0,  0,  1);

    Menu::weapon_tab.push_back(Menu::pom);
    assert(Menu::weapon_tab[0]->range==100);
    assert(Menu::weapon_tab[0]->weight==100);
    assert(Menu::weapon_tab[0]->caliber==12);
    assert(Menu::weapon_tab[0]->accuracy==12);
    assert(Menu::weapon_tab[0]->firerate==222);
    assert(Menu::weapon_tab[0]->name=="Kar98");
    assert(Menu::weapon_tab[0]->full_auto== false);
    assert(Menu::weapon_tab[0]->magazine.get_size()==30);
    assert(Menu::weapon_tab[0]->magazine.get_type()=="kołowy");
    assert(Menu::weapon_tab[0]->silencer_allowed== true);
    assert(Menu::weapon_tab[0]->tripod_allowed== false);
    assert(Menu::weapon_tab[0]->tripod== false);
    assert(Menu::weapon_tab[0]->silencer== true);

    assert(Menu::weapon_tab.size()==1);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Konstruktor bez bajerów i ekstra magazynka

    Menu::pom= new weapon(  300,  1,  71,  90, 20 ,  "Mosin",  0);

    Menu::weapon_tab.push_back(Menu::pom);

    assert(Menu::weapon_tab[1]->range==300);
    assert(Menu::weapon_tab[1]->weight==1);
    assert(Menu::weapon_tab[1]->caliber== 71);
    assert(Menu::weapon_tab[1]->accuracy==90);
    assert(Menu::weapon_tab[1]->firerate==20);
    assert(Menu::weapon_tab[1]->name=="Mosin");
    assert(Menu::weapon_tab[1]->full_auto== false);
    assert(Menu::weapon_tab[1]->magazine.get_size()==30);
    assert(Menu::weapon_tab[1]->magazine.get_type()=="standardowy");
    assert(Menu::weapon_tab[1]->silencer_allowed== false);
    assert(Menu::weapon_tab[1]->tripod_allowed== false);
    assert(Menu::weapon_tab[1]->tripod== false);
    assert(Menu::weapon_tab[1]->silencer== false);

    assert(Menu::weapon_tab.size()==2);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// konstruktor z dodatkowym majerami bez magazynka

    Menu::pom= new weapon(  200,  300,  56,  60, 600 ,  "Ak",  1, 1 ,1 ,1 ,1 );

    Menu::weapon_tab.push_back(Menu::pom);

    assert(Menu::weapon_tab[2]->range==200);
    assert(Menu::weapon_tab[2]->weight==300);
    assert(Menu::weapon_tab[2]->caliber== 56);
    assert(Menu::weapon_tab[2]->accuracy==60);
    assert(Menu::weapon_tab[2]->firerate==600);
    assert(Menu::weapon_tab[2]->name=="Ak");
    assert(Menu::weapon_tab[2]->full_auto== true);
    assert(Menu::weapon_tab[2]->magazine.get_size()==30);
    assert(Menu::weapon_tab[2]->magazine.get_type()=="standardowy");
    assert(Menu::weapon_tab[2]->silencer_allowed== true);
    assert(Menu::weapon_tab[2]->tripod_allowed== true);
    assert(Menu::weapon_tab[2]->tripod== true);
    assert(Menu::weapon_tab[2]->silencer== true);

    assert(Menu::weapon_tab.size()==3);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Menu::pom= new weapon(  400,  500,  76,  50, 20 ,  "47",  0 , 20, "prosty");

    Menu::weapon_tab.push_back(Menu::pom);

    assert(Menu::weapon_tab[3]->range==400);
    assert(Menu::weapon_tab[3]->weight==500);
    assert(Menu::weapon_tab[3]->caliber== 76);
    assert(Menu::weapon_tab[3]->accuracy==50);
    assert(Menu::weapon_tab[3]->firerate==20);
    assert(Menu::weapon_tab[3]->name=="47");
    assert(Menu::weapon_tab[3]->full_auto== false);
    assert(Menu::weapon_tab[3]->magazine.get_size()==20);
    assert(Menu::weapon_tab[3]->magazine.get_type()=="prosty");
    assert(Menu::weapon_tab[3]->silencer_allowed== false);
    assert(Menu::weapon_tab[3]->tripod_allowed== false);
    assert(Menu::weapon_tab[3]->tripod== false);
    assert(Menu::weapon_tab[3]->silencer== false);

    assert(Menu::weapon_tab.size()==4);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////// Test operatorów
 void weapon::test_O()
 {
     *(Menu::weapon_tab[2])+*(Menu::weapon_tab[3]);
        assert(Menu::weapon_tab[4]->range==400);
        assert(Menu::weapon_tab[4]->weight==300);
        assert(Menu::weapon_tab[4]->caliber== 76);
        assert(Menu::weapon_tab[4]->accuracy==60);
        assert(Menu::weapon_tab[4]->firerate==600);
        assert(Menu::weapon_tab[4]->name=="Ak-47");
        assert(Menu::weapon_tab[4]->full_auto== true);
        assert(Menu::weapon_tab[4]->magazine.get_size()==30);
        assert(Menu::weapon_tab[4]->magazine.get_type()=="standardowy");
        assert(Menu::weapon_tab[4]->silencer_allowed== true);
        assert(Menu::weapon_tab[4]->tripod_allowed== true);
        assert(Menu::weapon_tab[4]->tripod== true);
        assert(Menu::weapon_tab[4]->silencer== true);

        assert(Menu::weapon_tab.size()==5);

        (*Menu::weapon_tab[4])++;
        assert(Menu::weapon_tab[4]->silencer== true); // sprawdzamy czy nie dzieje się nicdziwneg przy np. próbie założenia tłumika kiedy jest już założony
        (*Menu::weapon_tab[4])--;
        assert(Menu::weapon_tab[4]->silencer== false);
        (*Menu::weapon_tab[4])--;
        assert(Menu::weapon_tab[4]->silencer== false);
        (*Menu::weapon_tab[4])++;
        assert(Menu::weapon_tab[4]->silencer== true);
        !(*Menu::weapon_tab[4]);
        assert(Menu::weapon_tab[4]->tripod== true); //to samo dla trójnogu
        &(*Menu::weapon_tab[4]);
        assert(Menu::weapon_tab[4]->tripod== false);
        &(*Menu::weapon_tab[4]);
        assert(Menu::weapon_tab[4]->tripod== false);
        !
        (*Menu::weapon_tab[4]);
        assert(Menu::weapon_tab[4]->tripod== true);



 } //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // test metody strzelania i pokrewnych
 void weapon::test_S()
 {
    assert(Menu::weapon_tab[4]->fire(30,1000,0)== 0); //przekraczamy zasięg maksymalny
    assert(Menu::weapon_tab[4]->fire(30,20,0)== 0); // brak kul w magazynku
    Menu::weapon_tab[4]->magazine.reload() ;
    assert(Menu::weapon_tab[4]->magazine.get_ammo() == 30 );
    Menu::weapon_tab[4]->magazine.reduce_ammo();
    assert(Menu::weapon_tab[4]->magazine.get_ammo() == 29 );
    Menu::weapon_tab[4]->fire(29,20,0);
    assert(Menu::weapon_tab[4]->current_temp!= weapon::temp); //sprawdzamy czy wzrasta temperatura
    Menu::weapon_tab[4]->magazine.reload() ;
    assert(Menu::weapon_tab[4]->fire(30 , 20 , 1)==0);
    assert(Menu::weapon_tab[4]->magazine.get_ammo() == 30);
    Menu::weapon_tab[4]->cool(); // sprawdzamy czy lufa się schłodziła
    assert(Menu::weapon_tab[4]-> current_temp== weapon::temp);


 }

  #endif


