//
// Created by albertczhang on 6/9/19.
//

#ifndef LINALGOPS_MATRIX_H
#define LINALGOPS_MATRIX_H

#include "Complex.h"
#include <vector>

using namespace std;

template<class T>
class Matrix {
private:
    vector<vector<T>> mat;
public:
    int m, n;

    Matrix();

    Matrix(int M, int N);

    void set(int i, int j, T x);

    T get(int i, int j) const;

    void show(int padding=5);

    vector<T> operator[](int i); // CAVEAT : ONLY FOR ACCESS, NOT ASSIGNMENT

    Matrix<T> operator+(const Matrix other);

    Matrix<T> operator-(const Matrix other);

    Matrix<T> operator*(const Matrix other);

    Matrix<T> getT() const;

    Matrix<T> getH() const;

//    Matrix<iint> getIntH() const;

};


#endif //LINALGOPS_MATRIX_H
