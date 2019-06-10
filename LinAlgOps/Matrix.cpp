//
// Created by albertczhang on 6/9/19.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"

template<class T>
vector<T> kNums(int k, T x) {
    vector<T> v;
    for (int i = 0; i < k; i++) {
        v.push_back(x);
    }
    return v;
}

template<class T>
Matrix<T>::Matrix() {
    m = 2, n = 2;
    for (int i = 0; i < 2; i++) {
        vector<T> r = kNums<T>(2, 0);
        mat.push_back(r);
    }
}

template<class T>
Matrix<T>::Matrix(int M, int N) {
    m = M, n = N;
    for (int i = 0; i < m; i++) {
        vector<T> r = kNums<T>(n, 0);
        mat.push_back(r);
    }
}

//int size(double **a) {
//    return sizeof(a) / sizeof(*a);
//}


template<class T>
void Matrix<T>::set(int i, int j, T x) {
    mat[i][j] = (T) x;
}


template<class T>
T Matrix<T>::get(int i, int j) const {
    if (i >= m || j >= n) {
        cout << "Matrix indices out of bounds, exiting...";
        exit(0);
    }
    return mat[i][j];
}


template<class T>
void Matrix<T>::show(int padding) {
    int w = padding;
    cout << "⎡";
    for (int j = 0; j < n - 1; j++) {
        cout << mat[0][j] << setw(w) << setfill(' ');
    }
    cout << mat[0][n - 1] << "⎤\n";
    for (int i = 1; i < m - 1; i++) {
        cout << "⎢";
        for (int j = 0; j < n - 1; j++) {
            cout << mat[i][j] << setw(w) << setfill(' ');
        }
        cout << mat[i][n - 1] << "⎥\n";
    }
    cout << "⎣";
    for (int j = 0; j < n - 1; j++) {
        cout << mat[m - 1][j] << setw(w) << setfill(' ');
    }
    cout << mat[m - 1][n - 1] << "⎦\n";
}


/***************************************************
 **************  OPERATOR OVERLOADING **************
 ***************************************************/
template<class T>
vector<T> Matrix<T>::operator[](int i) {
    if (i >= m) {
        cout << "Array index out of bound, exiting...";
        exit(0);
    }
    return mat[i];
}


template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) {
    if (m != other.m || n != other.n) {
        cout << "Dimensions don't match, exiting...";
        exit(0);
    }
    Matrix<T> result(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result.set(i, j, mat[i][j] + other.get(i, j));
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) {
    if (m != other.m || n != other.n) {
        cout << "Dimensions don't match, exiting...";
        exit(0);
    }
    Matrix<T> result(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result.set(i, j, mat[i][j] - other.get(i, j));
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other) {
    if (n != other.m) {
        cout << "Dimensions don't match, exiting...";
        exit(0);
    }

    /**** NAIVE MATRIX MULTIPLICATION ****/
    Matrix<T> result(m, other.n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < other.n; j++) {
            T dot = 0;
            for (int k = 0; k < n; k++) {
                dot = dot + mat[i][k] * other.get(k, j);
            }
            result.set(i, j, dot);
        }
    }
    return result;
}


/*
 * MATRIX OPERATIONS
 */

template<class T>
Matrix<T> Matrix<T>::getT() const {
    /* RETURNS THE TRANSPOSE */
    Matrix<T> transpose (n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transpose.set(j, i, mat[i][j]);
        }
    }
    return transpose;
}

template<>
Matrix<idouble> Matrix<idouble>::getH() const {
    /* RETURNS THE HERMITIAN TRANSPOSE (ONLY FOR COMPLEX MATRICIES) */
    Matrix<idouble> H (n, m);
    H = (*this).getT();
    for (int i = 0; i < H.m; i++) {
        for (int j = 0; j < H.n; j++) {
            H.set(i, j, H.get(i, j).getConj());
        }
    }
    return H;
}

template<>
Matrix<iint> Matrix<iint>::getH() const {
    /* RETURNS THE HERMITIAN TRANSPOSE (ONLY FOR COMPLEX MATRICIES) */
    Matrix<iint> H (n, m);
    H = (*this).getT();
    for (int i = 0; i < H.m; i++) {
        for (int j = 0; j < H.n; j++) {
            H.set(i, j, H.get(i, j).getConj());
        }
    }
    return H;
}



template
class Matrix<int>;

template
class Matrix<float>;

template
class Matrix<double>;

template
class Matrix<Complex<int>>;

template
class Matrix<Complex<double>>;