#include <stdio.h>
#include <algorithm>

/*
  @param priceList 价格列表，长度为 n
  @param n 需要切割的钢管的长度
  @param steps 用于保存最优切割值
  @return 长度为 n 的钢管切割后的最大收益值
*/
int cutRod(int priceList[], int n, int steps[]) {
  int *result = new int[n + 1];
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
  printf("best benefit: %d\n", cutRod(arr, n, steps));
  while(n > 0) {
    printf("%d ", steps[n]);
    n = n - steps[n];
  }
  return 0;
};