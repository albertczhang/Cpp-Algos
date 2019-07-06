//
// Created by albertczhang on 7/6/19.
//

#ifndef MADS_LIBRARY_GRAPH_H
#define MADS_LIBRARY_GRAPH_H

#include <vector>
#include "Matrix.h"

using namespace std;

class Graph {
protected:
    vector<vector<double>> graph;
    int w;
public:
    int V;

    virtual void connect(int i, int j) = 0;

    virtual void disconnect(int i, int j) = 0;

    virtual bool isConnected(int i, int j) = 0;

    virtual vector<int> neighbors(int i) = 0;

    virtual void direct(int i, int j) = 0;

    virtual bool isDirected(int i, int j) = 0;

    virtual void addNode() = 0;

    virtual void show() = 0;

    void setw(int w) {
        (*this).w = w;
    };

};


class AdjMatrix : public Graph {
public:
    AdjMatrix();

    explicit AdjMatrix(int V);

    void connect(int i, int j) override;

    void connect(int i, int j, double w);

    void disconnect(int i, int j) override;

    bool isConnected(int i, int j) override;

    vector<int> neighbors(int i) override;

    void direct(int i, int j) override;

    void direct(int i, int j, double w);

    bool isDirected(int i, int j) override;

    double weight(int i, int j);

    void addNode() override;

    void show() override;
};

class AdjList : public Graph {
public:
    AdjList();

    explicit AdjList(int V);

    void connect(int i, int j) override;

    void disconnect(int i, int j) override;

    bool isConnected(int i, int j) override;

    vector<int> neighbors(int i) override;

    void direct(int i, int j) override;

    bool isDirected(int i, int j) override;

    void addNode() override;

    void show() override;
};

/*class EdgeList : public Graph {
public:
    EdgeList();

    void connect(int i, int j);

    void disconnect(int i, int j);

    bool isAdj(int i, int j);
};*/


#endif //MADS_LIBRARY_GRAPH_H
