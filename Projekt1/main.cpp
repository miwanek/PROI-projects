#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

#include "getch.h"
#include "weapon.h"

void Menu();
void clean();


using namespace std;

int main()
{

    #ifdef _DEBUG
        cout << "Testujemy tralalala"<<endl;
    #endif
    Menu();

    return 0;
}
void Menu()
{

    weapon temp;
    vector<weapon>weapon_tab;
    temp.show();
    weapon_tab.push_back(temp);
    cout<<weapon_tab.size()<<endl;
   // weapon_tab.erase(weapon_tab.begin());
    cout<<weapon_tab.size()<<endl;
    getchar();
    clean();
    char znak;
    char akcja;
    do
    {
    system("clear");
    cout<<"Witaj na strzelnicy.\n"<<endl;
    cout<<"Co chcesz zrobić ? "<<endl;
    cout<<"Wciśnij 1, aby wyświetlić liste wszystkich dostepnych broni"<<endl;
    cout<<"Wciśnij 2, aby wybrac bron o podanym numerze"<<endl;
    cout<<"Wciśnij 3, aby dodac nowa bron do bazy"<<endl;
    cout<<"Wybierz 4, aby zmienic temperature otoczenia" << endl;
    cout<<"Wybierz 5, aby pokazac temperature otoczenia" << endl;
    cout<<"Wciśnij 6, aby zapisac liste broni do pliku"<<endl;
    cout<<"Wciśnij 7, aby odczytac liste broni z pliku"<<endl;
    cout<<"Wciśnij 8, aby wyjsc z programu"<<endl;
    int weapon_nr=-1;
    bool bylo=false;
    znak=cin.get();
    clean();
        switch(znak)
        {
        case '1':
            cout<<"To wszystkie bronie jakie sie obecnie znajduja w strzelnicy"<<endl<<endl;
            for(unsigned int i=0;i<weapon_tab.size();i++)
            {
                cout<<"Bron o numerze: " <<i<<" znana jako: "<<weapon_tab[i].name<<endl;
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
                for(unsigned int i=0; i<weapon_tab.size(); i++)
                {
                    if(weapon_nr==static_cast<int>(i))
                        {
                           do
                           {
                                system("clear");
                                cout<< "Wybrales bron o nazwie: "<< weapon_tab[weapon_nr].name <<" oraz numerze: "<< weapon_nr << endl << endl;
                                cout<< "Co chcesz zrobic?" << endl;
                                cout<< "Wybierz 1, aby wyswietlic parametry broni" << endl;
                                cout<< "Wybierz 2, aby poprawic parametry broni" << endl;
                                cout<< "Wybierz 3, aby usunac bron z bazy" << endl;
                                cout<< "Wybierz 4, aby porownac parametry tej oraz innej broni" << endl;
                                cout<< "Wybierz 5, aby polaczyc dwie bronie w nowa lepsza sztuke" << endl;
                                cout<< "Wybierz 6, aby strzelac do tarczy ogniem pojedyńczym" << endl;
                                cout<< "Wybierz 7, aby strzelac do tarczy ogniem automatyczny" << endl;
                                cout<< "Wybierz 8, aby uzupełnić magazynek" << endl;
                                cout<< "Wybierz 9, aby schlodzic lufe do temperatury pokojowej" << endl;
                                cout<< "Wybierz 0, aby zalozyc tlumik na lufe" << endl;
                                cout<< "Wybierz a, aby zdjac tlumik z lufy" << endl;
                                cout<< "Wybierz b, aby rozlozyc trojnog" << endl;
                                cout<< "Wybierz c, aby zlozyc trojnog" << endl;
                                cout<< "Wybierz d, aby odlozyc bron na miejsce" << endl;
                                akcja=cin.get();
                                clean();
                            switch(akcja)
                            {
                                case '1':
                                    weapon_tab[weapon_nr].show();
                                    break;
                                case '2':
                                    break;

                                case '3':
                                    break;

                                case '4':
                                    break;

                                case '5':
                                    break;

                                case '6':
                                    break;

                                case '7':
                                    break;

                                case '8':
                                    weapon_tab[weapon_nr].reload();
                                    break;

                                case '9':
                                    break;

                                case '0':
                                    break;

                                case 'a':
                                    break;

                                case 'b':
                                    break;

                                case 'c':
                                    break;

                                case 'd':
                                    break;

                                default:
                                    break;
                            }
                            cin.get();
                            clean();

                            } while(akcja!='d');
                        bylo=true;
                    }
                }
            if(bylo==false){ cout<<"Nie ma takiej broni w skladzie"<<endl;}
            break;

        case '3':
            {


               cout<<"Dodajemy nowy egzemplarz do bazy"<<endl;
            break;
            }
        case '4':
            weapon::change_temperature();
            break;
        case '5':
            weapon::current_temperature();
            break;
        case '6':
            break;

        case '7':
               cout<<"4"<<endl;
            break;

        case '8':
               cout<<"5"<<endl;
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
    cout<<weapon_tab.size()<<endl;


}
void clean()
{
    cin.clear();
    cin.ignore(10000,'\n');
}
