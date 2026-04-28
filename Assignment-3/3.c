#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

long long comparisons;
int maxDepth;

void swap(int *a, int *b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
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

void quickSort(int arr[], int low, int high, int depth) {
    if (low < high) {
        if (depth > maxDepth) maxDepth = depth;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, depth + 1);
        quickSort(arr, pi + 1, high, depth + 1);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++){
         L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++){
         R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]){
            arr[k++] = L[i++];
        }

        else arr[k++] = R[j++];
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2){
     arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r, int depth) {
    if (l < r) {
        if (depth > maxDepth) maxDepth = depth;
        int m = (l + r) / 2;
        mergeSort(arr, l, m, depth + 1);
        mergeSort(arr, m + 1, r, depth + 1);
        merge(arr, l, m, r);
    }
}

void fillNearlySorted(int arr[]) {
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < N/5; i++) {
        int a = rand() % N;
        int b = rand() % N;
        swap(&arr[a], &arr[b]);
    }
}

int main() {
    srand(time(NULL));
    int arr[N], arr2[N];

    fillNearlySorted(arr);
    for (int i = 0; i < N; i++){
         arr2[i] = arr[i];
    }

    comparisons = 0; maxDepth = 0;
    clock_t s = clock();
    quickSort(arr, 0, N - 1, 1);
    clock_t e = clock();
    printf("QuickSort -> Comp:%lld Depth:%d Time:%.4f\n", comparisons, maxDepth, (double)(e - s) / CLOCKS_PER_SEC);

    comparisons = 0; maxDepth = 0;
    s = clock();
    mergeSort(arr2, 0, N - 1, 1);
    e = clock();
    printf("MergeSort -> Comp:%lld Depth:%d Time:%.4f\n", comparisons, maxDepth, (double)(e - s) / CLOCKS_PER_SEC);

    return 0;
}
