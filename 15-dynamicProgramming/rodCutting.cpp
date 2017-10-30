#include <stdio.h>
#include <algorithm>
using namespace std;

int bottom_up_cut_rod(int priceList[], int n, int steps[]) {
  int* result = new int[n + 1];
  int tempMax  = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (tempMax < priceList[j] + result[i - j]) {
        tempMax = priceList[j] + result[i - j];
        steps[i] = j;
      }
    }
    result[i] = tempMax;
  }
  return result[n];
}


int main(int argc, char *argv[]){
  int arr[]={0, 1, 5, 8, 9, 10, 17, 17, 20};
  int n = 8;
  int* steps = new int[n + 1];
  printf("best benefit: %d\n", bottom_up_cut_rod(arr, n, steps));
  while(n > 0) {
    printf("%d ", steps[n]);
    n = n - steps[n];
  }
  return 0;
};