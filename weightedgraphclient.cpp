#include <iostream>
#include "WeightedGraph.h"

using namespace std;

int main()
{
    vector<int> vertexValueVec = {0, 1, 18, 6, 4, 13, 5, 2, 7};
    vector<Edge> edgeValueVec;

    edgeValueVec.push_back(Edge(0, 1, 100));
    edgeValueVec.push_back(Edge(0, 5, 100));
    edgeValueVec.push_back(Edge(1, 2, 100));
    edgeValueVec.push_back(Edge(1, 13, 100));
    edgeValueVec.push_back(Edge(2, 18, 100));
    edgeValueVec.push_back(Edge(5, 13, 100));
    edgeValueVec.push_back(Edge(5, 6, 100));
    edgeValueVec.push_back(Edge(5, 7, 100));
    edgeValueVec.push_back(Edge(7, 13, 100));
    edgeValueVec.push_back(Edge(13, 4, 100));
    edgeValueVec.push_back(Edge(18, 0, 100));
    WeightedGraph graph(vertexValueVec, edgeValueVec);
    graph.printGraph();
    return 0;
}