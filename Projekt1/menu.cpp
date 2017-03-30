#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

#include "menu.h"
#include "weapon.h"


using namespace std;






 std::vector<weapon*> Menu::weapon_tab; //wektor przetrzymujący wskazniki na bronie
 weapon* Menu::pom;

    int Menu::weapon_nr;
    int Menu::celc; // zmienna pomocnicza do przekzywania  temperatury do funkcji change_temperature
    bool Menu::bylo; // flaga czy dany element jest w bazie
    bool Menu::start;



void Menu::Mainmenu()
{

    char znak; // dwie zmienne do zarzadzania menu
    char akcja;
    do
    {

    Info1(); // inforamcje dla użytkowanika o możliwych opcjach w menu
    znak=cin.get(); // pobieramy znak zarządzający co teraz się będzie dziać
    clean(); // funkcja czyszcząca
        switch(znak)
        {
        case '1':
            cout<<"To wszystkie bronie jakie sie obecnie znajduja w strzelnicy"<<endl<<endl;
            for(unsigned int i=0;i<Menu::weapon_tab.size();i++) // przeszukujemy od 0 do rozmiaru wketora-1
            {
                cout<<"Bron o numerze: " <<i<<" znana jako: "<<Menu::weapon_tab[i]->name<<endl;
            }
            break;

        case '2':
            cout<< "Podaj poprawny  numer broni: ";
            cin>> weapon_nr; // podajemy nr broni na której będziemy dookonwyać operacji
            clean();
            if(cin.good()==false)
            {
                cout<<"Bledne dane"<<endl;
                    cin.get();
                    clean();
                break;
            }
                for(unsigned int i=0; i<Menu::weapon_tab.size(); i++)
                {
                    if(weapon_nr==static_cast<int>(i)) //rzutowanie dla pewności
                        {
                        Menu::weapon_tab[weapon_nr]->cool(); // Jeśli wyjmujemy broń z półki to musi mieć temperature otoczenia
                        bool fire_mode; // czy tryb automatyczny jest włączony
                           do
                           {
                                system("clear");
                                cout<< "Wybrales bron o nazwie: "<< Menu::weapon_tab[weapon_nr]->name <<" oraz numerze: "<< weapon_nr << endl << endl;
                                Info2(); // kolejne menu z informacjami lda użykownika co może wybrać
                                akcja=cin.get();
                                clean();
                            switch(akcja)
                            {

                                case '1':

                                    Menu::weapon_tab[weapon_nr]->show(); // wypisujemy parametry broni
                                    break;

                                case '2':

                                    delete Menu::weapon_tab[weapon_nr];
                                    Menu::weapon_tab.erase(Menu::weapon_tab.begin() + weapon_nr); //usuwamy broń z wektora i pamięci
                                    cout<< "Usunieto bron z bazy \n \n";
                                    break;


                                case '3':
                                    look(); // funkcja obsługująca dodawania broni
                                    break;

                                case '4':

                                    fire_mode=false; //
                                    cout<< "Strzelasz do tarczy ogniem pojedynczym" << endl;
                                    Menu::aim(fire_mode); //przekazujemy tryb ognia do funkcji obsługującej strzelanie do celu


                                    break;

                                case '5':
                                    if(weapon_tab[weapon_nr]->mode_check()==false)
                                    {
                                        cout<<"Wybrana broń nie może strzelać w trybie automatycznym" << endl;
                                        break;
                                    }

                                    else
                                    {
                                        fire_mode=true;
                                        cout<< "Strzelasz do tarczy ogniem automatycznym" << endl;
                                        Menu::aim(fire_mode); //przekazujemy tryb ognia do funkcji obsługującej strzelanie do celu
                                        break;
                                    }


                                case '6':

                                    Menu::weapon_tab[weapon_nr]->magazine.reload(); //przeładowujemy magazynek
                                    break;

                                case '7':

                                    Menu::weapon_tab[weapon_nr]->cool(); //schładzamy lufę
                                    break;

                                case '8':
                                    (*Menu::weapon_tab[weapon_nr])++; //zakładamy tłumik jesli to możliwe
                                    break;

                                case '9':
                                    (*Menu::weapon_tab[weapon_nr])--;  //zdejmujemy tłumik jesli to możliwe
                                    break;

                                case '0':
                                    !(*Menu::weapon_tab[weapon_nr]);  //zakładamy trójnóg jesli to możliwe
                                    break;

                                case 'a':
                                    &(*Menu::weapon_tab[weapon_nr]);  //zdejmujemy trójnóg  jesli to możliwe
                                    break;

                                case 'b': //wyjsce z  menu
                                    break;

                                default:
                                    break;
                            }
                            cin.get();
                            clean(); //czyszczenie strumienia

                            } while(akcja!='b'&& akcja != '2'); // warunek sprawdzający czy czas już kończyć
                        bylo=true;
                    }
                }
            if(bylo==false){ cout<<"Nie ma takiej broni w skladzie"<<endl;}
            break;

        case '3':
            {
               {

                    add(); // wywołanie funkcji obsługującej wczytywanie danych dla nowej broni

                }
            break;
            }
        case '4':
                do
                    {
                if(start==false) // jeśli nic jeszcze nie wczytywaliśmy nie ma sensu wykonwyać tych dwóch operacji
                    {
                        std::cin.clear();
                        std::cin.ignore(10000,'\n'); //czyszczenie strumienia
                    }
                    std::cout<< "Podaj obecna temperature otoczenia z zakresu +-50 stopni celcjusza"<< std::endl;
                    std::cin>>celc;
                    start=false;
                }
                while(celc>50||celc<-50||std::cin.fail()); // sprawdzamy czy temperatura to nie jest np. -300 stopni celcjusza
            weapon::change_temperature(celc); // zmieniamy temperature otoczenia
            break;

        case '5':

            weapon::current_temperature(); // wypisanie aktualnej tempereatury otoczenia
            break;

        case '6':
                cout<<"Wychodzimy z programu"<<endl;
            break;

        default:
           {
            cout<<"Bledny znak, sprobuj jeszcze raz"<<endl;

           }
        }
    cin.get();
    clean();
    }
    while(znak!='6'); //strażnik czy już kończymy
   // cout<<Menu::weapon_tab.size()<<endl;


}
void Menu::clean() // funkcja czyszcząco strumień wejściowy
{
    cin.clear();
    cin.ignore(10000,'\n');
}

