#include <stdio.h>

void swap(int &i, int &j) {
  int temp = j;
  j = i;
  i = temp;
}

void printHeap(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
// recursive function
// void maxHeapify(int arr[], int n, int i) {
//   int bigger = -1;
//   int left = 2 * i;
//   int right = 2 * i + 1;
//   // printf("n: %d, i: %d, left: %d, right: %d \n", n, i, left, right);
//   if (left < n) {
//     bigger = arr[i] < arr[left] ? left : i;
//   }
//   if (right < n) {
//     bigger = arr[bigger] < arr[right] ? right : bigger;
//   }

//   if (bigger != -1 && i != bigger) {
//     swap(arr[i], arr[bigger]);
//     maxHeapify(arr, n, bigger);
//   }
// }

void maxHeapify(int arr[], int n, int i) {
  int left = 2 * i;
  int right = 2 * i + 1;
  bool end = false;
  while(!end) {
    int bigger = -1;
    if (left < n) {
      bigger = arr[i] < arr[left] ? left : i;
    }
    if (right < n) {
      bigger = arr[bigger] < arr[right] ? right : bigger;
    }
    if (bigger != -1 && i != bigger) {
      swap(arr[i], arr[bigger]);
      i = bigger;
      left = 2 * bigger;
      right = 2 * bigger + 1;
    } else {
      end = true;
    }
  }
}

void buildMaxHeap(int arr[], int n) {
  for (int i = n/2 - 1; i >= 0; i--) {
    maxHeapify(arr, n, i);
  }
}

void heapsort(int arr[], int len) {
  buildMaxHeap(arr, len);
  for (int i = len - 1; i >= 0; i--) {
    swap(arr[i], arr[0]);
    maxHeapify(arr, i, 0);
  }
}

int main(int argc, char *argv[]) {
  int arr[] = {3, 5, 6, 0, 8, 7, 1, 2, 4};
  int len = sizeof(arr) / sizeof(int);
  heapsort(arr, len);
  printHeap(arr, len);
}
