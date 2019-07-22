//
// Created by albertczhang on 7/21/19.
//

#ifndef MADS_LIBRARY_POLYNOMIAL_H
#define MADS_LIBRARY_POLYNOMIAL_H

#include <vector>

using namespace std;

template <class T>
class Polynomial {
public:
    int deg;
    char var;
    vector<T> coeffs;

    Polynomial(char variable='x');

    Polynomial(vector<T> coefficients, char variable='x');

    void show();
};


#endif //MADS_LIBRARY_POLYNOMIAL_H
