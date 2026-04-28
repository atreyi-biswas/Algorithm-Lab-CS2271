#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

long long comparisons;
int maxDepth;

void swap(int *a, int *b) { 
    int t = *a; 
    *a = *b; 
    *b = t; }

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int depth) {
    if (low < high) {
        if (depth > maxDepth) maxDepth = depth;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, depth + 1);
        quickSort(arr, pi + 1, high, depth + 1);
    }
}

int randomizedPartition(int arr[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(&arr[r], &arr[high]);
    return partition(arr, low, high);
}

void randomizedQS(int arr[], int low, int high, int depth) {
    if (low < high) {
        if (depth > maxDepth) maxDepth = depth;
        int pi = randomizedPartition(arr, low, high);
        randomizedQS(arr, low, pi - 1, depth + 1);
        randomizedQS(arr, pi + 1, high, depth + 1);
    }
}

void fillArray(int arr[], double dupRatio) {
    int unique = N * (1 - dupRatio);

    for (int i = 0; i < unique; i++){
         arr[i] = rand();
    }

    for (int i = unique; i < N; i++){ 
        arr[i] = 5;
    }

    for (int i = 0; i < N; i++) {
        int j = rand() % N;
        swap(&arr[i], &arr[j]);
    }
}

void runTest(double dupRatio, char *label) {
    int arr[N], arrCopy[N];
    fillArray(arr, dupRatio);

    for (int i = 0; i < N; i++){
      arrCopy[i] = arr[i];
    }

    printf("\n%s\n", label);

    comparisons = 0; maxDepth = 0;
    clock_t s = clock();
    quickSort(arr, 0, N - 1, 1);
    clock_t e = clock();
    printf("Standard QS -> Comp:%lld Depth:%d Time:%.4f\n",
           comparisons, maxDepth, (double)(e - s) / CLOCKS_PER_SEC);

    comparisons = 0; maxDepth = 0;
    s = clock();
    randomizedQS(arrCopy, 0, N - 1, 1);
    e = clock();
    printf("Randomized QS -> Comp:%lld Depth:%d Time:%.4f\n", comparisons, maxDepth, (double)(e - s) / CLOCKS_PER_SEC);
}

int main() {
    srand(time(NULL));

    runTest(0.9, "90% Duplicates");
    runTest(0.5, "50% Duplicates");
    runTest(0.1, "10% Duplicates");

    return 0;
}
