#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


int main() {
int n;
printf("Enter n (>=10): \n");
scanf("%d", &n);


if (n < 10) {
printf("n must be at least 10\n");
return 0;
}


int *arr = (int *)malloc(n * sizeof(int));
srand(time(NULL));


for (int i = 0; i < n; i++)
arr[i] = rand() % 1000;


int L1 = INT_MIN; 
int L2 = INT_MIN; 
int L3 = INT_MIN;
int L4 = INT_MIN;
int S1 = INT_MAX;
int S2 = INT_MAX;
int S3 = INT_MAX;


for (int i = 0; i < n; i++) {
int x = arr[i];


// Largest
if (x > L1) { 
    L4 = L3; L3 = L2; L2 = L1; L1 = x; }
else if (x > L2) { 
    L4 = L3; L3 = L2; L2 = x; }
else if (x > L3) { 
    L4 = L3; L3 = x; }
else if (x > L4) { 
    L4 = x; }


// Smallest
if (x < S1) { 
    S3 = S2; S2 = S1; S1 = x; }
else if (x < S2) { 
    S3 = S2; S2 = x; }
else if (x < S3) { 
    S3 = x; }
}


printf("Array:\n");
for (int i = 0; i < n; i++) printf("%d ", arr[i]);


printf("4th Largest = %d\n", L4);
printf("3rd Smallest = %d\n", S3);


free(arr);
return 0;
}