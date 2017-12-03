#include <list>
#include <set>

using namespace std;

const int MAX_VALUE = 100000;

struct Node {
  int key;
  int distance;
};

struct compare {
  bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
  }
};

class Graph {
  int vertexAmount;
  list<Node> *adjLists;
  int *minDistance;
  set<pair<int, int>, compare> priorityQueue;
public:
  Graph(int vertexAmount);
  void addEdge(int src, int dest, int distance);
  void init(int start);
  void djikstra(int start);
  void printSet(set<pair<int, int>, compare> s);
};

Graph::Graph(int vAmount) {
  vertexAmount = vAmount;
  adjLists = new list<Node>[vertexAmount];
  minDistance = new int[vertexAmount];
}

void Graph::addEdge(int src, int dest, int distance) {
  Node node = {dest, distance};
  adjLists[src].push_back(node);
}

void Graph::init(int start) {
  for(int i = 0; i < vertexAmount; i++) {
    if (i == start) {
      Node node = {i, 0};
      priorityQueue.insert(make_pair(i, 0));
      minDistance[i] = 0;
    } else {
      Node node = {i, MAX_VALUE};
      priorityQueue.insert(make_pair(i, MAX_VALUE));
      minDistance[i] = MAX_VALUE;
    }
  }
}

void Graph::djikstra(int start) {
  init(start);
  while(!priorityQueue.empty()) {
    printSet(priorityQueue);
    int key = priorityQueue.begin()->first;
    priorityQueue.erase(priorityQueue.begin());

    list<Node>::iterator it;
    for(it = adjLists[key].begin(); it != adjLists[key].end(); it++) {
      if (minDistance[it->key] > it->distance + minDistance[key]) {
        priorityQueue.erase(make_pair(it->key, minDistance[it->key]));
        priorityQueue.insert(make_pair(it->key, it->distance + minDistance[key]));
        minDistance[it->key] = it->distance + minDistance[key];
      }
    }
  }

  for (int i = 0; i < vertexAmount; i++) {
    printf("vertex: %d, distance: %d \n", i, minDistance[i]);
  }
}

void Graph::printSet(set<pair<int, int>, compare> s) {
  set<pair<int, int> >::iterator it;
  for (it=s.begin(); it!=s.end(); ++it) {
    printf("key: %d, distance: %d \n", it->first, it->second);
  }
}

int main(int argv, char *argc[]) {
  Graph *graph = new Graph(9);
  graph->addEdge(0, 1, 4);
  graph->addEdge(0, 7, 8);
  graph->addEdge(1, 0, 4);
  graph->addEdge(1, 2, 8);
  graph->addEdge(1, 8, 11);
  graph->addEdge(2, 1, 8);
  graph->addEdge(2, 3, 7);
  graph->addEdge(2, 5, 4);
  graph->addEdge(2, 8, 2);
  graph->addEdge(3, 2, 7);
  graph->addEdge(3, 4, 9);
  graph->addEdge(3, 5, 14);
  graph->addEdge(4, 3, 9);
  graph->addEdge(4, 5, 10);
  graph->addEdge(5, 2, 4);
  graph->addEdge(5, 3, 14);
  graph->addEdge(5, 4, 10);
  graph->addEdge(5, 6, 2);
  graph->addEdge(6, 5, 2);
  graph->addEdge(6, 7, 1);
  graph->addEdge(6, 8, 6);
  graph->addEdge(7, 0, 8);
  graph->addEdge(7, 1, 11);
  graph->addEdge(7, 6, 1);
  graph->addEdge(7, 8, 7);
  graph->addEdge(8, 2, 2);
  graph->addEdge(8, 6, 6);
  graph->addEdge(8, 7, 7);
  graph->djikstra(0);
}