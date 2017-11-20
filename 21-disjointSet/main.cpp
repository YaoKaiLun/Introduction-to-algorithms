// g++ main.cpp DisjointSet.cpp

#include <stdio.h>
#include "DisjointSet.hpp"

int main(int argc, char *argv[]) {
  DisjointSet *disjointSet = new DisjointSet();

  for(int i = 0; i < 10; i++) {
    disjointSet->makeSet(i);
  }

  printf("1 set: %d \n", disjointSet->findSet(1));
  printf("2 set: %d \n", disjointSet->findSet(2));
  disjointSet->unionSets(1, 2);
  printf("1 set: %d \n", disjointSet->findSet(1));
  printf("2 set: %d \n", disjointSet->findSet(2));
  disjointSet->unionSets(3, 4);
  disjointSet->unionSets(5, 6);
  disjointSet->unionSets(6, 4);
  printf("4 set: %d \n", disjointSet->findSet(4));
  disjointSet->unionSets(2, 4);
  printf("2 set: %d \n", disjointSet->findSet(2));
}