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
    srand(time(NULL)); //inicjujemy generator liczb pseudolosowych
    #ifdef _DEBUG //testy

        weapon::tests();

    #endif
    Menu::Mainmenu();

    return 0;
}
