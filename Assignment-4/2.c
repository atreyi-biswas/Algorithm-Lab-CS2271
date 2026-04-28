#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; 
    *a = *b; 
    *b = t;
}

int insertionSortMedian(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr[n/2];
}

int partition(int arr[], int low, int high, int pivot) {
    int i;
    for (i = low; i <= high; i++)
        if (arr[i] == pivot) break;
    swap(&arr[i], &arr[high]);

    int store = low;
    for (i = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(&arr[store], &arr[i]);
            store++;
        }
    }
    swap(&arr[store], &arr[high]);
    return store;
}

int medianOfMedians(int arr[], int low, int high, int k) {
    int n = high - low + 1;

    if (n <= 5)
        return insertionSortMedian(arr + low, n);

    int med[(n+4)/5];
    int i;
    for (i = 0; i < n/5; i++)
        med[i] = insertionSortMedian(arr + low + i*5, 5);

    if (i*5 < n)
        med[i++] = insertionSortMedian(arr + low + i*5, n%5);

    int mom = medianOfMedians(med, 0, i-1, i/2);
    int pos = partition(arr, low, high, mom);

    if (pos == k) {
        return arr[pos];
    }
    else if (pos > k){
        return medianOfMedians(arr, low, pos-1, k);
    }
    else {
        return medianOfMedians(arr, pos+1, high, k);
    }
}

int main() {
    int n;
    printf("Enter number of households: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter incomes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int median = medianOfMedians(arr, 0, n-1, n/2);
    printf("Median income: %d\n", median);

    return 0;
}
