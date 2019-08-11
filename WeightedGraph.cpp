#include "WeightedGraph.h"

using namespace std;
Vertex::Vertex(int vertexValue, bool isVisitedValue)
{
    vertex = vertexValue;
    isVisited = isVisitedValue;
}

Edge::Edge(int source, int dest, int weightValue)
{
    vertexSource = source;
    vertexDest = dest;
    weight = weightValue;
}

WeightedGraph::WeightedGraph(vector<int> vertexValueVec, vector<Edge> edgeValueVec)
{
    int maxvertexValue = 0;
    for (auto vertexValue : vertexValueVec)
    {
        if (vertexValue > maxvertexValue)
            maxvertexValue = vertexValue;
        vertexVec.push_back(Vertex(vertexValue));
    }

    //edgeVec.resize(vertexValueVec.size()); //resize 到 max vertex number+1 i.e. 18+1 才行，因为vertice不是从0开始的连续value
    edgeVec.resize(maxvertexValue + 1);

    for (auto edgeValue : edgeValueVec)
    {
        edgeVec[edgeValue.vertexSource].push_back(make_pair(edgeValue.vertexDest, edgeValue.weight));
        //uncomment if undirected graph
        //edgeVec[edgeValue.vertexDest].push_back(make_pair(edgeValue.vertexSource, edgeValue.weight));
    }
}

void WeightedGraph::printGraph()
{
    cout << "Graph includes the following vertex(es):" << endl; //vertices
    for (auto vertexStruct : vertexVec)
    {
        cout << vertexStruct.vertex << " ";
    }
    cout << endl;

    cout << "Graph includes the following edges:" << endl;
    for (int i = 0; i < edgeVec.size(); i++)
    {
        for (int j = 0; j < edgeVec[i].size(); j++)
        {
            cout << "Vertex " << i << " to vetex " << edgeVec[i][j].first << ", and edge weight is " << edgeVec[i][j].second << endl;
        }
    }
}

void WeightedGraph::dfs(Vertex v1, Vertex v2)
{
    vector<Vertex> dfsPath;
    dfsHelper(v1, v2, dfsPath);
}
void WeightedGraph::dfsHelper(Vertex v1, Vertex v2, vector<Vertex> dfsPath)
{
    if (v1 == v2) //base case
    {
        for (auto element : dfsPath)
            cout << dfsPath.vertex << " ";
        cout << endl;
    }
    else
    {
        for (auto edgeVec[v1.vertex])
        {
        }
        //choose
        dfsPath.push_back();
        //explore

        //unchoose
    }
}
