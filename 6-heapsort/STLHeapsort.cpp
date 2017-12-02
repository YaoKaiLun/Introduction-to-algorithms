#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
  int src;
  int dest;
  int weight;
};

bool compare(const Edge &a, const Edge &b) {
  return a.weight < b.weight;
}

int main () {
  Edge edges[] = {
    {0, 1, -1},
    {0, 2, 4},
    {1, 2, 3},
    {1, 3, 2},
    {1, 4, 2},
    {3, 2, 5},
    {3, 1, 1},
    {4, 3, -3}
  };
  vector<Edge> vedges(edges, edges + 8);

  make_heap (vedges.begin(), vedges.end(), compare);
  printf("initial max heap: %d\n", vedges.front().weight);

  pop_heap (vedges.begin(), vedges.end(), compare);
  vedges.pop_back();
  printf("max heap after pop: %d\n", vedges.front().weight);


  // v.push_back(99);
  // push_heap (v.begin(), v.end());
  // printf("max heap after push: %d\n", v.front());

  // sort_heap (v.begin(), v.end());
  // printf("final sorted range :");
  // for (unsigned i=0; i<v.size(); i++) {
  //   printf(" %d", v[i]);
  // }

  // printf("\n");
  return 0;
}