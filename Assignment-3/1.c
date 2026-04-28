#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

long long comparisons = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

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

int randomizedPartition(int arr[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(&arr[r], &arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void fillAscending(int arr[]) { 
    for (int i = 0; i < N; i++) {
        arr[i] = i; 
    }
}

void fillDescending(int arr[]) { 
    for (int i = 0; i < N; i++){
        arr[i] = N - i; 
    }
}

void fillRandom(int arr[]) { 
    for (int i = 0; i < N; i++) {
        arr[i] = rand();
    }
}

void test(void (*fill)(int[]), char *label) {
    int arr[N];
    fill(arr);

    comparisons = 0;
    clock_t start = clock();
    randomizedQuickSort(arr, 0, N - 1);
    clock_t end = clock();

    printf("\n%s\n", label);
    printf("Comparisons: %lld\n", comparisons);
    printf("Time: %.4f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    srand(time(NULL));

    test(fillAscending, "Already Sorted");
    test(fillDescending, "Reverse Sorted");
    test(fillRandom, "Random Order");

    return 0;
}
