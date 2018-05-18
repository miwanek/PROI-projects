#include <cstdlib>
#include <cstring>
#ifndef NEW_VECTOR_H
#define NEW_VECTOR_H
/*! \file */

/// Szablon naszego wektora
template< typename T >
class New_vector
{
    private:
        unsigned int capacity; ///< pojemnosc wektora
        unsigned int vector_size; ///< rozmiar wektora
        T* new_vector;

    public:
        New_vector(size_t number= 5);
        New_vector( New_vector& v);
        New_vector( New_vector&& v);
        ~New_vector();
        T& operator[] (unsigned int i);
        void operator=( New_vector& v);
        New_vector& operator= ( New_vector&& v );
        New_vector<T> operator+( New_vector<T>& v);
        bool operator==( New_vector& v);
        bool operator>( New_vector& v);
        bool operator>=( New_vector& v);
        bool operator<( New_vector& v);
        bool operator<=( New_vector& v);
        void add_last(T);
        unsigned int show_capacity();
        unsigned int show_size();
        bool dispose(unsigned int nr);
        bool dispose(unsigned int nr, unsigned int amount);
        void  extend();
        void  extend(unsigned int nr);
        bool  put(unsigned int place, T data);
        bool  put(unsigned int place, T* data,unsigned int number);
        bool empty_vector();
        bool shrink();

    protected:


};

template< typename T  > New_vector<T >::New_vector( New_vector&& v)///< Konstruktor przenoszący
{

    new_vector= (v.new_vector);
    v.new_vector=nullptr;
    capacity= (v.capacity);
    v.capacity=0;
    vector_size=v.vector_size;
    v.vector_size=0;
    //std::cout<<" move ruct";

}


template< typename T  > New_vector<T>& New_vector <T>::operator=( New_vector&& v)///< Przenoszacy operator przypisania
{
    new_vector= v.new_vector;
    v.new_vector=nullptr;
    capacity= v.capacity;
    v.capacity=0;
    vector_size= v.vector_size;
    v.vector_size=0;
   // std::cout<<" move assigment";
    return *this;

}
template< typename T >New_vector<T >::New_vector(size_t number ) ///< Podstawowy konstruktor do którego podajemy liczbe elementów wektora
{
    new_vector= new(std::nothrow) T[number];
    if(!new_vector)
    {
        std::cout<<"brak pamieci";
        exit(0);
    }
    capacity=number;
    vector_size=0;
}

template< typename T  >New_vector<T >::~New_vector()///< Zwykly destuktor zwalnaijacy pamiec
{
   delete[] new_vector;
   //std::cout<<"usuwamy wektor";
}

