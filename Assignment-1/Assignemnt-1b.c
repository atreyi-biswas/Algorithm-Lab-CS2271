#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
1. generate an array of 50,000 random elements. 
2. Implement both Linear Search and Binary Search algorithms to search for a given element in the array.
3. If the element is found, display its position. 
4. compare the two search methods by reporting the number of comparisons performed and the time taken to locate the element.
*/

#define SIZE 50000

void generateArray(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand();
}

int linearSearch(int arr[], int key, int *comp) {
    for (int i = 0; i < SIZE; i++) {
        (*comp)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int key, int *comp) {
    int low = 0, high = SIZE - 1, mid;

    while (low <= high) {
        (*comp)++;
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[SIZE], key, pos, comparisons;
    clock_t start, end;

    generateArray(arr);

    printf("Enter element to search: ");
    scanf("%d", &key);

    comparisons = 0;
    start = clock();
    pos = linearSearch(arr, key, &comparisons);
    end = clock();

    printf("\nLinear Search:");
    printf("\nPosition = %d", pos);
    printf("\nComparisons = %d", comparisons);
    printf("\nTime = %ld\n", end - start);

    qsort(arr, SIZE, sizeof(int), compare);

    comparisons = 0;
    start = clock();
    pos = binarySearch(arr, key, &comparisons);
    end = clock();

    printf("\nBinary Search:");
    printf("\nPosition = %d", pos);
    printf("\nComparisons = %d", comparisons);
    printf("\nTime = %ld\n", end - start);

    return 0;
}


