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

  Node node0 = {0};
  Node node1 = {1};
  Node node2 = {2};
  Node node3 = {3};

  Node nodes[verticeAmount] = {node0, node1, node2, node3};

  Graph graph(verticeAmount, nodes);

  graph.addEdge(node0, node1);
  graph.addEdge(node0, node2);
  graph.addEdge(node1, node2);
  graph.addEdge(node2, node3);

  printf("the graph is: \n");
  graph.printGraph();
};