//
// Created by albertczhang on 7/21/19.
//

#ifndef MADS_LIBRARY_POLYNOMIAL_H
#define MADS_LIBRARY_POLYNOMIAL_H

#include <vector>

using namespace std;

template<class T>
class Polynomial {
public:
    int deg;
    char var;
    vector<T> coeffs;

    Polynomial(char variable = 'x');

    Polynomial(vector<T> coefficients, char variable = 'x');

    void show();

    T eval(T x);

    T operator()(T x);

    T operator[](int index);

    Polynomial<T> operator+(Polynomial<T> p);

    Polynomial<T> operator*(Polynomial<T> p);

    Polynomial<T> operator-(Polynomial<T> p);

    void scale(T c);

};

template<class T>
std::ostream &operator<<(std::ostream &os, Polynomial<T> p) {
    p.show();
    return os;
}

/****************************************
 ************ Interpolation *************
 ****************************************/

template<class T>
Polynomial<T> L_interpolate(T (*f)(T x), vector<T> points) {
    /* NOTE: points must be a list of distinct values */
    int L_deg = points.size() - 1;
    vector<T> zeroes(points.size());
    Polynomial<T> L(zeroes);
    for (T xi: points) {
        vector<T> one = {1};
        Polynomial<T> Lp(one);
        T denom(1);
        for (T xj: points) {
            if (xi != xj) {
                vector<T> factor = {T(-1) * xj, 1};
                Lp = Lp * Polynomial<T>(factor);
                denom = denom * (xi - xj);
            }
        }
        Lp.scale(T(f(xi)) / denom);
        L = L + Lp;
    }
    return L;
}

#endif //MADS_LIBRARY_POLYNOMIAL_H
