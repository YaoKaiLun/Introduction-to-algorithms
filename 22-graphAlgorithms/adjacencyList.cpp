#include <list>
#include <stdio.h>
using namespace std;

struct Node {
  int key;
};

class Graph {
  int verticeAmount;
  list<Node> * adjLists;
public:
  Graph(int amount);
  void addEdge(Node start, Node end);
  void printGraph();
};

Graph::Graph(int amount) {
  verticeAmount = amount;
  adjLists = new list<Node>[verticeAmount];
};

void Graph::addEdge(Node start, Node end) {
  adjLists[start.key].push_front(end);
};

void Graph::printGraph() {
  for(int i = 0; i < verticeAmount; i++) {
    printf("%d", i);
    for(list<Node>::iterator j = adjLists[i].begin(); j != adjLists[i].end(); j++) {
      printf(" -> %d", j->key);
    }
    printf("\n");
  }
};

int main(int argc, char *argv[]) {
  int verticeAmount = 4;
  Node node0 = {0};
  Node node1 = {1};
  Node node2 = {2};
  Node node3 = {3};
  Graph graph(verticeAmount);
  graph.addEdge(node0, node1);
  graph.addEdge(node0, node2);
  graph.addEdge(node1, node2);
  graph.addEdge(node2, node3);
  graph.printGraph();
};