#include "Graph.hpp"

int main(int argc, char *agrv[]) {
  Graph *graph = new Graph(5, 8);
  graph->addEdge(0, 1, -1);
  graph->addEdge(0, 2, 4);
  graph->addEdge(1, 2, 3);
  graph->addEdge(1, 3, 2);
  graph->addEdge(1, 4, 2);
  graph->addEdge(3, 2, 5);
  graph->addEdge(3, 1, 1);
  graph->addEdge(4, 3, -3);
  graph->bellmanFord(0);
}