#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

int fixedPivotSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        else if (pi > k) return fixedPivotSelect(arr, low, pi-1, k);
        else return fixedPivotSelect(arr, pi+1, high, k);
    }
    return -1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        else if (pi > k) return quickSelect(arr, low, pi-1, k);
        else return quickSelect(arr, pi+1, high, k);
    }
    return -1;
}

double medianQuick(int arr[], int n) {
    if (n % 2)
        return quickSelect(arr, 0, n-1, n/2);
    else {
        int a = quickSelect(arr, 0, n-1, n/2 - 1);
        int b = quickSelect(arr, 0, n-1, n/2);
        return (a + b) / 2.0;
    }
}

int main() {
    int n;
    printf("Enter number of scores: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter scores:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Median using Quickselect: %.2f\n", medianQuick(arr, n));

    return 0;
}
