#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

#include "weapon.h"
void Menu();


using namespace std;

int main()
{
    Menu();

    weapon temp;
    vector<weapon>weapon_tab;
    temp.show();
    return 0;
}
void Menu()
{
    cout<<"Witaj na strzelnicy.\n"<<endl;
    cout<<"Co chcesz zrobić ? "<<endl;
    cout<<"Wybierz 1, aby wyświetlić liste wszystkich dostepnych broni"<<endl;
    cout<<"Wybierz 2, aby wybrac bron o podanym numerze"<<endl;
    cout<<"Wybierz 3, aby dodac nowa bron do bazy"<<endl;
    cout<<"Wybierz 4, aby zapisac liste broni do pliku"<<endl;
    cout<<"Wybierz 5, aby odczytac liste broni z pliku"<<endl;
    cout<<"Wybierz 6, aby wyjsc z programu"<<endl;
    cout<<"Kazdy wybor nalezy potwierdzic przyciskiem enter."<<endl<<endl;
    char znak=getchar();
    switch(znak)
    {
        case
    }


}
