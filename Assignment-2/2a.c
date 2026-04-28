#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
int min;
int max;
long long comparisons;
} Result;


Result naiveMaxMin(int arr[], int n) {
Result r;
r.min = arr[0];
r.max = arr[0];
r.comparisons = 0;


for (int i = 1; i < n; i++) {
r.comparisons++;
if (arr[i] > r.max)
r.max = arr[i];


r.comparisons++;
if (arr[i] < r.min)
r.min = arr[i];
}
return r;
}


int main() {
int n;
printf("Enter number of elements: ");
scanf("%d", &n);


int *arr = (int *)malloc(n * sizeof(int));
srand(time(NULL));


for (int i = 0; i < n; i++)
arr[i] = rand() % 100000;


Result r = naiveMaxMin(arr, n);


printf("Minimum = %d", r.min);
printf("Maximum = %d", r.max);
printf("Comparisons = %lld", r.comparisons);


free(arr);
return 0;
}