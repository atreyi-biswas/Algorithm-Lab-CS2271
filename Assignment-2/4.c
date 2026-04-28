#include <stdio.h>

int exists(int set[], int size, int x) {
    for (int i = 0; i < size; i++)
        if (set[i] == x)
            return 1;
    return 0;
}

int main() {
    int A[100], B[100];
    int nA, nB, sizeA = 0, sizeB = 0;

    printf("Enter number of elements in set A: ");
    scanf("%d", &nA);

    printf("Enter elements of A:\n");
    while (sizeA < nA) {
        int x;
        scanf("%d", &x);
        if (!exists(A, sizeA, x))
            A[sizeA++] = x;
        else
            printf("Duplicate ignored!\n");
    }

    printf("Enter number of elements in set B: ");
    scanf("%d", &nB);

    printf("Enter elements of B :\n");
    while (sizeB < nB) {
        int x;
        scanf("%d", &x);
        if (!exists(B, sizeB, x))
            B[sizeB++] = x;
        else
            printf("Duplicate ignored!\n");
    }

    int subset = 1;

    for (int i = 0; i < sizeA; i++) {
        if (!exists(B, sizeB, A[i])) {
            subset = 0;
            break;
        }
    }

    if (subset) {
        if (sizeA < sizeB)
            printf("A is a proper subset of B\n");
        else
            printf("A is a subset of B but not a proper subset\n");
    } else {
        printf("A is not a subset of B\n");
    }

    return 0;
}
