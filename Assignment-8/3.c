#include <stdio.h>

// Recursive Knapsack
int knapsackRecursive(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapsackRecursive(wt, val, n - 1, W);

    int include = val[n - 1] +
                  knapsackRecursive(wt, val, n - 1, W - wt[n - 1]);

    int exclude = knapsackRecursive(wt, val, n - 1, W);

    return (include > exclude) ? include : exclude;
}

// DP Knapsack
int knapsackDP(int wt[], int val[], int n, int W) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w) {
                int include = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weights: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    printf("Recursive Result: %d\n", knapsackRecursive(wt, val, n, W));
    printf("DP Result: %d\n", knapsackDP(wt, val, n, W));

    return 0;
}