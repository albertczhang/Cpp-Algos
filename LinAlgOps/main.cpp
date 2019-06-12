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

    int n = 6;
    Matrix<double> m1(n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            m1.set(i, j, i);
            m1.set(j, i, -i);
        }
    }
    cout << setprecision(2);
    m1.show(6);
    cout << m1.det(1) << endl;
    m1.show();


    return 0;
}




