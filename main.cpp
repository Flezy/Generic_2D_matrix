#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include "matrix_szorzas.hpp"
#include "vector.hpp"
#include "memtrace.h"

using namespace std;

Vektor<Vektor<int> > Beolvas()
{
    int snumber, onumber;      // az aktuális mátrix sorszáma és oszlopsszáma
    std::cin>>snumber>>onumber;
    int tmp;

    Vektor<Vektor<int> > w(snumber);       // Vektorban Vektor
    Vektor<int> v(onumber);
    for (int i=0;i<snumber;i++)
    {


        for (int j=0;j<onumber; j++)                            // w mátrix létrehozása
        {
            std::cin>>tmp;
            v[j]=tmp;
        }

        w[i]=v;                     // Vektor elemi vektorok, így ezt megtehetjük

    }
    return w;
}

int main()
{
    _StartMemoryCheck() ;   // Memtrace
    Vektor<Vektor<int> > w, s;
    w.inic();
    s.inic();
    w=Beolvas();
    s=Beolvas();
    int snumber=w.getdb();
    Vektor<Vektor<int> > ER1(snumber);
    ER1.inic();
    Vektor<Vektor<int> > ER2(snumber);
    ER2.inic();
    ER1=w+s;
    std::cout<<w<<s<<ER1;
    ER2=w*2;
    std::cout<<ER2;
    Vektor<Vektor<int> > ER(snumber);
    ER.inic();
    matrix_szoroz<int>(w,s,ER);              // mátrixszorzás
    std::cout<<ER;
    _CrtDumpMemoryLeaks();

    return 0;
}
