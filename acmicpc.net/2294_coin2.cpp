#include <cstdio>

#define INF 99999999

#define LEN 100
#define MAX 10001

int N;
int K;
int coins[LEN] = {0};
int dp[MAX];

int min(int a, int b) {
    return a < b? a: b;
}

int minCoinChanges() {
    for (int val=1; val <= K; val++) {
        if (dp[val] == 1) {
            continue;
        }
        int ret = INF;
        for (int c=0; c < N; c++) {
            int cval = coins[c];
            if (val >= cval) {
                ret = min(ret, 1 + dp[val - cval]);
            }
        }
        dp[val] = ret;
    }
    return dp[K];
}

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i=0; i <= K; i++) {
        dp[i] = INF;
    }

    int valid=0;
    for (int i=0; i < N; i++) {
        int c;
        scanf("%d", &c);
        if (c <= 10000) {
            coins[valid] = c;
            valid++;
            dp[c] = 1;
        }
    }
    N = valid;

    int ret = minCoinChanges();
    if (ret == INF) {
        ret = -1;
    }

    printf("%d\n", ret);
}
