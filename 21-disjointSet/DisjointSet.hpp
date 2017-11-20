#ifndef DisjointSet_hpp
#define DisjointSet_hpp

#include "node.hpp"
#include <unordered_map>

class DisjointSet {
  std::unordered_map<int, node*> *nodes;

  public:
    DisjointSet();
    void makeSet(int key);
    int findSet(int key);
    void unionSets(int key1, int key2);
};

#endif