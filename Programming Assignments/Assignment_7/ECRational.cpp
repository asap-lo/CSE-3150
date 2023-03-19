//
//  ECRational.cpp
//  
//
//  Created by JACK LONBAROD

#include "ECRational.h"

template <class T>
ECRational<T>::ECRational(const T &numeratorIn, const T &denominatorIn)
{
    numerator = numeratorIn;
    denominator = denominatorIn;
}

template <class T>
ECRational<T>::ECRational(const ECRational &rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;
}

template <class T>
ECRational<T> &ECRational<T>::operator=(const ECRational &rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    return *this;
}

template <class T>
ECRational<T> ECRational<T>::operator+(const ECRational &rhs) const
{
    T num = numerator * rhs.denominator + rhs.numerator * denominator;
    T den = denominator * rhs.denominator;
    ECRational<T> r(num, den);
    return r;
}

template <class T>
ECRational<T> ECRational<T>::operator-(const ECRational &rhs) const
{
    T num = numerator * rhs.denominator - rhs.numerator * denominator;
    T den = denominator * rhs.denominator;
    ECRational<T> r(num, den);
    return r;
}

template <class T>
ECRational<T> ECRational<T>::operator*(const ECRational &rhs) const
{
    T num = numerator * rhs.numerator;
    T den = denominator * rhs.denominator;
    ECRational<T> r(num, den);
    return r;
}

template <class T>
ECRational<T> ECRational<T>::operator/(const ECRational &rhs) const
{
    T num = numerator * rhs.denominator;
    T den = denominator * rhs.numerator;
    ECRational<T> r(num, den);
    return r;
}

template <class T>
const T &ECRational<T>::GetNumerator() const
{
    return numerator;
}

template <class T>
const T &ECRational<T>::GetDenominator() const
{
    return denominator;
}

