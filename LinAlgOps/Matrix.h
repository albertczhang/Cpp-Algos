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

    bool operator==(const Matrix other);

    bool operator!=(const Matrix other);

    Matrix<T> getT() const;

    Matrix<T> getH() const;

    T det(int algo=0) const;

};

template<class T>
Matrix<T> operator*(T k, Matrix<T> other) {
    Matrix<T> result (other.m, other.n);
    for (int i = 0; i < other.m; i++) {
        for (int j = 0; j < other.n; j++) {
            result.set(i + 1, j + 1, k * other.get(i + 1, j + 1));
        }
    }
    return result;
}

template<class T>
Matrix<T> operator/(Matrix<T> other, T k) {
    Matrix<T> result (other.m, other.n);
    for (int i = 0; i < other.m; i++) {
        for (int j = 0; j < other.n; j++) {
            result.set(i + 1, j + 1, other.get(i + 1, j + 1) / k);
        }
    }
    return result;
}


//Matrix<int> operator*(int k, Matrix<int> other) {
//    Matrix<int> result (other.m, other.n);
//    for (int i = 0; i < other.m; i++) {
//        for (int j = 0; j < other.n; j++) {
//            result.set(i, j, k * other.get(i, j));
//        }
//    }
//    return result;
//}
//
//Matrix<double> operator*(double k, Matrix<double> other) {
//    Matrix<double> result (other.m, other.n);
//    for (int i = 0; i < other.m; i++) {
//        for (int j = 0; j < other.n; j++) {
//            result.set(i, j, k * other.get(i, j));
//        }
//    }
//    return result;
//}
//
//Matrix<float> operator*(float k, Matrix<float> other) {
//    Matrix<float> result (other.m, other.n);
//    for (int i = 0; i < other.m; i++) {
//        for (int j = 0; j < other.n; j++) {
//            result.set(i, j, k * other.get(i, j));
//        }
//    }
//    return result;
//}
//
//Matrix<iint> operator*(iint k, Matrix<iint> other) {
//    Matrix<iint> result (other.m, other.n);
//    for (int i = 0; i < other.m; i++) {
//        for (int j = 0; j < other.n; j++) {
//            result.set(i, j, k * other.get(i, j));
//        }
//    }
//    return result;
//}

//Matrix<idouble> operator*(idouble k, Matrix<idouble> other) {
//    Matrix<idouble> result (other.m, other.n);
//    for (int i = 0; i < other.m; i++) {
//        for (int j = 0; j < other.n; j++) {
//            result.set(i, j, k * other.get(i, j));
//        }
//    }
//    return result;
//}
//
//Matrix<ifloat> operator*(ifloat k, Matrix<ifloat> other) {
//    Matrix<ifloat> result (other.m, other.n);
//    for (int i = 0; i < other.m; i++) {
//        for (int j = 0; j < other.n; j++) {
//            result.set(i, j, k * other.get(i, j));
//        }
//    }
//    return result;
//}

#endif //LINALGOPS_MATRIX_H
