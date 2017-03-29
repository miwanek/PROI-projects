#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

#include "menu.h"
#include "weapon.h"


using namespace std;






 std::vector<weapon*> Menu::weapon_tab;
 weapon* Menu::pom;

    int Menu::weapon_nr;
    int Menu::celc;
    bool Menu::bylo;
    bool Menu::start;



void Menu::Mainmenu()
{
  //  temp=new weapon();
 //   Menu::weapon_tab.push_back(temp);
  //  cout<<Menu::weapon_tab.size()<<endl;
  //  getchar();
  //  clean();
    char znak;
    char akcja;
    do
    {

    Info1();
    znak=cin.get();
    clean();
        switch(znak)
        {
        case '1':
            cout<<"To wszystkie bronie jakie sie obecnie znajduja w strzelnicy"<<endl<<endl;
            for(unsigned int i=0;i<Menu::weapon_tab.size();i++)
            {
                cout<<"Bron o numerze: " <<i<<" znana jako: "<<Menu::weapon_tab[i]->name<<endl;
            }
            break;

        case '2':
            cout<< "Podaj poprawny  numer broni: ";
            cin>> weapon_nr;
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
                    if(weapon_nr==static_cast<int>(i))
                        {
                        Menu::weapon_tab[weapon_nr]->cool();
                        bool fire_mode;
                           do
                           {
                                system("clear");
                                cout<< "Wybrales bron o nazwie: "<< Menu::weapon_tab[weapon_nr]->name <<" oraz numerze: "<< weapon_nr << endl << endl;
                                Info2();
                                akcja=cin.get();
                                clean();
                            switch(akcja)
                            {

                                case '1':

                                    Menu::weapon_tab[weapon_nr]->show();
                                    break;

                                case '2':

                                    delete Menu::weapon_tab[weapon_nr];
                                    Menu::weapon_tab.erase(Menu::weapon_tab.begin() + weapon_nr);
                                    cout<< "Usunieto bron z bazy \n \n";
                                    break;


                                case '3':

                                    break;

                                case '4':

                                    fire_mode=false;
                                    cout<< "Strzelasz do tarczy ogniem pojedynczym" << endl;
                                    Menu::aim(fire_mode);


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
                                        Menu::aim(fire_mode);
                                        break;
                                    }


                                case '6':

                                    Menu::weapon_tab[weapon_nr]->magazine.reload();
                                    break;

                                case '7':

                                    Menu::weapon_tab[weapon_nr]->cool();
                                    break;

                                case '8':
                                    (*Menu::weapon_tab[weapon_nr])++;
                                    break;

                                case '9':
                                    (*Menu::weapon_tab[weapon_nr])--;
                                    break;

                                case '0':
                                    !(*Menu::weapon_tab[weapon_nr]);
                                    break;

                                case 'a':
                                    &(*Menu::weapon_tab[weapon_nr]);
                                    break;

                                case 'b':
                                    break;

                                default:
                                    break;
                            }
                            cin.get();
                            clean();

                            } while(akcja!='b'&& akcja != '2');
                        bylo=true;
                    }
                }
            if(bylo==false){ cout<<"Nie ma takiej broni w skladzie"<<endl;}
            break;

        case '3':
            {
               {

                    add();

                }
            break;
            }
        case '4':
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
            weapon::change_temperature(celc);
            break;

        case '5':

            weapon::current_temperature();
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
    while(znak!='6');
   // cout<<Menu::weapon_tab.size()<<endl;


}
void Menu::clean()
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
    weapon_nr=-1;
    celc= -100;
    bylo=false;
    start=true;


}

void Menu::Info2()
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
    float weight1=-1, caliber1=-1;
    unsigned int accuracy1=0, firerate1=0, magazine_size1=0, range1=0;
    string name1, magazine_type1;
    bool full_auto1, silencer_allowed1, silencer1, tripod_allowed1, tripod1, ekstra, mag;

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
        cout<<endl<<"Podaj kaliber broni w milimetrach  "<<endl;
        cin>>caliber1;
        clean();
    } while(caliber1<=0);

    do{
        cout<<endl<<"Podaj wage broni w kg  "<<endl;
        cin>>weight1;
        clean();
    } while(weight1<=0);
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
    if(ekstra==true&&mag==true)
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1,
                  magazine_size1,  magazine_type1,
                  silencer_allowed1,  tripod_allowed1,  tripod1,  silencer1);
    }

    if(ekstra==true&&mag==false)
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1,
                  silencer_allowed1,  tripod_allowed1,  tripod1,  silencer1);
    }

    if(ekstra==false&&mag==false)
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1 );

    }

    if(ekstra==false&&mag==true)
    {
        pom= new weapon(  range1,  weight1,  caliber1,   accuracy1,
                 firerate1,  name1,  full_auto1,
                  magazine_size1,  magazine_type1 );
    }

    weapon_tab.push_back(pom);


}

void Menu:: aim(bool fire_mode)
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

