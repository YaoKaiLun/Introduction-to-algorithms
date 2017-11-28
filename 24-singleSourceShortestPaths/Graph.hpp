#include "Edge.hpp"
#include "Node.hpp"
#include <vector>

using namespace std;

class Graph {
  protected:
    int vertexAmount;
    int edgeAmount;
    Node *nodes;
    vector <Edge> edges;
    void init(int start);
    int weight(int src, int dest);
    void relax(int src, int dest);
    void printNodes();
  public:
    Graph(int vertexAmount, int edgeAmount);
    void addEdge(int src, int dest, int weight);
    void bellmanFord(int start);
    void directedAcyclicGraphs();
};