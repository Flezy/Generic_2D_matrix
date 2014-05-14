#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include "matrix_szorzas.hpp"
#include "vector.hpp"
#include "memtrace.h"

Vektor<Vektor<int> > Beolvas()
{
    int snumber, onumber;      // az aktuális mátrix sorszáma és oszlopsszáma
    std::cin>>snumber>>onumber;
    int tmp;
    std::cout<<"valami1";

    Vektor<Vektor<int> > w(snumber);       // Vektorban Vektor
    std::cout<<"valami2";
    Vektor<int> v(onumber);
    for (int i=0;i<snumber;i++)
    {
        std::cout<<"valami3";


        for (int j=0;j<onumber; j++)                            // w mátrix létrehozása
        {
            std::cin>>tmp;
            v[j]=tmp;
        }
        std::cout<<"valami4";

        w[i]=v;                     // Vektor elemi vektorok, így ezt megtehetjük

    }
    return w;
}

using namespace std;

int main()
{
    _StartMemoryCheck() ;   // Memtrace
    Vektor<Vektor<int> > w, s;
    w=Beolvas();
    s=Beolvas();
    int snumber=w.getdb();
    int onumber=w[0].getdb();
    Vektor<Vektor<int> > ER(snumber);
    std::cout<<"valami8";

    Vektor<Vektor<int> > ER1(snumber);
    std::cout<<"valami9";
    Vektor<Vektor<int> > ER2(snumber);
    std::cout<<"valami";
    ER1=w+s;
    std::cout<<"valami";
    std::cout<<w<<s<<ER1;
    ER2=w*2;
    std::cout<<ER2;
    matrix_szoroz<int>(w,s,ER);              // mátrixszorzás
    std::cout<<ER;
    _CrtDumpMemoryLeaks();

    return 0;
}
