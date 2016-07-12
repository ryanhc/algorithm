#include <cstdio>

#define MAX 1000
#define INF 999999999

int N;
int seq[MAX];
int dp[MAX];

int min(int a, int b) {
    return a < b? a: b;
}

int findMinJump() {
    dp[0] = 0;
    for (int pos=0; pos < N; pos++) {
        for (int i=0; i < pos; i++) {
            if (seq[i] >= pos-i) {
                dp[pos] = min(dp[pos], dp[i] + 1);
            }
        }
    }
    return dp[N-1];
}

int main() {
    scanf("%d", &N);

    for (int i=0; i < N; i++) {
        scanf("%d", &seq[i]);
        dp[i] = INF;
    }

    int ret = findMinJump();
    if (ret == INF) {
        ret = -1;
    }
    printf("%d\n", ret);

    return 0;
}
