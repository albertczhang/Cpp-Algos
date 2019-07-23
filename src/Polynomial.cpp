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
    if (i == 1)
        return super;
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
    double a = p.coeffs[p.deg];
    if (a == 1)
        cout << p.var << getSuper(p.deg);
    else if (a == -1)
        cout << "-" << p.var << getSuper(p.deg);
    else
        cout << p.coeffs[p.deg] << p.var << getSuper(p.deg);

    for (int i = p.deg - 1; i >= 1; i--) {
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
    T a2 = p.coeffs[0];
    if (a2 > 0)
        cout << " + " << a2;
    else if (a2 < 0)
        cout << " - " << abs(a2);
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
    T a = p.coeffs[p.deg];
    if (a == 1) {
        cout << p.var << getSuper(p.deg);
    } else if (a == -1) {
        cout << "-" << p.var << getSuper(p.deg);
    } else {
        cout << "(" << a << ")" << p.var << getSuper(p.deg);
    }

    for (int i = p.deg - 1; i >= 1; i--) {
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
    cout << " + (" << p.coeffs[0] << ")";

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

template<class T>
T Polynomial<T>::eval(T x) {
    T result(0);
    for (int i = 0; i <= deg; i++) {
        result = result + coeffs[i] * pow(x, i);
    }
    return result;
}

/***********************************************
 ************ Operator Overloading *************
 ***********************************************/

template<class T>
T Polynomial<T>::operator()(T x) {
    return (*this).eval(x);
}

template<class T>
T Polynomial<T>::operator[](int index) {
    if (index > (*this).deg) {
        return 0;
    }
    return (*this).coeffs[index];
}

template<class T>
Polynomial<T> Polynomial<T>::operator+(Polynomial<T> p) {
    if (p.var != (*this).var) {
        cout << "variables don't match, currently no multi-var support..." << endl;
        exit(0);
    }

    int result_deg = max((*this).deg, p.deg);
    vector<T> result_coeffs(result_deg + 1);
    Polynomial result(result_coeffs);
    for (int i = 0; i <= min((*this).deg, p.deg); i++) {
        result.coeffs[i] = (*this).coeffs[i] + p.coeffs[i];
    }

    if ((*this).deg > p.deg) {
        for (int i = min((*this).deg, p.deg) + 1; i <= result_deg; i++) {
            result.coeffs[i] = (*this).coeffs[i];
        }
    } else {
        for (int i = min((*this).deg, p.deg) + 1; i <= result_deg; i++) {
            result.coeffs[i] = p.coeffs[i];
        }
    }
    return result;
}

template<class T>
Polynomial<T> Polynomial<T>::operator*(Polynomial<T> p) {
    if (p.var != (*this).var) {
        cout << "variables don't match, currently no multi-var support..." << endl;
        exit(0);
    }

    int result_deg = (*this).deg + p.deg;
    vector<T> result_coeffs(result_deg + 1);

    Polynomial<T> result(result_coeffs);

    for (int i = 0; i <= result_deg; i++) {
        T coeff = 0;
        for (int k = 0; k <= i; k++) {

            coeff = coeff + (*this)[k] * p[i - k];

        }
        result.coeffs[i] = coeff;
    }

    return result;
}

template<class T>
Polynomial<T> Polynomial<T>::operator-(Polynomial<T> p) {
    if (p.var != (*this).var) {
        cout << "variables don't match, currently no multi-var support..." << endl;
        exit(0);
    }

    int result_deg = max((*this).deg, p.deg);
    vector<T> result_coeffs(result_deg + 1);
    Polynomial result(result_coeffs);
    for (int i = 0; i <= min((*this).deg, p.deg); i++) {
        result.coeffs[i] = (*this).coeffs[i] - p.coeffs[i];
    }

    if ((*this).deg > p.deg) {
        for (int i = min((*this).deg, p.deg) + 1; i <= result_deg; i++) {
            result.coeffs[i] = (*this).coeffs[i];
        }
    } else {
        for (int i = min((*this).deg, p.deg) + 1; i <= result_deg; i++) {
            result.coeffs[i] = T(-1) * p.coeffs[i];
        }
    }
    return result;
}

template<class T>
void Polynomial<T>::scale(T c) {
    for (int i = 0; i <= (*this).deg; i++) {
        (*this).coeffs[i] = c * (*this).coeffs[i];
    }
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