void Menu::Info1()
{
    system("clear");
    cout<<"Witaj na strzelnicy.\n"<<endl;
    cout<<"Co chcesz zrobić ? "<<endl;
    cout<<"Wciśnij 1, aby wyświetlić liste wszystkich dostepnych broni"<<endl;
    cout<<"Wciśnij 2, aby wybrac bron o podanym numerze"<<endl;
    cout<<"Wciśnij 3, aby dodac nowa bron do bazy"<<endl;
    cout<<"Wybierz 4, aby zmienic temperature otoczenia" << endl;
    cout<<"Wybierz 5, aby pokazac temperature otoczenia" << endl;
    cout<<"Wciśnij 6, aby wyjsc z programu"<<endl;
    weapon_nr=-1; // wartości zabezpieczające
    celc= -100;//
    bylo=false;
    start=true;


}

void Menu::Info2() //kolejny help dla użytkownika
{
            cout<< "Co chcesz zrobic?" << endl;
            cout<< "Wybierz 1, aby wyswietlic parametry broni" << endl;
            cout<< "Wybierz 2, aby usunac bron z bazy" << endl;
            cout<< "Wybierz 3, aby polaczyc dwie bronie w nowa lepsza sztuke" << endl;
            cout<< "Wybierz 4, aby strzelac do tarczy ogniem pojedyńczym" << endl;
            cout<< "Wybierz 5, aby strzelac do tarczy ogniem automatyczny" << endl;
            cout<< "Wybierz 6, aby uzupełnić magazynek" << endl;
            cout<< "Wybierz 7, aby schlodzic lufe do temperatury pokojowej" << endl;
            cout<< "Wybierz 8, aby zalozyc tlumik na lufe" << endl;
            cout<< "Wybierz 9, aby zdjac tlumik z lufy" << endl;
            cout<< "Wybierz 0, aby rozlozyc trojnog" << endl;
            cout<< "Wybierz a, aby zlozyc trojnog" << endl;
            cout<< "Wybierz b, aby odlozyc bron na miejsce" << endl;
}

