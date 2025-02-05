#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int n, int weight[], int value[]) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    printf("\nDP Matrix:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%4d", dp[i][w]);
        }
        printf("\n");
    }
    return dp[n][W];
}

int main() {
    int W, n;
    printf("Enter the knapsack size/capacity: ");
    scanf("%d", &W);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    int max_value = knapsack(W, n, weight, value);
    printf("\nMaximum value in Knapsack = %d\n", max_value);
    return 0;
}
