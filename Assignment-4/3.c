#include <stdio.h>
#include <limits.h>

double findMedian(int A[], int n, int B[], int m) {
    if (n > m) return findMedian(B, m, A, n);

    int low = 0, high = n;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = (n + m + 1)/2 - i;

        int maxLeftA = (i == 0) ? INT_MIN : A[i-1];
        int minRightA = (i == n) ? INT_MAX : A[i];

        int maxLeftB = (j == 0) ? INT_MIN : B[j-1];
        int minRightB = (j == m) ? INT_MAX : B[j];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((n+m)%2 == 0)
                return ( (maxLeftA > maxLeftB ? maxLeftA : maxLeftB) +
                         (minRightA < minRightB ? minRightA : minRightB) ) / 2.0;
            else
                return (maxLeftA > maxLeftB ? maxLeftA : maxLeftB);
        }
        else if (maxLeftA > minRightB)
            high = i - 1;
        else
            low = i + 1;
    }
    return 0.0;
}

int main() {
    int n, m;
    printf("Size of array A: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter sorted A:\n");
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    printf("Size of array B: ");
    scanf("%d", &m);
    int B[m];
    printf("Enter sorted B:\n");
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    printf("Median of both arrays: %.2f\n", findMedian(A, n, B, m));

    return 0;
}
