#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
1. creates ten separate arrays with sizes of 5000,
10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, and 50000 elements,
respectively
2. Populate each array with randomly generated integer values. 
3. For every array, implement and apply four different sorting algorithms i.e., Bubble Sort, Insertion
Sort, Quick Sort, and Merge Sort to arrange the elements in ascending order. 
4. Measure and record the execution time taken by each sorting algorithm for each array size
5. finally perform a detailed comparison of their time performance to analyze and evaluate
the efficiency of these sorting techniques as the input size increases.
*/
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

//bubble sort

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//quick sort

int part(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = part(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//merge sort

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}



int main() {
    int n = 50000;
    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));
    clock_t start, end;

    srand(time(NULL));
    generateArray(arr, n);

    /* Bubble Sort */
    copyArray(arr, temp, n);
    start = clock();
    bubbleSort(temp, n);
    end = clock();
    printf("Bubble Sort Time: %ld clock ticks\n", end - start);

    /* Quick Sort */
    copyArray(arr, temp, n);
    start = clock();
    quickSort(temp, 0, n - 1);
    end = clock();
    printf("Quick Sort Time: %ld clock ticks\n", end - start);

    /* Merge Sort */
    copyArray(arr, temp, n);
    start = clock();
    mergeSort(temp, 0, n - 1);
    end = clock();
    printf("Merge Sort Time: %ld clock ticks\n", end - start);

    free(arr);
    free(temp);

    return 0;
}
