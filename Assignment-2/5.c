#include <stdio.h>

int exists(int set[], int size, int x) {
    for (int i = 0; i < size; i++)
        if (set[i] == x)
            return 1;
    return 0;
}

// Simple bubble sort
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int k, n;
    int unionSet[10000];   
    int uSize = 0;

    printf("Enter number of sets: ");
    scanf("%d", &k);

    for (int i = 1; i <= k; i++) {
        printf("Enter number of elements in set %d: ", i);
        scanf("%d", &n);

        printf("Enter elements of set %d:\n", i);
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);

            if (!exists(unionSet, uSize, x)) {
                unionSet[uSize++] = x;
            }
        }
    }

    // Sort the union
    sort(unionSet, uSize);

    printf("\nUnion of all sets:\n");
    for (int i = 0; i < uSize; i++) {
        printf("%d ", unionSet[i]);
    }

    return 0;
}
