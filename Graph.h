#ifndef _graph_h
#define _graph_h

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
/**
 * bool isVisted 也可以用一个vector<bool> flag来维护，以将Vertex简化成int.
 */

struct Edge
{
    Edge(int source, int dest);
    int vertexSource;
    int vertexDest;
};

class Graph // unweighted graph
{
public:
    //constructor and destructor
    Graph(vector<int> &vertexValueVec, vector<Edge> &edgeValueVec); // & is faster to avoid copy
    //member functions
    void addVertex(int vertexValue);
    void removeVertex(int vertexValue);
    void addEdge(struct Edge); //添加一条边也要把边的点加到点集合中去
    void addEdge(int src, int des);
    void removeEdge(struct Edge);
    void removeEdge(int src, int des);
    void printGraph(); //print vertexVec and edgeVec.
    bool dfs(Vertex v1, Vertex v2);
    bool bfs(Vertex v1, Vertex v2);
    /**
     * DFS and BFS computing complexity: O(V+E), because of 'visited and unvisited flag'.
     * 
     * Shortest path have two kinds of meaning: the fewest edges.
     * bfs is the fewest edges.
     * -bfs is parallel, so it is difficult to trace the path.Thus, we add a 'Vertex *previous' domain.
     *  when a dequeue and b enqueue, b's previous is a. 
     * -if unweighted graph, bfs is also the fewest cost.
     * -if weighted graph, bfs is invalid and we need dijkstra.
     * Dijkstra is the fewest cost.
     */

private:
    //member varibles
    /**
     * G = (V,E)
     * V = vertex set
     * E = edge set
     */
    vector<Vertex> vertexVec;
    vector<vector<int>> edgeVec; //use two-dimensional vector to simulink adjacency list
    bool isIn(int);
    int findRowNumbers(int, vector<int>);
    int findRowNumbers(int, vector<Vertex>);
};

#endif