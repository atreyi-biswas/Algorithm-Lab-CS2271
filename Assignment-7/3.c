#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Compare function for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 1D
int closest1D(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp);

    int min = INT_MAX;
    for(int i=0;i<n-1;i++) {
        int d = abs(arr[i] - arr[i+1]);
        if(d < min) min = d;
    }
    return min;
}

// 2D
double closest2D(int x[], int y[], int n) {
    double min = 1e9;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            double d = sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
            if(d < min) min = d;
        }
    }
    return min;
}

int main() {
    int n;
    printf("Enter number of points: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter 1D points:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Closest Distance (1D): %d\n", closest1D(arr,n));

    int x[n], y[n];
    printf("Enter 2D points (x y):\n");
    for(int i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);

    printf("Closest Distance (2D): %.2lf\n", closest2D(x,y,n));

    return 0;
}