template< typename T  > T& New_vector<T >:: operator[] (unsigned int i) ///< Operator wyłuskania
{
    if(i>=vector_size) exit(0);
    return new_vector[i]; //*(new_vector+i);
}

 template< typename T  >void New_vector<T >::add_last( T data)///< Funkcja dodaje dany element na koniec wektor. W razie potrzeby alokuje pamiec
{
    if(vector_size==capacity) extend();
    new_vector[vector_size]= data;
    vector_size++;
}

 template< typename T   >unsigned int New_vector<T >::show_capacity()///< Pokazuje obecna pojemnosc
{
    return capacity;
}

 template< typename T  >unsigned int New_vector<T  >::show_size()///< Pokazuje obecny rozmiar
{
    return vector_size;
}

 template< typename T   >void  New_vector<T  >::extend()///< Dwukrotnie zwieksza objetosc
{
    unsigned int new_capacity=capacity;
    new_capacity*=2;
    T* help_vector= new(std::nothrow) T[new_capacity];
    if(!help_vector)
    {
        std::cout<<"brak pamieci";
        exit(0);
    }
    for(size_t i=0; i<capacity;i++)
    {
        help_vector[i]= new_vector[i];   ///< kopiujemy dane ze starej tablicy do nowej rozszerzonej
    }

    delete[] new_vector;
    capacity=new_capacity;
    new_vector=help_vector;
}

 template< typename T  >void  New_vector<T  >::extend(unsigned int nr)///<Funkcja rozszerzaja wektor o x miejsc na elementy
{
    unsigned int new_capacity=capacity + nr;
    T* help_vector= new(std::nothrow) T[new_capacity];
    if(!help_vector)
    {
        std::cout<<"brak pamieci";
        exit(0);
    }
    for(size_t i=0; i<capacity;i++)
    {
        help_vector[i]= new_vector[i];   ///< Kopiujemy dane ze starej tablicy do nowej rozszerzonej
    }

    delete[] new_vector;
    capacity=new_capacity;
    new_vector=help_vector;
}

 template< typename T >bool New_vector<T  >::dispose(unsigned int nr)///<Funkcja usuwaja element o danym indeksie
{
   if(nr>=vector_size) return false;

   else
   {
       for(size_t i=nr; i<vector_size-1;i++)
       {
           new_vector[i]=new_vector[i+1];
       }
       vector_size--;
       return true;
   }
}


 template< typename T >bool New_vector<T  >::dispose(unsigned int nr, unsigned int amount ) ///< Przeładowana funkcja usuwajaca x elementów zaczynając k tej pozycji
{
   if((nr+amount) >=vector_size) return false;

   else
   {
       for(size_t i=nr; i<vector_size-amount;i++)
       {
           new_vector[i]=new_vector[i+amount];
       }
       vector_size-= amount;
       return true;
   }
}



 template< typename T > bool New_vector<T  >:: put(unsigned int place, T data) ///< Funkcja wstawiajaca element na dane miejsce
{
    if(place>vector_size) return false;
    else
    {
        if(vector_size == capacity) extend();
        for( size_t i=vector_size; i> place; i-- )
        {
            new_vector[i]=new_vector[i-1];
        }
        new_vector[place]=data;
        vector_size++;
        return true;
    }
}
/**
    Przeładowana funkcja dodajaca x elementow z wektora. Jako argumenty podajemy: 1) miejsce wstawienia elementów, 2) wskaznik na tablice,
    z której będziemy pobierać elementy, 3) liczbe elementow do wstawienia
*/
 template< typename T > bool New_vector<T  >:: put(unsigned int place, T* data, unsigned int number)
{

    if(place>vector_size) return false;
    else
    {
        unsigned int new_size=vector_size+ number;
        if(capacity< new_size) extend(new_size-capacity);
        for( size_t i=vector_size; i> place; i-- )
        {
            new_vector[i+number-1]=new_vector[i-1];
        }
        for(size_t i=0; i<number;i++)
        {
            new_vector[i+place]=data[i];
        }
        vector_size+=number;
        return true;
    }
}


 template< typename T >bool New_vector<T  >::empty_vector() ///< Banalna funkcja sprawdzająca czy wektor jest pusty
{
    if(vector_size == 0) return true;
    else return false;
}

 template< typename T  >bool New_vector<T >::shrink()///< Zmniejsza pojemnosc do rozmiaru wektora, realokujac pamiec oczywiscie
{
    if(vector_size == capacity) return false;
    T* help_vector= new(std::nothrow) T[vector_size];
    if(!help_vector)
    {
        std::cout<<"brak pamieci";
        exit(0);
    }
    for(size_t i=0; i<vector_size;i++)
    {
        help_vector[i]= new_vector[i];   ///< kopiujemy dane ze starej tablicy do nowej rozszerzonej
    }

    delete[] new_vector;
    capacity=vector_size;
    new_vector=help_vector;
    return true;
}


template< typename T  > New_vector<T >::New_vector( New_vector& v)///< Konstruktor kopiujacy
{

    new_vector= new T[v.capacity];
    for(size_t i ; i< v.vector_size;i++)
    {
        new_vector[i]= v.new_vector[i];
    }
    capacity=v.capacity;
    vector_size=v.vector_size;

}

template< typename T  > void New_vector <T > ::operator=( New_vector& v) ///< operator przypisania dla wektora
{

    delete [] new_vector;
    new_vector= new(std::nothrow) T[v.capacity];
    if(!new_vector)
    {
        std::cout<<"brak pamieci";
        exit(0);
    }
    for(size_t i=0 ; i< v.vector_size;i++)
    {
        new_vector[i]= v.new_vector[i];
    }
    capacity=v.capacity;
    vector_size=v.vector_size;

}
template< typename T  > bool New_vector <T > ::operator==( New_vector& v) ///<Sprawdza czy rozmiar jest równy
{
    if(vector_size== v.vector_size) return true;
    else return false;
}

/// Operator sprawdza czy rozmiar pierwszego wektora jest wiekszy od rozmiaru drugiego
template< typename T  > bool New_vector <T > ::operator>( New_vector& v)
{
    if(vector_size> v.vector_size) return true;
    else return false;

}

/// Operator sprawdza czy pojemnosc pierwszego wektora jest wieksza od pojemnosci drugiego
template< typename T  > bool New_vector <T > ::operator>=( New_vector& v)
{
    if(capacity > v.capacity) return true;
    else return false;
}

/// Operator sprawdza czy rozmiar pierwszego wektora jest mniejszy od pojemnosci drugiego
template< typename T  > bool New_vector <T > ::operator<( New_vector& v)
{
    if(vector_size < v.vector_size) return true;
    else return false;
}
/// Operator sprawdza czy pojemnosc pierwszego wektora jest mniejsza od pojemnosci drugiego
template< typename T  > bool New_vector <T > ::operator<=( New_vector& v)
{
    if( capacity < v.capacity) return true;
    else return false;
}
 /**Generyczna funkcja dodająca dwa wektory. Dodaje na końcu pierwszego wektora  elementy drugiego wektora oraz modyfikuje rozmiar i pojemnosc
    pierwszego wektora do liczby elementow w nowym, powiekszonym wektorze*/
