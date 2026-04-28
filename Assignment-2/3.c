#include <stdio.h>
#include <string.h>

#define MAXN 100000

// Returns 1 if pattern P matches S starting at index j
int isMatch(char S[], char P[], int j, int m) {
    for (int i = 0; i < m; i++) {
        if (P[i] == '*')        // wildcard matches 'c' or 'd'
            continue;

        if (P[i] != S[j + i])   // exact match required
            return 0;
    }
    return 1;   // full match
}

int main() {
    char S[MAXN], P[1000];

    printf("Enter source string (c and d only): ");
    scanf("%s", S);

    printf("Enter pattern (c, d, *): ");
    scanf("%s", P);

    int n = strlen(S);
    int m = strlen(P);

    int M[MAXN];   // stores match positions
    int count = 0;

    // Slide pattern over string
    for (int j = 0; j <= n - m; j++) {
        if (isMatch(S, P, j, m)) {
            M[count++] = j;
        }
    }

    // Output results
    printf("Match positions: ");
    if (count == 0) {
        printf("No match found");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", M[i]);
        }
    }

    printf("\n");
    return 0;
}
