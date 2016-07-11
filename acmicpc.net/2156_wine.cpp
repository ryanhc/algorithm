#include <cstdio>

#define MAX 10001

int N;
int wines[MAX];
int dp[MAX];

int max(int a, int b) {
    return a > b? a: b;
}

int findMaxWine(int pos) {
    if (pos < 0) {
        return 0;
    } else if (pos == 0) {
        return wines[0];
    } else if (pos == 1) {
        return wines[0] + wines[1];
    }

    int& ret = dp[pos];
    if (ret != -1) {
        return ret;
    }
    ret = max(ret, findMaxWine(pos-1));
    ret = max(ret, findMaxWine(pos-3) + wines[pos-1] + wines[pos]);
    ret = max(ret, findMaxWine(pos-2) + wines[pos]);

    return ret;
}

int main() {
    scanf("%d", &N);

    for (int i=0; i < N; i++) {
        scanf("%d", &wines[i]);
        dp[i] = -1;
    }
    wines[N] = 0;
    dp[N] = -1;

    int ret = findMaxWine(N);
    printf("%d\n", ret);
    return 0;
}
