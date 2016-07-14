#include <cstdio>

#define MAX 1000

int N; // col
int M; // row
char m[MAX][MAX];
int dp[MAX][MAX];

int max(int a, int b) {
    return a > b? a: b;
}

int findMaxCandies() {
    dp[0][0] = m[0][0];
    for (int x=1; x < M; x++) {
        dp[0][x] = dp[0][x-1] + m[0][x];
    }

    for (int y=1; y < N; y++) {
        dp[y][0] = dp[y-1][0] + m[y][0];
    }

    for (int y=1; y < N; y++) {
        for (int x=1; x < M; x++) {
            dp[y][x] = max(dp[y][x], dp[y-1][x] + m[y][x]);
            dp[y][x] = max(dp[y][x], dp[y-1][x-1] + m[y][x]);
            dp[y][x] = max(dp[y][x], dp[y][x-1] + m[y][x]);
        }
    }

    return dp[N-1][M-1];
}

int main() {
    scanf("%d %d", &N, &M);
    int n;
    for (int y=0; y < N; y++) {
        for (int x=0; x < M; x++) {
            scanf("%d", &n);
            m[y][x] = (char)n;
            dp[y][x] = 0;
        }
    }

    int ret = findMaxCandies();
    printf("%d\n", ret);

    return 0;
}
