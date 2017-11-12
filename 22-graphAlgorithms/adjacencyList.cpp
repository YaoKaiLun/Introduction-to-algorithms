#include <list>
#include <stdio.h>
using namespace std;

struct Node {
  int key;
};

class Graph {
  int verticeAmount;
  list<Node> *adjLists;
public:
  Graph(const int amount, Node *nodes);
  void addEdge(Node start, Node end);
  void printGraph();
};

Graph::Graph(const int amount, Node *nodes) {
  verticeAmount = amount;
  adjLists = new list<Node>[verticeAmount];
  for(int i = 0; i < verticeAmount; i++) {
    adjLists[i].push_back(nodes[i]);
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

int main(int argc, char *argv[]) {
  const int verticeAmount = 4;

  Node nodes[verticeAmount];
  for(int i = 0; i < verticeAmount; i++) {
    Node node = {i};
    nodes[i] = node;
  }

  Graph graph(verticeAmount, nodes);

  graph.addEdge(nodes[0], nodes[1]);
  graph.addEdge(nodes[0], nodes[2]);
  graph.addEdge(nodes[1], nodes[2]);
  graph.addEdge(nodes[2], nodes[3]);

  printf("the graph is: \n");
  graph.printGraph();
};