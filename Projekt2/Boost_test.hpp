#ifndef BOOST_TEST_HPP_INCLUDED
#define BOOST_TEST_HPP_INCLUDED
/*! \file */
#ifdef _DEBUG

#define BOOST_TEST_MODULE my test suite
#include <boost/test/included/unit_test.hpp>
#include "weapon.h"
///A to testy
BOOST_AUTO_TEST_CASE( custom_size_test ) ///< Sprawdzamy czy działa tworzenie wektora o odpowiedniej ilosci pamieci
{
  New_vector<int > tab(17);
  BOOST_CHECK_EQUAL(tab.show_capacity(),17);
  BOOST_CHECK_EQUAL(tab.show_size(),0);
  tab.add_last(7);
  BOOST_CHECK_EQUAL(tab[0],7);
  BOOST_CHECK_EQUAL(tab.show_size(),1);
}


BOOST_AUTO_TEST_CASE( basic_functions_test )///< Sprawdzamy podstawowe funkcjonalnosci
{
    New_vector<int> tab;
    BOOST_CHECK_EQUAL(tab.show_capacity(),5);
    BOOST_CHECK_EQUAL(tab.show_size(),0);
    tab.add_last(5);
    BOOST_CHECK_EQUAL(tab.show_size(),1);
    BOOST_REQUIRE_EQUAL(tab[0],5);
    tab.add_last(0);
    tab.add_last(2);
    tab.add_last(5);
    tab.add_last(6);
    tab.add_last(99);
    BOOST_CHECK_EQUAL(tab.show_size(),6);
    BOOST_CHECK_EQUAL(tab.show_capacity(),10);
    BOOST_CHECK_EQUAL(tab[5],99);
    BOOST_CHECK_EQUAL(tab[4],6);
    BOOST_CHECK_EQUAL(tab[3],5);
    BOOST_CHECK_EQUAL(tab[2],2);
    BOOST_CHECK_EQUAL(tab[1],0);
    tab.dispose(2); ///< usuwamy element i sprawdzamy czy dobrze przesuwa ustrojstwo
    BOOST_REQUIRE_EQUAL(tab[0],5);
    BOOST_CHECK_EQUAL(tab[4],99);
    BOOST_CHECK_EQUAL(tab[3],6);
    BOOST_CHECK_EQUAL(tab[2],5);
    BOOST_CHECK_EQUAL(tab[1],0);
    BOOST_CHECK_EQUAL(tab.show_size(),5);
    BOOST_WARN(tab.put(1,7) );
    BOOST_REQUIRE_EQUAL(tab[0] , 5);
    BOOST_REQUIRE_EQUAL(tab[1] , 7);
    BOOST_REQUIRE_EQUAL(tab[2] , 0);
    BOOST_REQUIRE_EQUAL(tab[3] , 5);
    BOOST_REQUIRE_EQUAL(tab[4] , 6);
    BOOST_REQUIRE_EQUAL(tab[5] , 99);
    BOOST_CHECK_EQUAL(tab.show_size(),6);
    BOOST_CHECK_EQUAL(tab.empty_vector(),false);
    BOOST_CHECK(tab.shrink());
    BOOST_CHECK_EQUAL(tab.show_capacity(),6);
    BOOST_CHECK(!tab.shrink());

}

BOOST_AUTO_TEST_CASE( test_constructor_copy) ///< test konstruktora kopiujacego
{
  New_vector<int > tab(1);
  tab.add_last(1);
  tab.add_last(2);
  tab.add_last(3);
  BOOST_CHECK_EQUAL(tab.show_capacity(),4);
  New_vector<int > tab2(tab);
  BOOST_CHECK_EQUAL(tab2.show_capacity(),4);

}

BOOST_AUTO_TEST_CASE( test_operator_assign) ///< test przypisania
{
  New_vector<int > tab(1);
  tab.add_last(4);
  tab.add_last(5);
  tab.add_last(6);
  BOOST_CHECK_EQUAL(tab[0],4);
  BOOST_CHECK_EQUAL(tab[1],5);
  BOOST_CHECK_EQUAL(tab[2],6);
  BOOST_CHECK_EQUAL(tab[0],4);
  New_vector<int > tab2(1);
  BOOST_CHECK_EQUAL(tab2.show_capacity(),1);
  tab2=tab;
  BOOST_CHECK_EQUAL(tab2.show_size(),tab.show_size());
  BOOST_CHECK_EQUAL(tab2[0],4);
  BOOST_CHECK_EQUAL(tab2[1],5);
  BOOST_CHECK_EQUAL(tab2[2],6);
  BOOST_CHECK_EQUAL(tab2.show_capacity(),4);
  BOOST_CHECK_EQUAL(tab2.show_size(),3);

}

