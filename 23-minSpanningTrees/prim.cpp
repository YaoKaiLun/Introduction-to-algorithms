#include <list>
#include <stdio.h>
using namespace std;

const int MAX_VALUE = 100000;
const int vertexAmount = 5;

// the better way is using binary heap
int extractMinWeightNode(int vertice[], bool visitedNodes[]) {
  int minValue = MAX_VALUE, minNode;
  for(int i = 0; i < vertexAmount; i++) {
    if (!visitedNodes[i] && vertice[i] < minValue) {
      // printf("%d ", i);
      minValue = vertice[i];
      minNode = i;
    }
  }
  return minNode;
}

void prim(const int weightMatrix[5][5], int start, int result[]) {
  int vertice[vertexAmount];
  int parent[vertexAmount];
  bool visitedNodes[vertexAmount];

  for(int i = 0; i < vertexAmount; i++) {
    vertice[i] = MAX_VALUE;
    visitedNodes[i] = false;
  }

  vertice[start] = 0;
  parent[0] = -1;

  int minNode;
  for(int j = 0; j < vertexAmount - 1; j++) {
    minNode = extractMinWeightNode(vertice, visitedNodes);
    visitedNodes[minNode] = true;

    for(int i = 0; i < vertexAmount; i++) {
      if (weightMatrix[minNode][i] != 0 && !visitedNodes[i] && weightMatrix[minNode][i] < vertice[i]) {
        vertice[i] = weightMatrix[minNode][i];
        parent[i] = minNode;  // put minMode -> i in
      }
    }
  }

  for(int i = 1; i < vertexAmount; i++) {
    printf("%d -> %d  %d \n", parent[i], i, weightMatrix[parent[i]][i]);
  }
}

int main(int argv, char *argc[]) {
  const int weightMatrix[vertexAmount][vertexAmount] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
  };
  int result[vertexAmount];
  int startNode = 0;

  prim(weightMatrix, startNode, result);
  return 0;
}