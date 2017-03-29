#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

#include "menu.h"
#include "weapon.h"

void Menu();
void clean();


using namespace std;

int main()
{

    #ifdef _DEBUG
        cout << "Testujemy tralalala"<<endl;
    #endif
    Menu::Mainmenu();

    return 0;
}