void Menu::add()
{
    unsigned int weight1= 0, caliber1= 0 ;
    unsigned int accuracy1=0, firerate1=0, magazine_size1=0, range1=0; //parametry broni
    string name1, magazine_type1;
    bool full_auto1, silencer_allowed1, silencer1, tripod_allowed1, tripod1, ekstra, mag; //flagi do elementów dodatkowych niestandardoweg magazynka, trójnogu

    cout<<"Podaj poprawne parametry broni"<<endl;
    cout<<"Wpisz nazwe broni"<<endl;
    cin>>name1;
    clean();

    do{
        cout<<endl<<"Podaj zasięg efektywny broni z zakresu 1-5000 metrów"<<endl;
        cin>>range1;
        clean();
    } while(range1<1||range1>5000);

    do{
        cout<<endl<<"Podaj celnosc broni w procentach 1-100"<<endl;
        cin>>accuracy1;
        clean();
    } while(accuracy1<1||accuracy1>100);


    do{
        cout<<endl<<"Podaj szybkostrzelnosc broni "<<endl;
        cin>>firerate1;
        clean();
    } while(firerate1<1);

    do{
        cout<<endl<<"Podaj kaliber broni w 1/10 milimetrów  "<<endl;
        cin>>caliber1;
        clean();
    } while(caliber1==0);

    do{
        cout<<endl<<"Podaj wage broni w gramach  "<<endl;
        cin>>weight1;
        clean();
    } while(weight1==0);
    do
    {
        clean();
        cout<<endl<<"Czy karabin ma tryb ognia automatycznego."<<endl<< "Wpisz 1 jeśli tak, zero w przeciwnym wypadku?  "<<endl;
        cin>>full_auto1;
    } while(cin.fail());

    do
    {
        clean();
        cout<<endl<<"Czy karabin ma niestandardowy magazynek?"<<endl <<"Wklep 1 jeśli tak, zero w przeciwnym wypadku?  "<<endl;
        cin>>mag;
    } while(cin.fail());
    if(mag==true)
        {
                do{
                    cout<<endl<<"Podaj rozmiar magazynka:   "<<endl;
                    cin>>magazine_size1;
                    clean();
                } while(magazine_size1==0);

                    cout<<endl<<"Podaj rodzaj magazynka magazynka:  "<<endl;
                    cin>>magazine_type1;
                    clean();
        }

    do
    {
        clean();
        cout<<endl<<"Bron posiada jakies dodatkowe elementy mozliwe do zamocowania?"<<endl<< "Wpisz 1 jeśli, tak 0 dla opcji nie "<<endl;
        cin>>ekstra;
    } while(cin.fail());
    if(ekstra==true)
        {
               do
                {
                    clean();
                    cout<<endl<<"Mozna do niej w ogóle zamontowac tlumik? 1/0 to tak/nie "<<endl;
                    cin>>silencer_allowed1;
                } while(cin.fail());

                if(silencer_allowed1 == true)
                {
                    do
                        {
                            clean();
                            cout<<endl<<"A moze ma już go zamontowanego ? 1/0 to tak/nie "<<endl;
                            cin>>silencer1;
                        } while(cin.fail());
                }
                else silencer1=false;

                do
                {
                    clean();
                    cout<<endl<<"Mozna do broni  zamontowac trojnog lub inne wsparcie? 1/0 to tak/nie "<<endl;
                    cin>>tripod_allowed1;
                } while(cin.fail());

                if(tripod_allowed1 == true)
                {

                    do
                    {
                        clean();
                        cout<<endl<<"A moze ma już to cudo rozłożone  ? 1/0 to tak/nie "<<endl;
                        cin>>tripod1;
                    } while(cin.fail());

                }
                else tripod1=false;
        }
    if(ekstra==true&&mag==true) //różne konstruktóry dla odpowiednich danych /wszystko
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1,
                  magazine_size1,  magazine_type1,
                  silencer_allowed1,  tripod_allowed1,  tripod1,  silencer1);
    }

    if(ekstra==true&&mag==false) // dodatkowe elementy, ale standardowy magazynek
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1,
                  silencer_allowed1,  tripod_allowed1,  tripod1,  silencer1);
    }

    if(ekstra==false&&mag==false) // bez zbędnych bajerów i zwykły magazynek
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1 );

    }

    if(ekstra==false&&mag==true) // niestandardowy magazynek i brak dodatkowych elementów
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1,
                  magazine_size1,  magazine_type1 );
    }

    weapon_tab.push_back(pom); //dodajemy broń na wektor


}

void Menu:: aim(bool fire_mode) //podajemy w funkcji liczbe kul jakie chcemy wystrzelić i odległosć celu
{
    unsigned int bullet, distance;

    do
    {
        clean();
        cout<<endl<<"Podaj różną od zera liczbe pocisków, które chcesz wystrzelić"<<endl;
        cin>>bullet;

    } while( cin.fail()|| bullet == 0);

    do
    {
        clean();
        cout<<endl<<"Podaj dystans w jakim znajduje się cel zaokrąglając do pełnych metrów"<<endl;
        cin>>distance;

    } while( cin.fail()|| distance==0);

    cout<<"Trafiłeś do celu "<<Menu::weapon_tab[weapon_nr]->fire(bullet, distance, fire_mode)<< " razy"<<endl;


}
void Menu:: look() // szukamy broni do operatora dodawania
{
    int number=-1;

    cout<< "Podaj numer broni do połączenia: ";
    cin>> number;

            if(cin.good()==false)
            {
                cout<<"Bledne dane"<<endl;
                    cin.get();
                    clean();
                return;
            }

            for(unsigned int i=0; i< weapon_tab.size(); i++)
                {
                    if(number==static_cast<int>(i) && number!=weapon_nr)
                    {
                        (*weapon_tab[ weapon_nr ]) + (*weapon_tab[ number ]);
                        weapon_nr= weapon_tab.size()-1;
                        return;
                    }
                }

}

