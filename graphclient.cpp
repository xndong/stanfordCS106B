#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    vector<int> vertexValueVec = {0, 1, 18, 6, 4, 13, 5, 2, 7};
    vector<Edge> edgeValueVec;
    /**
     * varible and value:
     * #int a, a is a varible. 10 is a value.
     * #Similarly, for class type, 
     *   'classname a' a is a varible.
     *   'constructor(parameter is applicable)' is a value.
     * 
     * You can pass in a value directly instead of a varible. eg min(10,16) min(a,b)
     * Similarly, you can pass an object value directly just use its constructor instead of an object varible.
     */
    edgeValueVec.push_back(Edge(0, 1));
    edgeValueVec.push_back(Edge(0, 5));
    edgeValueVec.push_back(Edge(1, 2));
    edgeValueVec.push_back(Edge(1, 13));
    edgeValueVec.push_back(Edge(2, 18));
    edgeValueVec.push_back(Edge(5, 13));
    edgeValueVec.push_back(Edge(5, 6));
    edgeValueVec.push_back(Edge(5, 7));
    edgeValueVec.push_back(Edge(7, 13));
    edgeValueVec.push_back(Edge(13, 4));
    edgeValueVec.push_back(Edge(18, 0));
    Graph graph(vertexValueVec, edgeValueVec);
    graph.addVertex(256);
    graph.addVertex(512);
    graph.addEdge(5, 13);
    graph.addEdge(256, 1024);
    graph.addEdge(1024, 2048);
    graph.removeEdge(256, 1024);
    graph.removeEdge(9999, 20480);
    graph.printGraph();
    return 0;
}