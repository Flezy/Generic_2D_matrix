#ifndef MATRIX_SZOROZ
#define MATRIX_SZOROZ
#include "vector.hpp"
#include<iostream>
#include"memtrace.h"

template <class elemtipus>
void matrix_szoroz(Vektor <Vektor<elemtipus> >& A, Vektor <Vektor<elemtipus> >& B, Vektor<Vektor<elemtipus> >& C)
{
    C=A;
    if (A[0].getdb()!=B.getdb()) {std::cerr<<"hiba, ezt a ket matrixot nem lehet osszeszorozni!";return;}
    int snumber=A.getdb(), onumber=B[0].getdb();
    elemtipus s=0;                                      // mátrixszozás, melyben legelõször megvizsgálja, hogy a
                                                // mátrixszorzás alapfeltétele (PxQ (x) QxR = PxR) teljesüljön
    for(int i=0; i<snumber; i++)
    {
        for(int j=0; j<onumber; j++)                // "s" fogja tárolni nekünk az eredmény mátrix aktuális elemének értékét
        {
            for(int k=0; k<B.getdb(); k++)
                s=s+A[i][k]*B[k][j];
            C[i][j]=s;
            s=0;
        }
    }
}

#endif // MATRIX_SZOROZ
