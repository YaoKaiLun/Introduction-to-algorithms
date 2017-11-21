// g++ kruskal.cpp ../21-disjointSet/DisjointSet.cpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "../21-disjointSet/DisjointSet.hpp"
using namespace std;

struct edge {
  int src;
  int dest;
  int weight;
};

int compareEdge (const void * a, const void * b) {
  edge* a1 = (edge*)a;
  edge* b1 = (edge*)b;
  return a1->weight > b1->weight;
}

void kruskal(int vertexAmount, int edgeAmount, edge edges[]) {
  DisjointSet *disjointSet = new DisjointSet();
  for(int i = 0; i < vertexAmount; i++) {
    disjointSet->makeSet(i);
  }

  qsort(edges, edgeAmount, sizeof(edges[0]), compareEdge);

  vector<edge> resultEdges;

  for (int i = 0; i < edgeAmount; i++) {
    if (disjointSet->findSet(edges[i].src) != disjointSet->findSet(edges[i].dest)) {
      resultEdges.push_back(edges[i]);
      disjointSet->unionSets(edges[i].src, edges[i].dest);
    }
  }

  vector<edge>::iterator e;
  for(e = resultEdges.begin(); e != resultEdges.end(); e++) {
    printf("%d -> %d : %d \n", e->src, e->dest, e->weight);
  }
}

int main(int argv, char * argc[]) {
  const int vertexAmount = 4;
  const int edgeAmount = 5;
  edge edges[edgeAmount] = {
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
  };

  kruskal(vertexAmount, edgeAmount, edges);
}