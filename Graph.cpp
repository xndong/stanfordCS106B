#include "Graph.h"

using namespace std;
Vertex::Vertex(int vertexValue, bool isVisitedValue)
{
    vertex = vertexValue;
    isVisited = isVisitedValue;
}

Edge::Edge(int source, int dest)
{
    vertexSource = source;
    vertexDest = dest;
}

Graph::Graph(vector<int> &vertexValueVec, vector<Edge> &edgeValueVec)
{
    edgeVec.resize(vertexValueVec.size()); //Fall off here!因为没有resize()的话，edgeVec是空的，用index来access element会error。
    int i = 0;
    for (auto vertexValue : vertexValueVec)
    {
        vertexVec.push_back(Vertex(vertexValue));
        edgeVec[i].push_back(vertexValue);
        i++;
    }

    for (auto edgeValue : edgeValueVec)
    {
        int row = findRowNumbers(edgeValue.vertexSource, vertexValueVec);
        //Fall off here again! edgeVec[i][0]是错误的，因为现在还是空，所以无法access element,因此要用push_back()
        edgeVec[row].push_back(edgeValue.vertexDest);

        //uncomment if undirected graph
        //row = findRowNumbers(edgeValue.vertexDest, vertexValueVec);
        //edgeVec[row].push_back(edgeValue.vertexSource);
    }
}

void Graph::addVertex(int vertexValue)
{
    vertexVec.push_back(Vertex(vertexValue));
    edgeVec.resize(vertexVec.size());
    //edgeVec[vertexVec.size() - 1].push_back(vertex);
}

void Graph::removeVertex(int vertexValue)
{
    //remove all edges i.e.  .erase()
    //remove vertex
    //resize vertexVec
    //resize edgeVec
}

void Graph::addEdge(struct Edge e)
{
    int src = e.vertexSource;
    int des = e.vertexDest;
    addEdge(src, des);
}

void Graph::addEdge(int src, int des)
{
    bool srcIn = isIn(src);
    bool desIn = isIn(des);
    if (!srcIn)         //!isIn(src)
        addVertex(src); //
    if (!desIn)         //!isIn(des)
        addVertex(des); //

    int row = findRowNumbers(src, vertexVec);
    if (edgeVec[row].size() == 0)
        edgeVec[row].push_back(src);
    edgeVec[row].push_back(des);

    row = findRowNumbers(des, vertexVec);
    if (edgeVec[row].size() == 0)
        edgeVec[row].push_back(des);
    //uncomment if undirected graph
    //edgeVec[row].push_back(src);
}

void Graph::removeEdge(struct Edge e)
{
    int src = e.vertexSource;
    int des = e.vertexDest;
    removeEdge(src, des);
}

void Graph::removeEdge(int src, int des)
{
    if (!isIn(src) || !isIn(des))
    {
        cout << "wrong edge, please check source vertex and destination vertex!" << endl;
        return;
    }
    int row = findRowNumbers(src, vertexVec);
    for (auto iter = edgeVec[row].begin(); iter != edgeVec[row].end(); iter++)
    {
        if (*iter == des)
        {
            edgeVec[row].erase(iter);
            return; //break
        }
    }
}

bool Graph::isIn(int value)
{
    for (auto element : vertexVec)
    {
        if (value == element.vertex)
            return true;
    }
    return false;
}

void Graph::printGraph()
{
    cout << "Graph includes the following vertex(es):" << endl; //vertices
    for (auto vertexStruct : vertexVec)
    {
        cout << vertexStruct.vertex << " ";
    }
    cout << endl;

    cout << "Graph includes the following edges:" << endl;
    for (int i = 0; i < edgeVec.size(); i++) // edgeVec.size() == vertexVec.size()
    {
        for (int j = 1; j < edgeVec[i].size(); j++)
        {
            cout << "Vertex " << edgeVec[i][0] << " to vertex " << edgeVec[i][j] << endl;
        }
    }
}

int Graph::findRowNumbers(int vectexValue, vector<int> vertexValueVec)
{
    int row = 0;
    for (int j = 0; j < vertexValueVec.size(); j++)
    {
        if (vectexValue == vertexValueVec[j])
            row = j;
    }
    return row;
}
int Graph::findRowNumbers(int vectexValue, vector<Vertex> vertexVec)
{
    int row = 0;
    for (int j = 0; j < vertexVec.size(); j++)
    {
        if (vectexValue == vertexVec[j].vertex)
            row = j;
    }
    return row;
}
