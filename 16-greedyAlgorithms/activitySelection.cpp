#include <stdio.h>

int main(int argc, char *argv[]) {
  const int activityAmount = 11;
  int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  int finish[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

  int *result = new int[activityAmount];
  int resultCount = 0;
  result[resultCount] = 0;

  for (int i =1; i < activityAmount; i++) {
    if (start[i] >= finish[result[resultCount]]) {
      result[++resultCount] = i;
    }
  }

  printf("maximum-size set of mutually compatible activities: \n");

  for (int i =0; i < activityAmount; i++) {
    printf("number %d : start at %d, finish at %d \n", result[i] + 1, start[result[i]], finish[result[i]]);
  }

  return 0;
}