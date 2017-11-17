#include <list>
#include <stdio.h>
using namespace std;

struct Node {
  int key;
};

class Graph {
  int verticeAmount;
  const Node *vertices;
  list<Node> *adjLists;
public:
  Graph(const int amount, const Node *vertices);
  void addEdge(Node start, Node end);
  void printGraph();
  void topoSort();
  void topoSortUtil(int verticeKey, bool *visited, list<Node> &range);
};

Graph::Graph(const int amount, const Node *nodes) {
  verticeAmount = amount;
  vertices = nodes;
  adjLists = new list<Node>[verticeAmount];
  for(int i = 0; i < verticeAmount; i++) {
    adjLists[i].push_back(vertices[i]);
  }
};

void Graph::addEdge(Node start, Node end) {
  adjLists[start.key].push_back(end);
};

void Graph::printGraph() {
  for(int i = 0; i < verticeAmount; i++) {
    list<Node>::iterator j = adjLists[i].begin();
    printf("%d", j->key);
    for(++j; j != adjLists[i].end(); j++) {
      printf(" -> %d", j->key);
    }
    printf("\n");
  }
};

void Graph::topoSort() {
  bool visited[verticeAmount];
  list<Node> range;

  for(int i = 0; i < verticeAmount; i++) {
    visited[i] = false;
  }

  for(int i = 0; i < verticeAmount; i++) {
    if (!visited[i]) {
      topoSortUtil(vertices[i].key, visited, range);
    }
  }

  list<Node>::iterator node;
  for(node = range.begin(); node != range.end(); node++) {
    printf("%d ", node->key);
  }
}

void Graph::topoSortUtil(int verticeKey, bool *visited, list<Node> &range) {
  visited[verticeKey] = true;

  list<Node>:: iterator node;
  for(node = adjLists[verticeKey].begin(); node != adjLists[verticeKey].end(); node++) {
    if(!visited[node->key]) {
      topoSortUtil(node->key, visited, range);
    }
  }

  range.push_front(*adjLists[verticeKey].begin());
}

int main(int argc, char *argv[]) {
  const int verticeAmount = 6;
  Node vertices[verticeAmount];

  for(int i = 0; i < verticeAmount; i++) {
    Node node = {i};
    vertices[i] = node;
  }

  Graph graph(verticeAmount, vertices);

  graph.addEdge(vertices[2], vertices[3]);
  graph.addEdge(vertices[3], vertices[1]);
  graph.addEdge(vertices[4], vertices[0]);
  graph.addEdge(vertices[4], vertices[1]);
  graph.addEdge(vertices[5], vertices[0]);
  graph.addEdge(vertices[5], vertices[2]);

  printf("the graph is: \n");
  graph.printGraph();

  printf("the topo sort is: \n");
  graph.topoSort();
};