#include <cstdio>

#define MAX 41

int dp[MAX][3]; // sum, sumOfZeros, sumOfOnes

int countFib(int n) {
    int& ret = dp[n][0];
    int& sumOfZeros = dp[n][1];
    int& sumOfOnes = dp[n][2];

    if (ret != -1) {
        return ret;
    }

    if (n==0) {
        ret = 0;
        sumOfZeros = 1;
        sumOfOnes = 0;
    } else if (n==1) {
        ret = 1;
        sumOfZeros = 0;
        sumOfOnes = 1;
    } else {
        ret = countFib(n-1) + countFib(n-2);
        sumOfZeros = dp[n-1][1] + dp[n-2][1];
        sumOfOnes = dp[n-1][2] + dp[n-2][2];
    }

    return ret;
}

int main() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        countFib(n);
        printf("%d %d\n", dp[n][1], dp[n][2]);
    }

    return 0;
}
