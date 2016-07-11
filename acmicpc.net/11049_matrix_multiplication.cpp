#include <cstdio>

#define MAX 501
#define INF 999999999

int N;
int r[MAX];
int c[MAX];
int dp[MAX][MAX];

int min(int a, int b) {
    return a < b? a: b;
}

int minMatrixMul(int s, int e) {
    if (s == e) {
        return 0;
    }

    int& ret = dp[s][e];
    if (dp[s][e] != INF) {
        return ret;
    }
    for (int i=s+1; i <= e; i++) {
        ret = min(ret, minMatrixMul(s, i-1) + minMatrixMul(i, e) + (r[s]*r[i]*c[e]));
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i < N; i++) {
        scanf("%d %d", &r[i], &c[i]);
    }

    for (int y=0; y < MAX; y++) {
        for (int x=0; x < MAX; x++) {
            dp[y][x] = INF;
        }
    }

    int ret = minMatrixMul(0, N-1);
    printf("%d\n", ret);
}
