#include <stdio.h>
#include <limits.h>
#include <string>
#include <sstream>

#define INF 0x7fffffff

using namespace std;

/*
  @param matrixRows 矩阵链中每个矩阵的行数
  @param steps 用于保存最优分割点
  @return 矩阵链为 matrixRows 的最小乘积代价
*/
int matrixChainMultiply(int matrixAmount, int matrixRows[], int **steps) {
  int **matrixMemery = new int *[matrixAmount];
  for(int i = 0; i < matrixAmount; i++) {
    matrixMemery[i] = new int[matrixAmount];
  }

  for(int i = 0; i < matrixAmount; i++) {
    matrixMemery[i][i] = 0;
  }

  // l 为子矩阵链长度
  for (int l = 2; l <= matrixAmount; l++) {
    for (int i = 0; i <= matrixAmount - l; i++) {
      int j = i + l - 1;
      matrixMemery[i][j] = INF;
      for (int k = i; k < j; k++) {
        int cost = matrixMemery[i][k] + matrixMemery[k + 1][j] + matrixRows[i] * matrixRows[k + 1] * matrixRows[j + 1];
        if (cost < matrixMemery[i][j]) {
          matrixMemery[i][j] = cost;
          steps[i][j] = k;
        }
      }
    }
  }
  return matrixMemery[0][matrixAmount - 1];
}

 string joinSteps(int **steps, int start, int end) {
  int k = steps[start][end];

  if (start == end) {
    stringstream str;
    str << start;
    return "A" + str.str();
  } else {
    return "(" + joinSteps(steps, start, k) + joinSteps(steps, k + 1, end) + ")";
  }
}

int main(int argc, char *argv[]){
  int matrixAmount = 3;
  int matrixRows[] = {10, 100, 5, 50};

  int **steps = new int *[matrixAmount];
  for(int i = 0; i < matrixAmount; i++) {
    steps[i] = new int[matrixAmount];
  }

  int leastCost = matrixChainMultiply(matrixAmount, matrixRows, steps);
  string result = joinSteps(steps, 0, 2);

  printf("leastCost: %d\n", leastCost);
  printf("best order: %s\n", result.c_str());

  return 0;
};