template< typename T  > New_vector<T >  New_vector <T > ::operator+( New_vector<T> & v)
{

    unsigned int total_size= vector_size+ v.vector_size;
    New_vector<T> out;
    delete [] out.new_vector;
    out.new_vector= new(std::nothrow) T[total_size];
    if(!(out.new_vector) )
    {
        std::cout<<"brak pamieci";
        exit(0);
    }
    for(size_t i=0 ; i< vector_size ;i++)
    {
        out.new_vector[i]= new_vector[i];
    }
    for(size_t i=0 ; i< v.vector_size ;i++)
    {
        out.new_vector[i+vector_size]= v.new_vector[i];
    }
    out.vector_size= total_size;
    out.capacity= total_size;
    return out;
}



/** Specjalizowana funkcja dla intów dodająca do siebie zawartości odpowiednich pól dwóch wektorów. Rozmiar jak i pojemność wynikowego wektora jest równa
    większemu z dwóch */
 template<> inline New_vector<int> New_vector<int>::operator+( New_vector<int>& v)
{
    New_vector<int> out;
    delete [] out.new_vector;
    if(vector_size> v.vector_size) out.vector_size= vector_size;
    else out.vector_size= v.vector_size;
    out.capacity= out.vector_size;
    out.new_vector= new(std::nothrow) int[out.vector_size];
    if(!(out.new_vector) )
    {
        std::cout<<"brak pamieci";
        exit(0);
    }

    for( size_t i =0; i< out.vector_size;i++)
    {
        out.new_vector[i]=0;
       if(vector_size > i )   out.new_vector[i]+= new_vector[i];

       if(v.vector_size > i )  out.new_vector[i]+=v.new_vector[i];
    }


    return out;
}
/** Funkcja sprawdzającą czy dwa wektory zawierają te same elementy. W przypadku, gdy liczba przechowywanych elementów się zgadza sprawdzana
    jest zgodność wszystkich elementów na odpowiednich pozycjach */
template<  > inline bool New_vector <int > ::operator==( New_vector<int>& v)
{
   if(vector_size!= v.vector_size) return false;
   else
   {
       for(size_t i=0; i<vector_size; i++ )
       {
           if(new_vector[i]!= v.new_vector[i]) return false;
       }
       return true;
   }
}

/** Operator sprawdzający czy pierwszy wektor jest "wiekszy" leksykograicznie od drugiego. Sprawdza po kolei każdy element zgodnie z zasadami
    porzadku leksykograficznego */
template<  > inline bool New_vector <int > ::operator>=( New_vector<int>& v)
{
       unsigned int max_size;
       if(vector_size> v.vector_size) max_size= vector_size;
       else max_size= v.vector_size;

       for(size_t i=0; i< max_size; i++ )
       {
           if(i== vector_size && i== v.vector_size ) return false;
           if(i== vector_size && i< v.vector_size ) return false;
           if(i== v.vector_size && i< vector_size ) return true;

           if(new_vector[i] > v.new_vector[i] ) return true;
           if(new_vector[i] < v.new_vector[i] ) return false;
       }
       return false;
}

/** Operator sprawdzający czy pierwszy wektor jest "mniejszy" leksykograicznie od drugiego. Sprawdza po kolei każdy element zgodnie z zasadami
    porzadku leksykograficznego */
template<  > inline bool New_vector <int > ::operator<=( New_vector<int>& v)
{
       unsigned int max_size;
       if(vector_size> v.vector_size) max_size= vector_size;
       else max_size= v.vector_size;

       for(size_t i=0; i< max_size; i++ )
       {
           if(i== vector_size && i== v.vector_size ) return false;
           if(i== vector_size && i< v.vector_size ) return true;
           if(i== v.vector_size && i< vector_size ) return false;

           if(new_vector[i] < v.new_vector[i] ) return true;
           if(new_vector[i] > v.new_vector[i] ) return false;
       }
       return false;
}

/** Operator sprawdzający czy suma elemntów pierwszego wektora  jest mniejsza od sumy elementów drugiego wektora */
template<  > inline bool New_vector <int > ::operator<( New_vector<int>& v)
{
    unsigned int sum1= 0;
    unsigned int sum2= 0;
    for(size_t i=0; i< vector_size; i++)
    {
        sum1+= new_vector[i];
    }

    for(size_t i=0; i< v.vector_size; i++)
    {
        sum2+= v.new_vector[i];
    }
    if(sum1< sum2) return true;
    else return false;
}

/** Operator sprawdzający czy suma elemntów pierwszego wektora  jest wieksza od sumy elementów drugiego wektora */
template<  > inline bool New_vector <int > ::operator>( New_vector<int>& v)
{
    unsigned int sum1= 0;
    unsigned int sum2= 0;
    for(size_t i=0; i< vector_size; i++)
    {
        sum1+= new_vector[i];
    }

    for(size_t i=0; i< v.vector_size; i++)
    {
        sum2+= v.new_vector[i];
    }
    if(sum1> sum2) return true;
    else return false;
}








#endif // NEW_VECTOR_H
