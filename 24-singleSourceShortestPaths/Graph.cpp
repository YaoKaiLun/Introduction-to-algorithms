#include "Graph.hpp"
#include "Edge.hpp"

const int MAX_VALUE = 100000;

Graph::Graph(int vAmount, int eAmount) {
  vertexAmount = vAmount;
  edgeAmount = eAmount;
}

void Graph::addEdge(int src, int dest, int weight) {
  Edge edge = {src, dest, weight};
  edges.push_back(edge);
};

void Graph::init(int start) {
  nodes = new Node[vertexAmount];
  for(int i = 0; i < vertexAmount; i++) {
    if (i == start) {
      nodes[i].distance = 0;
    } else {
      nodes[i].distance = MAX_VALUE;
    }
    nodes[i].parent = -1;
  }
}

int Graph::weight(int src, int dest) {
  vector <Edge> :: iterator i;
  for(i = edges.begin(); i != edges.end(); i++) {
    if (i->src == src && i->dest == dest) {
      return i->weight;
    }
  }
  throw;
}

void Graph::relax(int src, int dest) {
  int temp = nodes[src].distance + weight(src, dest);
  // printf("u-distance: %d, weight(uv): %d, v-distance: %d\n", nodes[src].distance, weight(src, dest), nodes[dest].distance);
  if (temp < nodes[dest].distance) {
    nodes[dest].distance = temp;
  }
}

void Graph::printNodes() {
  printf("nodes: \n");
  for(int i = 0; i < vertexAmount; i++) {
    printf("node: %d, distance: %d \n", i, nodes[i].distance);
  }
}

void Graph::bellmanFord(int start) {
  init(start);
  vector <Edge> :: iterator i;
  for(i = edges.begin(); i != edges.end(); i++) {
    relax(i->src, i->dest);
    // printNodes();
  }
  printNodes();
}