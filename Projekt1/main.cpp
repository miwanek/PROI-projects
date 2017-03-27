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
    cout<<"Wciśnij 4, aby zapisac liste broni do pliku"<<endl;
    cout<<"Wciśnij 5, aby odczytac liste broni z pliku"<<endl;
    cout<<"Wciśnij 6, aby wyjsc z programu"<<endl;
    int weapon_nr=-1;
    bool bylo=false;
    znak=getchar();
    clean();
        switch(znak)
        {
        case '1':
            cout<<"To wszystkie bronie jakie sie obecnie znajduja w strzelnicy"<<endl<<endl;
            for(int i=0;i<weapon_tab.size();i++)
            {
                cout<<"Bron o numerze: " <<i<<" znana jako: "<<weapon_tab[i].name<<endl;
            }
            break;

        case '2':
            cout<<"Podaj poprawny  numer broni: ";
            cin>>weapon_nr;
            if(cin.good()==false)
            {
                cout<<"Bledne dane"<<endl;
                break;
            }
                for(int i=0; i<weapon_tab.size(); i++)
                {
                    if(weapon_nr==i)
                        {
                            cout<<"Wybrales bron o nazwie: "<<weapon_tab[weapon_nr].name<<" oraz numerze: "<<weapon_nr<<endl<<endl;
                            cout<<"Co chcesz zrobic?"<<endl;
                            cout<<"Wybierz 1, aby wyswietlic parametry broni"<<endl;
                            cout<<"Wybierz 3, aby poprawic parametry broni"<<endl;
                            cout<<"Wybierz 4, aby usunac bron z bazy"<<endl;
                            cout<<"Wybierz 5, aby strzelac do tarczy ogniem pojedyńczym" <<endl;
                            cout<<"Wybierz 6, aby strzelac do tarczy ogniem automatyczny"<<endl;
                            cout<<"Wybierz 6, aby przeladowac karabin"<<endl
                            cout<<"Wybierz 7, aby schlodzic lufe do temperatury pokojowej"<<endl;
                            cout<<"Wybierz 8, aby zalozyc tlumik na lufe karrabinu"<<endl;
                            cout<<"Wybierz 9, aby

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
               cout<<"4"<<endl;
            break;
        case '5':
               cout<<"5"<<endl;
            break;
        case '6':
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
