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
    vector<vector<int>> graph;
    int V;
public:
    virtual void connect(int i, int j) = 0;

    virtual void disconnect(int i, int j) = 0;

    virtual bool isConnected(int i, int j) = 0;

    virtual vector<int> neighbors(int i) = 0;

    virtual void direct(int i, int j) = 0;

    virtual bool isDirected(int i, int j) = 0;

    virtual void addNode() = 0;

    virtual void show() = 0;

};


class AdjMatrix : public Graph {
public:
    AdjMatrix(int V);

    void connect(int i, int j) override;

    void disconnect(int i, int j) override;

    bool isConnected(int i, int j) override;

    vector<int> neighbors(int i) override;

    void direct(int i, int j) override;

    bool isDirected(int i, int j) override;

    void addNode() override;

    void show() override;
};

class AdjList : public Graph {
public:
    AdjList(int V);

    void connect(int i, int j);

    void disconnect(int i, int j);

    bool isConnected(int i, int j);

    vector<int> neighbors(int i);

    void direct(int i, int j);

    bool isDirected(int i, int j);

    void addNode();
};

/*class EdgeList : public Graph {
public:
    EdgeList();

    void connect(int i, int j);

    void disconnect(int i, int j);

    bool isAdj(int i, int j);
};*/


#endif //MADS_LIBRARY_GRAPH_H
