#include <stdio.h>

// Recursive Fibonacci
long long fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// DP (Memoization)
long long fibMemoHelper(int n, long long dp[]) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibMemoHelper(n - 1, dp) + fibMemoHelper(n - 2, dp);
    return dp[n];
}

long long fibMemo(int n) {
    long long dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    return fibMemoHelper(n, dp);
}

// DP (Tabulation)
long long fibTab(int n) {
    long long dp[n + 1];
    dp[0] = 0;
    if (n > 0) dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Recursive: %lld\n", fibRecursive(n));
    printf("DP Memoization: %lld\n", fibMemo(n));
    printf("DP Tabulation: %lld\n", fibTab(n));

    return 0;
}