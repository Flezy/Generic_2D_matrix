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
    int snumber, onumber;      // az aktu�lis m�trix sorsz�ma �s oszlopssz�ma
    std::cin>>snumber>>onumber;
    int tmp;
    std::cout<<"valami1";

    Vektor<Vektor<int> > w(snumber);       // Vektorban Vektor
    std::cout<<"valami2";
    Vektor<int> v(onumber);
    for (int i=0;i<snumber;i++)
    {
        std::cout<<"valami3";


        for (int j=0;j<onumber; j++)                            // w m�trix l�trehoz�sa
        {
            std::cin>>tmp;
            v[j]=tmp;
        }
        std::cout<<"valami4";

        w[i]=v;                     // Vektor elemi vektorok, �gy ezt megtehetj�k

    }
    std::cout<<"return";
    return w;
}

int main()
{
    _StartMemoryCheck() ;   // Memtrace
    Vektor<Vektor<int> > w, s;
    w.inic();
    s.inic();
    std::cout<<"olvasok\n";
    w=Beolvas();
    std::cout<<"olvasok\n";
    s=Beolvas();
    std::cout<<"koszke\n";
    int snumber=w.getdb();
    int onumber=w[0].getdb();
    std::cout<<"valami8";
    Vektor<Vektor<int> > ER1(snumber);
    ER1.inic();
    std::cout<<"valami9";
    Vektor<Vektor<int> > ER2(snumber);
    ER2.inic();
    std::cout<<"valami";
    ER1=w+s;
    std::cout<<"valami";
    std::cout<<w<<s<<ER1;
    ER2=w*2;
    std::cout<<ER2;
    Vektor<Vektor<int> > ER(snumber);
    ER.inic();
    matrix_szoroz<int>(w,s,ER);              // m�trixszorz�s
    std::cout<<ER;
    _CrtDumpMemoryLeaks();

    return 0;
}
