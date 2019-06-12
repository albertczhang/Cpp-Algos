//
// Created by albertczhang on 6/9/19.
//


#include "Complex.h"
#include <ostream>
#include <math.h>

using namespace std;

template<class T>
Complex<T>::Complex() {
    a = 0;
    b = 0;
    r2 = 0;
    r = 0.0;
}

template<class T>
Complex<T>::Complex(T A) {
    a = A;
    b = 0;
    r2 = a * a;
    r = (double) a;
}

template<class T>
Complex<T>::Complex(T A, T B) {
    a = A;
    b = B;
    r2 = a * a + b * b;
    r = sqrt(r2);
}

template<class T>
Complex<T> Complex<T>::operator+(const Complex<T> z) {
    Complex<T> result(a + z.a, b + z.b);
    return result;
}

template<class T>
Complex<T> Complex<T>::operator-(const Complex<T> z) {
    Complex<T> result(a - z.a, b - z.b);
    return result;
}

template<class T>
Complex<T> Complex<T>::operator*(const Complex<T> z) {
    Complex<T> result(a * z.a - b * z.b, a * z.b + b * z.a);
    return result;
}

template<class T>
Complex<T> Complex<T>::operator/(const Complex<T> z) {
    /* CAVEAT : SHOULD ONLY BE USED WITH TYPE DOUBLE OR FLOAT */
    Complex<T> result((a * z.a + b * z.b) / z.r2, (-1 * a * z.b + b * z.a) / z.r2);
    return result;
}

template<class T>
bool Complex<T>::operator==(const Complex<T> z) {
    return ((a == z.a) && (b == z.b));
}

template<class T>
bool Complex<T>::operator!=(const Complex<T> z) {
    return !((a == z.a) && (b == z.b));
}


template<class T>
void Complex<T>::set(T A, T B) {
    Complex<T> z(A, B);
    *this = z;
}

template<class T>
void Complex<T>::conj() {
    b *= -1;
}

template<class T>
Complex<T> Complex<T>::getConj() const {
    Complex<T> z (a, -1 * b);
    return z;
}

template
class Complex<int>;

template
class Complex<float>;

template
class Complex<double>;



