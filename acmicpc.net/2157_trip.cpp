#include <cstdio>

#define MAX 301

int N, M, K;

int map[MAX][MAX]; // (from, to)
int dp[MAX][MAX];

int max(int a, int b) {
    return a > b? a: b;
}

int findMaxMeal() {
    dp[1][1] = 0;
    for (int to=2; to <= N; to++) {
        dp[to][2] = map[1][to];
    }

    for (int city=2; city <= N; city++) {
        for (int from=2; from < city; from++) {
            for (int m=3; m <= M; m++) {
                if (map[from][city] != -1 && dp[from][m-1] != -1) {
                    dp[city][m] = max(dp[city][m], dp[from][m-1] + map[from][city]);
                }
            }
        }
    }

    int ret = 0;
    for (int m=2; m <= M; m++) {
        ret = max(ret, dp[N][m]);
    }

    return ret;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);

    for (int y=1; y <= N; y++) {
        for (int x=1; x <= N; x++) {
            map[y][x] = -1;
            dp[y][x] = -1;
        }
    }

    for (int i=1; i <= K; i++) {
        int from, to, k;
        scanf("%d %d %d", &from, &to, &k);
        map[from][to] = max(map[from][to], k);
    }

    int ret = findMaxMeal();
    printf("%d\n", ret);

    return 0;
}

