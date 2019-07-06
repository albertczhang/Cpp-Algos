//
// Declarations for Matrix Class
//

#ifndef MADS_LIBRARY_MATRIX_H
#define MADS_LIBRARY_MATRIX_H

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

    void show(int padding = 5, double maxError = 1.0e-10);

    vector<T> operator[](int i); // CAVEAT : ONLY FOR ACCESS, NOT ASSIGNMENT

    Matrix<T> operator+(const Matrix other);

    Matrix<T> operator-(const Matrix other);

    Matrix<T> operator*(const Matrix other);

    bool operator==(const Matrix other);

    bool operator!=(const Matrix other);

    Matrix<T> getT() const;

    Matrix<T> getH() const;

    void rowMinus(int i1, int i2, T factor); // SUBTRACT FACTOR * I1 FROM I2

    void rowSwap(int i1, int i2);

    void rowMult(int i, T factor);

    void rowDiv(int i, T factor);

    T det(int algo = 0) const;

    void gaussElim();

    void gaussElim(int col);

    Matrix<T> inverse();


};

template<class T, int M, int N>
Matrix<T> makeMatrix(T entries[M][N]);

template<class T, int M, int N>
Matrix<T> makeMatrix(T entries[M][N]) {
    Matrix<T> result (M, N);
    for (int i = 1; i <= result.m; i++) {
        for (int j = 1; j <= result.n; j++) {
            result.set(i, j, entries[i - 1][j - 1]);
        }
    }
    return result;
}

template<class T>
Matrix<T> operator*(T k, Matrix<T> other) {
    Matrix<T> result(other.m, other.n);
    for (int i = 0; i < other.m; i++) {
        for (int j = 0; j < other.n; j++) {
            result.set(i + 1, j + 1, k * other.get(i + 1, j + 1));
        }
    }
    return result;
}

template<class T>
Matrix<T> operator/(Matrix<T> other, T k) {
    Matrix<T> result(other.m, other.n);
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

#endif //MADS_LIBRARY_MATRIX_H
