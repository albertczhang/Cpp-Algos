#include <iostream>
#include "Matrix.h"
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double randDouble(double min, double max) {
    return (max - min) * ((double) rand() / (double) RAND_MAX) + min;
}

void testDet(int trials);

int main() {

    /* How to INITIALIZE a matrix:
    double m2[4][4] = {{1, 2, 3, 4},
                       {3, 1, 2, 5},
                       {5, 1, 6, 7},
                       {2, 5, 3, 6}};
    Matrix<double> m1 (4, 4);
    m1 = makeMatrix<double, 4, 4>(m2);

    m1.show(); */


    cout << setprecision(2);

    double arr[4][4] = {{1, 4, 2, 5},
                      {4, 2, 6, 4},
                      {4, 7, 1, 3},
                      {4, 3, 2, 2}};
    Matrix<double> m (4, 4);
    m = makeMatrix<double, 4, 4>(arr);

    m.show();
    m.gaussElim();
    m.show(6);
    cout << (m.get(2, 1) == 0) << endl;



    return 0;
}


void testDet(int trials) {
    srand(time(NULL));

    cout << setprecision(2);
    int NUM_TRIALS = trials;
    int good_count = 0;
    int rough_count = 0;
    int bad_count = 0;
    double error = 0;
    for (int trials = 0; trials < NUM_TRIALS; trials++) {

        int n = rand() % 7 + 2;
        Matrix<double> m1(n, n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                m1.set(i, j, randDouble(-10, 10));

            }
        }
        m1.show(6);
        int d1 = m1.det(1);
        int d2 = m1.det();
        if (d1 == d2) {
            good_count++;
            cout << "Determinants match: " <<
                 d1 << " = " << d2 << endl << endl;
        }
        else if (d1 - d2 > -2 && d1 - d2 < 2) {
            rough_count++;
            error += abs((d1 - d2) / d1 * 100);
            cout << "Determinants are off by 1: " <<
                 d1 << " = " << d2 << endl << endl;
            cout << "error: " << error << endl;
        } else {
            bad_count++;
            error += abs((d1 - d2) / d1 * 100);
            cout << "Determinants don't match: " <<
                 d1 << " != " << d2 << endl << endl;
            cout << "error: " << error << endl;
        }
    }
    error /= NUM_TRIALS;
    cout << "Matching: " << good_count << endl;
    cout << "Off by one: " << rough_count << endl;
    cout << "Not Matching: " << bad_count << endl;
    cout << "Mean Error: " << error << "%" << endl;
}


