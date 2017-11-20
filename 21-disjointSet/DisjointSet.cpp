#include "node.hpp"
#include "DisjointSet.hpp"

DisjointSet::DisjointSet() {
  nodes = new std::unordered_map<int, node*>();
}

void DisjointSet::makeSet(int key) {
  node *n = new node();
  n->key = key;
  n->rank = 0;
  n->parent = key;
  (*nodes)[key] = n;
}

int DisjointSet::findSet(int key) {
  node *n = (*nodes)[key];
  return key == n->parent ? key : (key = findSet(n->parent));
}

void DisjointSet::unionSets(int key1, int key2) {
  int parent1Key = findSet(key1);
  int parent2Key = findSet(key2);
  node *parent1 = (*nodes)[parent1Key];
  node *parent2 = (*nodes)[parent2Key];
  if (parent1->rank > parent2->rank) {
    parent2->parent = parent1Key;
  } else {
    parent1->parent = parent2Key;
    if (parent1->rank == parent2->rank) {
      parent2->rank += 1;
    }
  }
}