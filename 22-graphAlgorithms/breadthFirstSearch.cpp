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
  void BFS(int verticeKey);
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

void Graph::BFS(int verticeKey) {
  bool visited[verticeAmount];
  for(int i = 0; i < verticeAmount; i++) {
    visited[i] = false;
  }

  list<Node> queue;
  queue.push_back(adjLists[verticeKey].front());

  while(!queue.empty()) {
    Node head = queue.front();
    queue.pop_front();

    if (!visited[head.key]) {
      list<Node>:: iterator node = adjLists[head.key].begin();
      printf("%d ", node->key);
      visited[head.key] = true;
      for(++node; node != adjLists[head.key].end(); node++) {
        queue.push_back(*node);
      }
    }
  }

}

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
  graph.addEdge(node2, node0);
  graph.addEdge(node2, node3);
  graph.addEdge(node3, node3);

  printf("the graph is: \n");
  graph.printGraph();

  printf("the BFS is: \n");
  graph.BFS(0);
};