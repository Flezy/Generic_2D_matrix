#ifndef VECTOR_HPP
#define VECTOR_HPP
#include<iostream>
#include<typeinfo>
#include"memtrace.h"
#include<fstream>
#include<cstdio>
#include<cstdlib>
using std::ostream;
using namespace std;

template <class elemtipus>           // Vektor elõdekralárása
class Vektor;

template <class elemtipus>                  // "<<" operator elõdekralárása
ostream& operator<<(ostream& os, Vektor<elemtipus>& V);

template <class elemtipus>
class Vektor
{
private:
    elemtipus *data;                    // Elemtipus pointer ami mutat a vektorunk kezdetére
    int db;                                 // vektorunk hossza
public:
    Vektor(const Vektor<elemtipus> & V)                    // másoló konstruktor
    {
        std::cout<<"konst1("<<V.db<<":"<<V.data[0]<<")";
        db = V.db;
        data = (elemtipus*)malloc (db*sizeof(elemtipus));
        for (int i=0; i<db; i++)
        {
            data[i]=V.data[i];
        }
    }

    friend std::ostream & operator<< <elemtipus>(std::ostream & os, Vektor<elemtipus> & V);         // friend deklaráció

    Vektor <elemtipus>(int n=0): data(NULL),db(n)
    {
        std::cout<<"konst2";
        try
        {
            data = (elemtipus*)malloc (n*sizeof(elemtipus));
            if (typeid(elemtipus) == typeid(int))
            {
                for (int i=0;i<db;i++)
                {
                    std::cout<<"data["<<i<<"]=0;";
                    data[i]=0;
                }
            }
            else
            {
                for (int i=0;i<db;i++)
                {
                    std::cout<<"data["<<i<<"].inic();";
                    ((Vektor*)data)[i].inic();
                }
            }
        }
        catch (std::bad_alloc)
        {
            std::cerr<<"rossz foglalás";
        }
    }

    void szunjmeg()
    {
        free(data);
    }

    ~Vektor()
    {
        if (typeid(elemtipus) != typeid(int))
            for (int i=0;i<db;i++)
                ((Vektor*)data)[i].szunjmeg();
        szunjmeg();
    }

    void inic()
    {
        std::cout<<"inic";
        db=0;data=NULL;
    }

    Vektor & operator= (Vektor V)                 // = operator, ami többszörösen is használható
    {
        if (this==&V) return *this;
        std::cout<<"haho"<<V[0];
        if (data!=NULL)
            free(data);
        db=V.db;
        data = (elemtipus*)malloc (db*sizeof(elemtipus));
        for (int i=0; i<db; i++)
        {
            data[i]=V.data[i];
        }
        return (*this);
    }

    class iter                          // iterátor osztály és benne a szükséges operator átdefinálásokkal
    {
        int i;
        Vektor *tmp;
    public:
        iter(Vektor & w): tmp(&w), i(0) {}
        bool has_next()
        {
            return i<tmp->db;
        }
        elemtipus & operator *()
        {
            return tmp->data[i];
        }
        iter & operator ++()
        {
            i++;
            return *this;
        }
    };
    elemtipus & operator[](int i)
    {
        if (i>=db)
        {
            std::cout<<"túlindexelés";
        }
        return data[i];
    }
    const elemtipus & operator[](int i) const           // [] operator konstans módon is
    {
        if (i>=db)
        {
            std::cout<<"túlindexelés";
            return 0;
        }
        return data[i];
    }
    int getdb()                                                 // getter (db) fgv
    {
        return db;
    }
    Vektor<elemtipus> operator+ (Vektor<elemtipus> &V)
    {
        Vektor<elemtipus>TMP(db);
        for (int i=0; i<db; i++)
        {
            TMP.data[i]=data[i]+V.data[i];
        }
        return TMP;
    }
    Vektor<elemtipus> operator* (int skal)
    {
        Vektor<elemtipus>TMP(db);
        for (int i=0; i<db; i++)
        {
            TMP.data[i]=data[i]*skal;
        }
        return TMP;
    }
};

template <class elemtipus>                                              // "<<" operator definiálás
ostream& operator<<(ostream& os, Vektor<elemtipus>& V)
{
    for (int i=0; i<V.db; i++)
        os<<" "<<V.data[i];
    os<<"\n";
    return os;
}


#endif
