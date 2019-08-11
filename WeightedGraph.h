#ifndef _weightedgraph_h
#define _weightedgraph_h

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

struct Vertex
{
    Vertex(int vertexValue, bool isVisitedValue = false);
    int vertex;
    bool isVisited;
};

struct Edge
{
    Edge(int source, int dest, int weightValue = 0); //default value, eg not a number inf null...
    int vertexSource;
    int vertexDest;
    int weight;
};

class WeightedGraph // weighted graph
{
public:
    //constructor and destructor
    WeightedGraph(vector<int> vertexValueVec, vector<Edge> edgeValueVec); // & is faster to avoid copy
    //member functions
    void addVertex(int vertex);
    void removeVertex(int vertex);
    void addEdge(struct Edge); //添加一条边也要把边的点加到点集合中去
    void addEdge(int src, int des, int weight);
    void removeEdge(struct Edge);
    void removeEdge(int src, int des);
    void printGraph(); //print vertexVec and edgeVec.
    /**
     * graph path search: search for a path from one vertext to another
     * -sometimes, we just want any path( or want to know there is a path).
     * -sometimes, we want to minimize path length( #of edges).
     * -sometimes, we want to minimize path cost( #sum of edge weights).
     */
    void dfs(Vertex v1, Vertex v2); //find a path between two vertices by exploring each possible path as far as possible before backtracking.
    void bfs();                     //
    /**
     * dfs often used in problem of 'if exist'.
     * bfs often used in problem of 'the optimal solution'.
     */
    void Dijskra();
    void Astar();
    void dfsTraverse();
    void bfsTraverse();

private:
    //member varibles
    vector<Vertex> vertexVec;
    vector<vector<pair<int, int>>> edgeVec; //use two-dimensional vector to simulink adjacency list
};

#endif