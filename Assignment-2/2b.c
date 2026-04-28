#include <stdio.h>
typedef struct {
int min;
int max;
long long comparisons;
} Result;


Result maxMinDC(int arr[], int low, int high) {
Result res;


if (low == high) {
res.min = arr[low];
res.max = arr[low];
res.comparisons = 0;
return res;
}
else if (low + 1 == high) {
res.comparisons = 1;
if (arr[low] < arr[high]) {
res.min = arr[low];
res.max = arr[high];
} else {
res.min = arr[high];
res.max = arr[low];
}
return res;
}


int mid = (low + high) / 2;
Result left = maxMinDC(arr, low, mid);
Result right = maxMinDC(arr, mid + 1, high);


res.comparisons = left.comparisons + right.comparisons;


res.comparisons++;
if (left.min < right.min)
res.min = left.min;
else
res.min = right.min;


res.comparisons++;
if (left.max > right.max)
res.max = left.max;
else
res.max = right.max;


return res;
}


int main() {
int n;
printf("Enter number of elements: ");
scanf("%d", &n);


int *arr = (int *)malloc(n * sizeof(int));
srand(time(NULL));


for (int i = 0; i < n; i++)
arr[i] = rand() % 100000;


Result r = maxMinDC(arr, 0, n - 1);


printf("Minimum = %d", r.min);
printf("Maximum = %d", r.max);
printf("Comparisons = %lld", r.comparisons);


free(arr);
return 0;
}