BOOST_AUTO_TEST_CASE( test_operator_compare) ///< test comparatotów niewyspecjalizowanych
{
  New_vector<char > tab(2);
  tab.add_last('a');
  tab.add_last('b');
  tab.add_last('c');
  BOOST_CHECK_EQUAL(tab[0],'a');
  BOOST_CHECK_EQUAL(tab[1],'b');
  BOOST_CHECK_EQUAL(tab[2],'c');
  New_vector<char > tab2(2);
  tab2.add_last('b');
  BOOST_CHECK(tab > tab2);
  BOOST_CHECK(tab >= tab2);
  tab2.add_last('b');
  tab2.add_last('c');
  BOOST_REQUIRE(tab2 == tab);
  tab2.add_last('e');
  tab2.add_last('e');
  BOOST_CHECK( tab < tab2 );
  BOOST_CHECK( tab <= tab2 );

}

BOOST_AUTO_TEST_CASE( test_operator_add) ///<test elementarnego dodawania na koniec i operatora podstawianaia
{
  New_vector<char > tab(2);
  tab.add_last('a');
  tab.add_last('b');
  tab.add_last('c');
  BOOST_CHECK_EQUAL(tab[0],'a');
  BOOST_CHECK_EQUAL(tab[1],'b');
  BOOST_CHECK_EQUAL(tab[2],'c');
  New_vector<char > tab2(2);
  tab2.add_last('d');
  New_vector<char > tab3(2);
  tab3= (tab+tab2);
  BOOST_CHECK_EQUAL(tab3[0],'a');
  BOOST_CHECK_EQUAL(tab3[1],'b');
  BOOST_CHECK_EQUAL(tab3[2],'c');
  BOOST_CHECK_EQUAL(tab3[3],'d');

}

BOOST_AUTO_TEST_CASE( test_int) ///<test dodawania wektorów intów
{
  New_vector<int > tab(2);
  tab.add_last(1);
  tab.add_last(2);
  New_vector<int > tab2(2);
  tab2.add_last(2);
  tab2.add_last(3);
  tab2.add_last(7);
  New_vector<int > tab3(2);
  tab3=tab+tab2;
  BOOST_CHECK_EQUAL(tab3[0], 3);
  BOOST_CHECK_EQUAL(tab3[1], 5);
  BOOST_CHECK_EQUAL(tab3[2], 7);
}

BOOST_AUTO_TEST_CASE( test_int_equal) ///test operatora rownosci i usuwania
{
  New_vector<int > tab(2);
  tab.add_last(1);
  tab.add_last(2);
  New_vector<int > tab2(2);
  tab2.add_last(1);
  BOOST_CHECK_EQUAL(tab==tab2, false);
  tab2.add_last(2);
  BOOST_CHECK(tab==tab2 );
  BOOST_CHECK(tab2.dispose(1));
  tab2.add_last(3);
  BOOST_CHECK_EQUAL(tab==tab2, false);
}

BOOST_AUTO_TEST_CASE( test_int_compare_lexicograf) ///< test przeciazonego operatora <= dla int( porównywanie leksykograficzne tablic)
{
  New_vector<int > tab(2);
  tab.add_last(1);
  tab.add_last(2);
  New_vector<int > tab2(2);
  tab2.add_last(1);
  BOOST_CHECK_EQUAL(tab>=tab2, true);
  BOOST_CHECK_EQUAL(tab<=tab2, false);
  tab2.add_last(3);
  BOOST_CHECK_EQUAL(tab>=tab2, false);
  BOOST_CHECK_EQUAL(tab<=tab2, true);
  BOOST_CHECK(tab2.dispose(0));
  BOOST_CHECK_EQUAL(tab>=tab2, false);
  BOOST_CHECK(tab2.dispose(0));
  tab2.add_last(1);
  tab2.add_last(2);
  BOOST_CHECK_EQUAL(tab<=tab2, false);
}

BOOST_AUTO_TEST_CASE( test_int_compare_sum) ///< test przeciazonego operatora < dla int
{
  New_vector<int > tab(2);
  tab.add_last(3);
  tab.add_last(2);
  New_vector<int > tab2(2);
  tab2.add_last(7);
  tab2.add_last(6);
  BOOST_CHECK(tab< tab2);
  BOOST_CHECK_EQUAL(tab > tab2, false);
  tab.add_last(8);
  BOOST_CHECK_EQUAL(tab > tab2, false);
  BOOST_CHECK_EQUAL(tab < tab2, false);

}

