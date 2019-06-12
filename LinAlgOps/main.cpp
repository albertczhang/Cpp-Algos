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

    Matrix<iint> m1(5, 5);
    for (int i = 1; i <= m1.m; i++) {
        for (int j = 1; j <= m1.n; j++) {
            iint z(i, j);
            m1.set(i, j, z);
        }
    }
    Matrix<iint> m2(5, 5);
    for (int i = 1; i <= m2.m; i++) {
        for (int j = 1; j <= m2.n; j++) {
            iint z(i, j);
            m2.set(i, j, z);
        }
    }
    cout << setprecision(3);
    cout << (m1 != m2) << endl;
    m1.show();
    iint x(3);
    m2 = x * m1;
    m2.show();
    int a = 3;
    double d = 2.5;
    double d2 = a * d;
    cout << d2;


    return 0;
}




