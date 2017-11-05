#include<stdio.h>

int max(int a, int b) {
  return a >= b ? a : b;
}

int main(int argc, char *argv []) {
  /** resutl:
   * max price is: 16
   * best choice is:
   * obejct 4, weight: 4, price 9
   * obejct 3, weight: 3, price 5
   * obejct 2, weight: 3, price 2
  */
  const int weights[] = {2, 3, 3, 4, 6};
  const int price[] = {1, 2, 5, 9, 4};
  const int maxWeight = 10;


  /** resutl:
   *  max price is: 220
   *  best choice is:
   *  obejct 3, weight: 30, price 120
   *  obejct 2, weight: 20, price 100
  */
  // const int weights[] = {10, 20, 30};
  // const int price[] = {60, 100, 120};
  // const int maxWeight = 50;

  int objectAmount = sizeof(weights) / sizeof(weights[0]);
  int memery[objectAmount][maxWeight + 1];

  for(int i = 1; i <= maxWeight; i++) {
    memery[0][i] = weights[0] > i ? 0 : price[0];
  }

  for (int i = 1; i < objectAmount; i++) {
    for (int j = 1; j <= maxWeight; j++) {
      if (weights[i] <= j) {
        memery[i][j] = max(memery[i - 1][j], memery[i - 1][j - weights[i]] + price[i]);
      } else {
        memery[i][j] = memery[i - 1][j];
      }
      printf("%d ", memery[i][j]);
    }
    printf("\n");
  }

  printf("max price is: %d \n", memery[objectAmount - 1][maxWeight]);

  printf("best choice is: \n");

  int restWeight = maxWeight;
  for(int i = objectAmount - 1; i > 0; i--) {
    if (memery[i][restWeight] > memery[i - 1][restWeight]) {
      restWeight -= weights[i];
      printf("obejct %i, weight: %d, price %d \n", i + 1, weights[i], price[i]);
    }
  }

  return 0;
}