BOOST_AUTO_TEST_CASE(test_weapon) ///< Test podstawowej klasy broni
{
    New_vector<weapon>tab;
    weapon pom(20,20,5,30,123,"Karabin",1);
    tab.add_last(pom);
    pom= weapon(20,20,5,30,123,"K98",1,40,"normalny",1,1,1,1);
    tab.add_last(pom);
    BOOST_CHECK_EQUAL(tab.show_size(),2);
    tab.dispose(0);
    BOOST_CHECK_EQUAL(tab[0].magazine.get_size(),40);
    BOOST_CHECK_EQUAL(tab[0].name,"K98");
    New_vector<weapon>tab2;
    pom= weapon(40,20,5,30,123,"mp44",1,45,"kolowy");
    tab2.add_last(pom);
    pom= weapon(40,20,5,30,300,"mp40",1,45,"kolowy",1,1,0,1);
    tab2.add_last(pom);
    pom= weapon(400,20,5,80,20,"gewehr44",1,45,"kolowy",1,1,0,1);
    tab2.add_last(pom);
    New_vector<weapon>tab3;
    tab3=tab+tab2;
    BOOST_REQUIRE_EQUAL(tab3.show_size(),4);
    BOOST_CHECK_EQUAL(tab3[2].name,"mp40");
    New_vector<weapon>tab4(100000);

}

BOOST_AUTO_TEST_CASE(test_magazine) ///< Test klasy magazynka
{
    New_vector<weapon::Magazine>tab;
    New_vector<weapon::Magazine>tab2(2);
    weapon::Magazine pom(20,"alibaba");
    tab.add_last(pom);
    pom= weapon::Magazine(25, "inny");
    tab.add_last(pom);
    BOOST_CHECK_EQUAL(tab.show_size(),2);
    tab.dispose(0);
    BOOST_CHECK_EQUAL(tab[0].get_size(),25);
    BOOST_CHECK_EQUAL(tab[0].get_type(),"inny");
    pom= weapon::Magazine();
    tab2.add_last(pom);
    pom= weapon::Magazine( 20, "boo");
    tab2.add_last(pom);
    pom= weapon::Magazine( 330, "wielki");;
    tab2.add_last(pom);
    New_vector<weapon::Magazine>tab3;
    tab3= tab+tab2;
    BOOST_REQUIRE_EQUAL(tab3.show_size(),4);
    BOOST_CHECK_EQUAL(tab3[1].get_size(),30);
    tab2=tab;
    BOOST_CHECK_EQUAL(tab2[0].get_size(),25);
    pom= weapon::Magazine(50,"tasmowy");
    tab.put(0,pom);
    BOOST_CHECK_EQUAL(tab[0].get_type(), "tasmowy");
    BOOST_CHECK_EQUAL(tab[0].get_size(), 50 );
    BOOST_REQUIRE(!tab.empty_vector());

}

BOOST_AUTO_TEST_CASE(test_multiple_remove) ///< Test wielokrotnego usuwania
{
    New_vector<weapon::Magazine>tab(6);
    weapon::Magazine pom(20,"alibaba1");
    tab.add_last(pom);
    pom= weapon::Magazine(25, "inny");
    tab.add_last(pom);
    pom= weapon::Magazine( 20, "tak");
    tab.add_last(pom);
    pom= weapon::Magazine( 330, "wielki");
    tab.add_last(pom);
    tab.dispose(1,2);
    BOOST_CHECK_EQUAL(tab[0].get_type(),"alibaba1");
    BOOST_CHECK_EQUAL(tab[1].get_type(),"wielki");
    BOOST_REQUIRE_EQUAL(tab.show_size(),2);

    New_vector<weapon::Magazine>tab2(6);
    pom= weapon::Magazine(25, "1");
    tab2.add_last(pom);
    pom= weapon::Magazine(25, "2");
    tab2.add_last(pom);
    pom= weapon::Magazine( 20, "3");
    tab2.add_last(pom);
    pom= weapon::Magazine( 330, "4");
    tab2.add_last(pom);
    tab2.dispose(0,0);
    BOOST_CHECK_EQUAL(tab2[0].get_type(),"1");
    BOOST_CHECK_EQUAL(tab2[1].get_type(),"2");
    BOOST_CHECK_EQUAL(tab2[2].get_type(),"3");
    BOOST_CHECK_EQUAL(tab2[3].get_type(),"4");
    BOOST_REQUIRE_EQUAL(tab2.show_size(),4);
    tab2.dispose(0,2);
    BOOST_CHECK_EQUAL(tab2[0].get_type(),"3");
    BOOST_CHECK_EQUAL(tab2[1].get_type(),"4");
    BOOST_REQUIRE_EQUAL(tab.show_size(),2);
}

