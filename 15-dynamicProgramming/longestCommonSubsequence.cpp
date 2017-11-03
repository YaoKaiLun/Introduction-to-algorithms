#include <stdio.h>

int longestCommonSubsequence (char sequence1[], char sequence2[], int sequence1Length, int sequence2Length, char **steps) {

  int **memery = new int *[sequence1Length +1];

  for (int i = 0; i <= sequence1Length; i++) {
    memery[i] = new int[sequence2Length + 1];
  }

  for (int i = 0; i <= sequence1Length; i++) {
    memery[i][0] = 0;
  }

  for (int i = 0; i <= sequence2Length; i++) {
    memery[0][i] = 0;
  }

  for (int i = 1; i <= sequence1Length; i++) {
    for (int j = 1; j <= sequence2Length; j++) {
      if (sequence1[i -1] == sequence2[j -1]) {
        memery[i][j] = memery[i - 1][j - 1] + 1;
        // 'u' is 'up', 'l' is left, 'd' is diagonal
        steps[i - 1][j - 1] = 'd';
      } else if (memery[i - 1][j] > memery[i][j - 1]) {
        memery[i][j] = memery[i - 1][j];
        steps[i - 1][j - 1] = 'l';
      } else {
        memery[i][j] = memery[i][j - 1];
        steps[i - 1][j - 1] = 'u';
      }
    }
  }

  return memery[sequence1Length][sequence2Length];
}

void printSteps(char **steps, char sequence1[], int i, int j) {
  if (i < 0 || j < 0) {
    return;
  }

  if (steps[i][j] == 'd') {
    printSteps(steps, sequence1, i - 1, j - 1);
    printf("%c ", sequence1[i]);
  } else if (steps[i][j] == 'u') {
    printSteps(steps, sequence1, i, j - 1);
  } else if (steps[i][j] == 'l') {
    printSteps(steps, sequence1, i - 1, j);
  }
}


int main(int argc, char *arvc[]) {
  char sequence1[] = {'B', 'D', 'C', 'A', 'B', 'A'};
  char sequence2[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
  int sequence1Length = sizeof(sequence1)/sizeof(sequence1[0]);
  int sequence2Length = sizeof(sequence2)/sizeof(sequence2[0]);

  char **steps = new char *[sequence1Length];

  for (int i = 0; i < sequence1Length; i++) {
    steps[i] = new char[sequence2Length];
  }

  int len = longestCommonSubsequence(sequence1, sequence2, sequence1Length, sequence2Length, steps);
  printf("longest length: %d\n", len);

  printf("longest common subsequence: \n");
  printSteps(steps, sequence1, sequence1Length - 1, sequence2Length - 1);

  return 0;
}