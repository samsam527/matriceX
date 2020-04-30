#include "matricX.h"
#include<iostream>
using namespace std;
matricX::matricX()
{
    nbl=nbc = 1;
    T = new double *[nbl];
    for(int i(0); i<nbl;i++)
    {
        T[i] = new double [nbc];
    }
}
matricX::matricX(int nbl, int nbc)
{
    this -> nbl = nbl;
    this -> nbc = nbc;
    T = new double * [nbl];
    for (int i(0); i<nbl; i++)
    {
        T[i] = new double [nbc];
    }
    int compteur = 0;
    for (int i(0); i<nbl;i++)
    {
        for (int j(0); j<nbc;j++)
            T[i][j] =  ++compteur;
    }
}


matricX:: matricX (const matricX &A)
{
    nbl = A.nbl;
    nbc = A.nbc;
    T = new double *[nbc];
    for (int i(0); i<nbl; i++)
    {
        T[i] = new double [nbc];

    }
    for (int i(0); i<nbl;i++)
    {
        for (int j(0); j<nbc;j++)
            T[i][j] = A.T[i][j];
    }
}

void matricX :: afficher()
{
    for (int i(0); i<nbl;i++)
    {
        for (int j(0); j<nbc;j++)
        {
            cout << T[i][j]<< "  ";

        }
    cout<<endl;
    }

}

matricX &matricX:: operator = (const matricX &A)
{
    for (int i(0); i<nbl;i++)
    {
        for (int j(0); j<nbc;j++)
            T[i][j] = A.T[i][j];
    }
    return *this;
}

double* matricX :: operator [] (int i) const
{
    return T[i];
}

matricX matricX :: operator + (const matricX &A) const
{
    matricX r(nbl, nbc);
    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<nbc;j++)
        r[i][j] = A[i][j] + T[i][j];
    }
    return r;
}

matricX matricX :: operator - (const matricX &A) const
{
    matricX r(nbl, nbc);
    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<nbc;j++)
        r[i][j] = A[i][j] - T[i][j];
    }
    return r;
}

matricX matricX :: operator * (const matricX &A) const
{
    matricX r(nbl, A.nbc);

    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<A.nbc; j++)
        {
            r[i][j] = 0;
            for (int k(0); k<nbc; k++)
                r[i][j] += T[i][k]* A[k][j];
        }
    }
    return r;
}

matricX matricX :: operator * (double a) const
{
    matricX r(nbl, nbc);
    for (int i(0); i<nbl; i++)
    {
        for(int j(0); j<nbc;j++)
            r[i][j] = a*T[i][j];
    }
    return r;

}

matricX matricX:: operator / (double a) const
{
    matricX r(nbl, nbc);
    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<nbc;j++)
            r[i][j] = T[i][j]* (1/a);
    }
    return r;
}

matricX &matricX:: operator += (const matricX &A)
{
    for (int i(0); i<nbl;i++)
    {
        for (int j(0); j<nbl;j++)
            T[i][j] += A[i][j];
    }
    return *this;
}


matricX &matricX :: operator -= (const matricX &A)
{
    for (int i(0); i<nbl;i++)
    {
        for (int j(0); j<nbc;j++)
            T[i][j] -= A[i][j];
    }
    return *this;
}

matricX &matricX ::operator *= (const matricX &A)
{
    /*
    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<A.nbc; j++)
        {
            for (int k(0); k<nbc; k++)
            T[i][j] += T[i][k]*A[k][j];
        }
    }
    return *this;
    */


    *this = *this *A;
    return *this;
}
matricX &matricX :: operator *= (double a)

matricX ::matricX ~matricX()
{
    for (int i(0); i<nbl; i++)
        delete [] T[i];
    delete [] T;
}
