#include <iostream>
#include "Matrix.h"
#include <math.h>
#include <iomanip>

using namespace std;


int main() {

//    cout << setprecision(3);
//    Matrix<int> M;

//    idouble zarr[4];
//    zarr[0] = idouble(3, 4);
//    zarr[1] = idouble(4, 5);
//    zarr[2] = idouble(5, 6);
//    zarr[3] = idouble(6, 7);
//    for (int i = 0; i < 4; i++) {
//        zarr[i].conj();
//    }
//    for (int i = 0; i < 4; i++) {
//        cout << zarr[i] << endl;
//    }

    Matrix<iint> m1 (5, 5);
    for (int i = 0; i < m1.m; i++) {
        for (int j = 0; j < m1.n; j++) {
            iint z (i, j);
            if (i == j) {
                m1.set(i, j, 2);
            }
            m1.set(i, j, z);
        }
    }
    Matrix<iint> m2 (5, 5);
    for (int i = 0; i < m2.m; i++) {
        for (int j = 0; j < m2.n; j++) {
            iint z (j, i);
            m2.set(i, j, z);
        }
    }
    cout << setprecision(3);
    m1.show();
    m1.getH().show();
    m2.show(6);
    Matrix<iint> m3 (5, 5);
    m3 = m1 * m2;
    m3.show(6);
    int x = 341;
    double y = 2.34;
    string s = "h";
    float f = 3.45;

    char c = 'h';
    idouble z (3.341, 44525);
    cout << sizeof(f) << endl;
    return 0;
}

