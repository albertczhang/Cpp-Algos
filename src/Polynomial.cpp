//
// Created by albertczhang on 7/21/19.
//

#include <iostream>
#include <Polynomial.h>
#include <Matrix.h>

vector<string> supers = {"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"};

string getSuper(int i) {
    string s = to_string(i);
    string super = "";
    for (int index = 0; index < s.size(); index++) {
        super += supers[stoi(string(1, s[index]))];
    }
    return super;
}

template<class T>
Polynomial<T>::Polynomial(char variable) {
    deg = 0;
    vector<T> v;
    coeffs = v;
    var = variable;
}

template<class T>
Polynomial<T>::Polynomial(vector<T> coefficients, char variable) {
    deg = coefficients.size() - 1;
    coeffs = coefficients;
    var = variable;
}

template<class T>
void realShow(Polynomial<T> p) {
    cout << p.coeffs[0];

    for (int i = 1; i <= p.deg; i++) {
        double a = p.coeffs[i];
        if (a == 1) {
            cout << " + " << p.var << getSuper(i);
        } else if (a == -1) {
            cout << " - " << p.var << getSuper(i);
        } else if (a < 0) {
            string a_str = to_string(a);
            cout << " " << a_str[0] << " " << -a << p.var << getSuper(i);
        } else if (a == 0) {
            continue;
        } else {
            cout << " + " << a << p.var << getSuper(i);
        }
    }
}

template<>
void Polynomial<int>::show() {
    realShow(*this);
}

template<>
void Polynomial<float>::show() {
    realShow(*this);
}

template<>
void Polynomial<double>::show() {
    realShow(*this);
}

template<class T>
void complexShow(Polynomial<T> p) {

    cout << "(" << p.coeffs[0] << ")";

    for (int i = 1; i <= p.deg; i++) {
        T a = p.coeffs[i];
        if (a == 1) {
            cout << " + " << p.var << getSuper(i);
        } else if (a == -1) {
            cout << " - " << p.var << getSuper(i);
        } else if (a == 0) {
            continue;
        } else {
            cout << " + (" << a << ")" << p.var << getSuper(i);
        }
    }
}

template<>
void Polynomial<iint>::show() {
    complexShow(*this);
}

template<>
void Polynomial<ifloat>::show() {
    complexShow(*this);
}

template<>
void Polynomial<idouble>::show() {
    complexShow(*this);
}


template
class Polynomial<int>;

template
class Polynomial<float>;

template
class Polynomial<double>;

template
class Polynomial<iint>;

template
class Polynomial<ifloat>;

template
class Polynomial<idouble>;