BOOST_AUTO_TEST_CASE(test_multiple_add) ///< Test wielokrotnego dodawania
{
    weapon::Magazine* cos;
    cos= new weapon::Magazine[8];

    weapon::Magazine pom(20,"zboj1");
    cos[0]=pom;
    BOOST_CHECK_EQUAL(cos[0].get_type(),"zboj1");
    pom= weapon::Magazine(25, "zboj2");
    cos[1]=pom;
    pom= weapon::Magazine(26, "zboj3");
    cos[2]=pom;
    pom= weapon::Magazine(25, "zboj4");
    cos[3]=pom;


    New_vector<weapon::Magazine>tab2(2);
    pom= weapon::Magazine(25, "zboj5");
    tab2.add_last(pom);
    pom= weapon::Magazine(25, "zboj6");
    tab2.add_last(pom);

    tab2.put(1,cos,4);

    BOOST_REQUIRE_EQUAL(tab2.show_size(),6);
    BOOST_CHECK_EQUAL(tab2[0].get_type(),"zboj5");
    BOOST_CHECK_EQUAL(tab2[1].get_type(),"zboj1");
    BOOST_CHECK_EQUAL(tab2[2].get_type(),"zboj2");
    BOOST_CHECK_EQUAL(tab2[3].get_type(),"zboj3");
    BOOST_CHECK_EQUAL(tab2[4].get_type(),"zboj4");
    BOOST_CHECK_EQUAL(tab2[5].get_type(),"zboj6");
    tab2.put(0,cos,4);
    BOOST_CHECK_EQUAL(tab2[0].get_type(),"zboj1");
    BOOST_CHECK_EQUAL(tab2[1].get_type(),"zboj2");
    BOOST_CHECK_EQUAL(tab2[2].get_type(),"zboj3");
    BOOST_CHECK_EQUAL(tab2[3].get_type(),"zboj4");
    BOOST_REQUIRE_EQUAL(tab2.show_size(),10);
    BOOST_REQUIRE_EQUAL(tab2.show_size(),10);
    tab2.put(10,cos,3);
    BOOST_CHECK_EQUAL(tab2[10].get_type(),"zboj1");
    BOOST_CHECK_EQUAL(tab2[11].get_type(),"zboj2");
    BOOST_CHECK_EQUAL(tab2[12].get_type(),"zboj3");
    tab2.put(0,cos,0);
    BOOST_CHECK_EQUAL(tab2[0].get_type(),"zboj1");
    BOOST_CHECK_EQUAL(tab2[1].get_type(),"zboj2");
    BOOST_CHECK_EQUAL(tab2[2].get_type(),"zboj3");
    BOOST_CHECK_EQUAL(tab2[3].get_type(),"zboj4");
    BOOST_REQUIRE_EQUAL(tab2.show_size(),13);
}

BOOST_AUTO_TEST_CASE(test_extensive_numbers) ///< Test miliona intów
{
    int table[1000000];

    for( size_t i=0;i<1000000; i++ )
    {
        table[i]=i;
    }
    New_vector<int > tab(2);
    tab.add_last(7);
    tab.put(1,table,1000000);
    BOOST_CHECK_EQUAL(tab.show_size(),1000001);
    tab.dispose(2,10000);
    BOOST_CHECK_EQUAL(tab[0],7);
    BOOST_CHECK_EQUAL(tab[1],0);
    BOOST_CHECK_EQUAL(tab[2],10001);
    BOOST_CHECK_EQUAL(tab[3],10002);
    tab.dispose(6,500000);
    BOOST_CHECK_EQUAL(tab[6],510005);
}


BOOST_AUTO_TEST_CASE(test_move) ///< Test konstruktora przenoszacego i przenoszacego operatora przypisania
{
    New_vector<weapon::Magazine>tab;
    New_vector<weapon::Magazine>tab2(2);
    weapon::Magazine pom(20,"alibaba");
    tab.add_last(pom);
    BOOST_CHECK_EQUAL(tab[0].get_type(),"alibaba");
    pom= weapon::Magazine(25, "inny");
    tab.add_last(pom);
    pom= weapon::Magazine( 20, "abc");
    tab2.add_last(pom);
    tab2= std::move(tab);
    BOOST_CHECK_EQUAL(tab2[0].get_type(), "alibaba");
    BOOST_CHECK_EQUAL(tab.show_size(),0);
    New_vector<weapon::Magazine>tab3(std::move(tab2));
    BOOST_CHECK_EQUAL(tab2.show_size(),0);
    BOOST_CHECK_EQUAL(tab3[2].get_type(), "inny");

}

#endif

#endif // BOOST_TEST_HPP_INCLUDED
