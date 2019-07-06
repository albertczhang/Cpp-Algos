//
// Created by albertczhang on 7/6/19.
//

#include <iostream>
#include "Graph.h"

vector<double> initVec(int size) {
    vector<double> v;
    for (int i = 0; i < size; i++) {
        v.push_back(NAN);
    }
    return v;
}


/****************************************************
 ***************** ADJACENCY MATRIX *****************
 ****************************************************/

AdjMatrix::AdjMatrix() {
    (*this).V = 0;
    (*this).w = 3;
}

AdjMatrix::AdjMatrix(int V) {
    (*this).V = V;
    (*this).w = 3;
    for (int i = 0; i < V; i++) {
        vector<double> row = initVec(V);
        (*this).graph.push_back(row);
    }
}

void AdjMatrix::connect(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = 1;
    (*this).graph[j][i] = 1;
}

void AdjMatrix::connect(int i, int j, double w) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = w;
    (*this).graph[j][i] = w;
}

void AdjMatrix::disconnect(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = NAN;
    (*this).graph[j][i] = NAN;
}

bool AdjMatrix::isConnected(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    double e1 = (*this).graph[i][j];
    double e2 = (*this).graph[j][i];
    return (e1 == e1 && e2 == e2);
}

vector<int> AdjMatrix::neighbors(int i) {
    i--;
    if (i >= V || i < 0) {
        cout << "index out of bounds, exiting..." << endl;
        exit(0);
    }
    vector<int> adj;
    for (int j = 0; j < (*this).V; j++) {
        if ((*this).graph[i][j] == (*this).graph[i][j])
            adj.push_back(j + 1);
    }
    return adj;
}

void AdjMatrix::direct(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = 1;
}

void AdjMatrix::direct(int i, int j, double w) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = w;
}

bool AdjMatrix::isDirected(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    double e = (*this).graph[i][j];
    return (e == e);
}

double AdjMatrix::weight(int i, int j) {
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    return (*this).graph[i][j];
}

void AdjMatrix::addNode() {
    (*this).V++;
    int newSize = (*this).V;
    for (int i = 0; i < newSize - 1; i++) {
        (*this).graph[i].push_back(NAN);
    }
    (*this).graph.push_back(initVec(newSize));
}

void AdjMatrix::show() {
    int V = (*this).V;
    for (int n = 0; n < w; n++)
        cout << " ";
    cout << std::setw((*this).w) << setfill(' ') << "│";
    for (int i = 0; i < V; i++) {
        cout << std::setw((*this).w) << i + 1;
    }
    cout << endl;
    for (int i = 0; i < w; i++) {
        cout << "──";
    }
    for (int i = 0; i < V; i++) {
        for (int n = 0; n < w; n++) {
            cout << "─";
        }
    }
    cout << endl;
    for (int i = 0; i < V; i++) {
        cout << std::setw((*this).w) << setfill(' ') << i + 1 << setfill(' ') << std::setw((*this).w) << "│";
        for (int j = 0; j < V; j++) {
            double x = (*this).graph[i][j];
            if (x == x)
                cout << std::setw((*this).w) << (*this).graph[i][j];
            else
                cout << std::setw((*this).w) << "~";
        }
        cout << endl;
    }
    cout << endl;
}


/**************************************************
 ***************** ADJACENCY LIST *****************
 **************************************************/

AdjList::AdjList() {
    (*this).V = 0;
    (*this).w = 3;
}

AdjList::AdjList(int V) {
    (*this).V = V;
    (*this).w = 3;
    for (int i = 0; i < V; i++) {
        vector<double> row;
        (*this).graph.push_back(row);
    }
}

void AdjList::connect(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i].push_back(j + 1);
    (*this).graph[j].push_back(i + 1);
}


void AdjList::disconnect(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }

    for (int k = 0; k < (*this).graph[i].size(); k++) {
        if ((*this).graph[i][k] == j + 1) {
            (*this).graph[i].erase((*this).graph[i].begin() + k);
            k--;
        }
    }
    for (int k = 0; k < (*this).graph[j].size(); k++) {
        if ((*this).graph[j][k] == i + 1) {
            (*this).graph[j].erase((*this).graph[j].begin() + k);
            k--;
        }
    }
}

bool AdjList::isConnected(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    bool flag1 = false;
    bool flag2 = false;
    for (int k = 0; k < (*this).graph[i].size(); k++) {
        if ((*this).graph[i][k] == j + 1) {
            flag1 = true;
            break;
        }
    }
    for (int k = 0; k < (*this).graph[j].size(); k++) {
        if ((*this).graph[j][k] == i + 1) {
            flag2 = true;
            break;
        }
    }
    return flag1 && flag2;
}

vector<int> AdjList::neighbors(int i) {
    i--;
    if (i >= V || i < 0) {
        cout << "index out of bounds, exiting..." << endl;
        exit(0);
    }
    vector<int> adj;
    for (int k = 0; k < (*this).graph[i].size(); k++) {
        adj.push_back((*this).graph[i][k]);
    }
    return adj;
}

void AdjList::direct(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i].push_back(j + 1);
}

bool AdjList::isDirected(int i, int j) {
    int V = (*this).V;
    i--;
    j--;
    if (i >= V || j >= V || i < 0 || j < 0) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    bool flag = false;
    for (int k = 0; k < (*this).graph[i].size(); k++) {
        if ((*this).graph[i][k] == j + 1) {
            flag = true;
            break;
        }
    }
    return flag;
}

void AdjList::addNode() {
    (*this).V++;
    vector<double> newrow;
    (*this).graph.push_back(newrow);
}

void AdjList::show() {
    int V = (*this).V;
    cout << endl;
    for (int i = 0; i < V; i++) {
        cout << std::setw((*this).w) << setfill(' ') << i + 1 << setfill(' ') << std::setw((*this).w) << "│";
        bool flag = true;
        for (int j = 0; j < (*this).graph[i].size(); j++) {
            if (j < (*this).graph[i].size() - 1)
                cout << (*this).graph[i][j] << ", ";
            else {
                cout << (*this).graph[i][j] << endl;
                flag = false;
            }
        }
        if (flag)
            cout << endl;
    }
    cout << endl;
}