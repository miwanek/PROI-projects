#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

#include "menu.h"
#include "weapon.h"
#include "new_vector.h"
#include "Boost_test.hpp"
/*! \file */
/** \mainpage Projekt 2 podsumowanie
*
* \section intro_sec Wstęp
*
*   W drugim projekcie za zadanie mieliśmy stworzyć kontener umożliwiający swobodne przechowywanie naszych danych z pierwszego projektu.
*   Najwygodniejsza w użyciu wydawała się dynamicznie alokowana tablica, znana jako wektor, którą zaimplementowałem.
*
* \section content_sec Zawartośc
*
*  Nasz wektor o nazwie New_Vector został zrealizowany za pomocą szablonu o jednym argumencie - nieznanym typie typename T.
*  Kontener posiada ponad to składowe prywatne: capacity odpowiadające za obecna pojemność wektora, czyli liczbe elementów jakie można do niego wrzucić
*  bez realokacji pamięci, vector_size mówiące ile elementów już znajduje się w wektorze oraz *T new_vector czyli wskaźnik na miejsce gdzie właściwie
*  znajdują się nasze przechowywane elementy. Dodany do programu jest prosty konstruktor kopiujący, a nasz bazowy konstruktor pozwala określić startową
*  pojemność wektora ( w przypadku braku argumentu domyślnie jest to 5 ).
*
*   Najważniejsze funkcje i zarazem funkcjonalności to:
*   - Dodawanie elementu na koniec wektora void add_last()
*   - Automatyczne zwiekszanie pojemnosci wektora w przypadku jego przepelnienia.
*      Zwiekszenie pojemnosci dwukrotne/ o okreslona wartosc : przeładowane funkcje extend
*   - Sprawdzanie czy wektor jest pusty:  bool vector_empty()
*   - Wyłuskiwanie elementów z wektora : T& operator[] (unsigned int i)
*   - Kopiowanie zawartości jednego wektora do drugiego void operator= (const New_vector& v)
*   - Sklejanie dwóch wektorów w jedną New_vector<T> operator+(const New_vector<T>& v)
*   - Sprawdzanie, który wektor ma wieksza pojemnosc, wielkosc: niewyspecjalizowane operatory > / < , <= / >= ==
*   - Podglądanie aktualnej pojemnosci wektora: unsigned int show_capacity()
*   - Podglądanie aktualnego rozmiaru wektora; unsigned int show_size()
*   - Usuwanie danego elementu/elementów : bool dispose(unsigned int nr, unsigned int amount)/ bool dispose(unsigned int nr)
*   - Wstawianie elementu/ elementów w danym miejscu: bool  put(unsigned int place, T data) / bool  put(unsigned int place, T* data)
*   - Zmniejszanie pojemnosci wektora do jego rozmiaru : bool shrink()
*
*  Specjalizacje operatorów dla inta:
*  -  + dodawanie elementów na odpowiednich pozycjach do siebie
*  -  </> okreslają dla ktorego wektora suma jego elemntow jest wieksza/ mniejsza
*  -  <= / >= porownuja oba wektory wzgledem porzadku leksykograficznego
*  -  == sprawdza czy wketory zawieraja taka samo liczbe elementów i czy te elementy sa sobie równe
*
*
*
*
*
*
 */


//    Menu::Mainmenu();
void Menu();
void clean();

using namespace std;
#ifndef _DEBUG
int main()
{
    srand(time(NULL)); //inicjujemy generator liczb pseudolosowych

    //weapon::tests();






    Menu::Mainmenu();

    return 0;
}
#endif
