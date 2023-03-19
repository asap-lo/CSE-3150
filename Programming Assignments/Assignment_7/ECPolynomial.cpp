//
//  ECPolynomial.cpp
//  
//
//  Created by JACK LOMBARDO
//

#include "ECPolynomial.h"
#include <iostream>
using namespace std;

ECPolynomial::ECPolynomial(const std::vector<double> &listCoeffsIn)
{
    listCoeffs = listCoeffsIn;
}

//default constructor
ECPolynomial::ECPolynomial()
{
    listCoeffs.push_back(0.0);
}

ECPolynomial::ECPolynomial(const ECPolynomial &rhs)
{
    listCoeffs = rhs.listCoeffs;
    while(listCoeffs.back() == 0 && listCoeffs.size() > 1)
    {
        listCoeffs.pop_back();
    }
}

ECPolynomial ECPolynomial::operator+(const ECPolynomial &rhs) const
{
    //add two polynomials together
    vector<double> result;
    int i = 0;
    int j = 0;
    while (i < listCoeffs.size() && j < rhs.listCoeffs.size())
    {
        result.push_back(listCoeffs[i] + rhs.listCoeffs[j]);
        i++;
        j++;
    }
    while (i < listCoeffs.size())
    {
        result.push_back(listCoeffs[i]);
        i++;
    }
    while (j < rhs.listCoeffs.size())
    {
        result.push_back(rhs.listCoeffs[j]);
        j++;
    }
    while (result.back() == 0 && result.size() > 1)
    {
        result.pop_back();
    }
    ECPolynomial r(result);
    return r;

    
    
}

ECPolynomial ECPolynomial::operator*(const ECPolynomial &rhs) const
{
    vector<double> result;
    for (int i = 0; i < listCoeffs.size() + rhs.listCoeffs.size() - 1; i++)
    {
        result.push_back(0);
    }
    for (int i = 0; i < listCoeffs.size(); i++)
    {
        for (int j = 0; j < rhs.listCoeffs.size(); j++)
        {
            result[i + j] += listCoeffs[i] * rhs.listCoeffs[j];
        }
    }
    while (result.back() == 0 && result.size() > 1)
    {
        result.pop_back();
    }
    return result;
}

ECPolynomial ECPolynomial::operator/(const ECPolynomial &rhs) const
{
    vector<double> result;
    vector<double> remainder;
    int i = 0;
    int j = 0;
    while (i < listCoeffs.size() && j < rhs.listCoeffs.size())
    {
        result.push_back(listCoeffs[i] / rhs.listCoeffs[j]);
        i++;
        j++;
    }
    while (i < listCoeffs.size())
    {
        remainder.push_back(listCoeffs[i]);
        i++;
    }
    while (j < rhs.listCoeffs.size())
    {
        remainder.push_back(rhs.listCoeffs[j]);
        j++;
    }
    while (remainder.back() == 0 && remainder.size() > 1)
    {
        remainder.pop_back();
    }
    return result;
}

ECPolynomial ECPolynomial::operator%(const ECPolynomial &rhs) const
{
    vector<double> result;
    vector<double> remainder;
    int i = 0;
    int j = 0;
    while (i < listCoeffs.size() && j < rhs.listCoeffs.size())
    {
        result.push_back(listCoeffs[i] / rhs.listCoeffs[j]);
        i++;
        j++;
    }
    while (i < listCoeffs.size())
    {
        remainder.push_back(listCoeffs[i]);
        i++;
    }
    while (j < rhs.listCoeffs.size())
    {
        remainder.push_back(rhs.listCoeffs[j]);
        j++;
    }
    while (remainder.back() == 0 && remainder.size() > 1)
    {
        remainder.pop_back();
    }
    return remainder;
}

int ECPolynomial::GetDegree() const
{
    //ignore trailing zeros
    if(listCoeffs.size() == 0)
    {
        return 0;
    }
    int i = listCoeffs.size() - 1;
    while (abs(listCoeffs[i]) <= 1e-100 && i > 0)
    {
        i--;
    }
    return i;
}

double ECPolynomial::GetCoeff(int i) const
{
    if(i < 0 || i >= listCoeffs.size() || listCoeffs.size() == 0)
    {
        return 0;
    }
    
    return listCoeffs[i];
}

void ECPolynomial::Dump() const
{
    cout << "Deg: " << GetDegree() << "  ";
    for (int i = 0; i < listCoeffs.size(); i++)
    {
        cout << listCoeffs[i] << " ";
    }
    cout << endl;
}

ECPolynomial ECPolynomial::Scale(double factor)
{
    for (int i = 0; i < listCoeffs.size(); i++)
    {
        listCoeffs[i] *= factor;
    }
    return listCoeffs;
}

void ECPolynomial::SetCoeffAt(int i, double val) 
{
    if (i < 0)
    {
        return;
    }
    if (i >= listCoeffs.size())
    {
        listCoeffs.resize(i + 1);
    }
    listCoeffs[i] = val;
}

//constructor for input of a single int
ECPolynomial :: ECPolynomial(int d)
{
    for (int i = 0; i < d; i++)
    {
        listCoeffs.push_back(0);
    }
}