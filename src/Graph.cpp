//
// Created by albertczhang on 7/6/19.
//

#include <iostream>
#include "Graph.h"

vector<int> initVec(int size) {
    vector<int> v;
    for (int i = 0; i < size; i++) {
        v.push_back(0);
    }
    return v;
}


/****************************************************
 ***************** ADJACENCY MATRIX *****************
 ****************************************************/

AdjMatrix::AdjMatrix(int V) {
    (*this).V = V;
    for (int i = 0; i < V; i++) {
        vector<int> row = initVec(V);
        (*this).graph.push_back(row);
    }
}

void AdjMatrix::connect(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = 1;
    (*this).graph[j][i] = 1;
}

void AdjMatrix::disconnect(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = 0;
    (*this).graph[j][i] = 0;
}

bool AdjMatrix::isConnected(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    return ((*this).graph[i][j] == 1) && ((*this).graph[j][i] == 1);
}

vector<int> AdjMatrix::neighbors(int i) {
    if (i >= V) {
        cout << "index out of bounds, exiting..." << endl;
        exit(0);
    }
    vector<int> adj;
    for (int j = 0; j < (*this).V; j++) {
        if ((*this).graph[i][j])
            adj.push_back(j);
    }
    return adj;
}

void AdjMatrix::direct(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = 1;
}

bool AdjMatrix::isDirected(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    return ((*this).graph[i][j] == 1);
}

void AdjMatrix::addNode() {
    (*this).V++;
    int newSize = (*this).V;
    for (int i = 0; i < newSize - 1; i++) {
        (*this).graph[i].push_back(0);
    }
    (*this).graph.push_back(initVec(newSize));
}

void AdjMatrix::show() {
    int V = (*this).V;
    int w = 3;
    for (int n = 0; n < w; n++)
        cout << " ";
    cout << setw(w) << setfill(' ') << "│";
    for (int i = 0; i < V; i++) {
        cout << setw(w) << i;
    }
    cout << endl;
    cout << "─────";
    for (int i = 0; i < V; i++) {
        for (int n = 0; n < w; n++) {
            cout << "─";
        }
    }
    cout << endl;
    for (int i = 0; i < V; i++) {
        cout << setw(w) << setfill(' ') << i << setfill(' ') << setw(w) << "│";
        for (int j = 0; j < V; j++) {
            cout << setw(w) << (*this).graph[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


/**************************************************
 ***************** ADJACENCY LIST *****************
 **************************************************/


AdjList::AdjList(int V) {
    (*this).V = V;
    for (int i = 0; i < V; i++) {
        vector<int> row;
        (*this).graph.push_back(row);
    }
}

void AdjList::connect(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i].push_back(j);
    (*this).graph[j].push_back(i);
}

/* TODO: everything below this point */

void AdjList::disconnect(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = 0;
    (*this).graph[j][i] = 0;
}

bool AdjList::isConnected(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    return ((*this).graph[i][j] == 1) && ((*this).graph[j][i] == 1);
}

vector<int> AdjList::neighbors(int i) {
    if (i >= V) {
        cout << "index out of bounds, exiting..." << endl;
        exit(0);
    }
    vector<int> adj;
    for (int j = 0; j < (*this).V; j++) {
        if ((*this).graph[i][j])
            adj.push_back(j);
    }
    return adj;
}

void AdjList::direct(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    (*this).graph[i][j] = 1;
}

bool AdjList::isDirected(int i, int j) {
    int V = (*this).V;
    if (i >= V || j >= V) {
        cout << "indices out of bounds, exiting..." << endl;
        exit(0);
    }
    return ((*this).graph[i][j] == 1);
}

void AdjList::addNode() {
    (*this).V++;
    int newSize = (*this).V;
    for (int i = 0; i < newSize - 1; i++) {
        (*this).graph[i].push_back(0);
    }
    (*this).graph.push_back(initVec(newSize));
}