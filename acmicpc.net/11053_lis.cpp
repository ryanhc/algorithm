#include <cstdio>

#define MAX 1000

int N;
int seq[MAX];
int dp[MAX];

int max(int a, int b) {
    return a > b? a: b;
}

int lis() {
    for(int i=0; i < N; i++) {
        int& ret = dp[i];
        for(int j=0; j < i; j++) {
            if (seq[j] < seq[i]) {
                ret = max(ret, 1 + dp[j]);
            }
        }
    }

    int maxSoFar=0;
    for (int i=0; i < N; i++) {
        maxSoFar = max(maxSoFar, dp[i]);
    }

    return maxSoFar;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i < N; i++) {
        scanf("%d", &seq[i]);
        dp[i] = 1;
    }

    int ret = lis();
    printf("%d\n", ret);
}
