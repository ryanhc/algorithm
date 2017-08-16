#include <cstdio>

#define MAX 91

int N;
long long int dp[2][MAX];

long long int pinaryNumber(int pos, int digit) {
    long long int ret = dp[digit][pos];
    if (ret != -1) {
        return ret;
    }

    if (pos == 2) {
        dp[0][pos] = 1;
        dp[1][pos] = 0;
        return 1;
    }

    long long int count = 0;
    if (digit == 1) {
        count = pinaryNumber(pos-1, 0);
        dp[digit][pos] = count;
    } else {
        count = pinaryNumber(pos-1, 0) +
                pinaryNumber(pos-1, 1);
        dp[digit][pos] = count;
    }

    return count;
}

int main() {
    for (int y=0; y < 2; y++) {
        for (int x = 0; x < MAX; x++) {
            dp[y][x] = -1;
        }
    }

    scanf("%d", &N);
    long long int count = 0;
    if (N == 1) {
        count = 1;
    } else {
        count = pinaryNumber(N, 0) + pinaryNumber(N, 1);
    }
    printf("%lld\n", count);
}
