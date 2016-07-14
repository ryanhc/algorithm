#include <cstdio>

#define MAX 1000

int N;
int boxes[MAX];
int dp[MAX];

int max(int a, int b) {
    return a > b? a: b;
}

// This is a LIS problem
int findMaxBoxes() {
    for (int i=0; i < N; i++) {
        dp[i] = 1;
    }

    for (int pos=0; pos < N; pos++) {
        for (int i=0; i < pos; i++) {
            if (boxes[i] < boxes[pos]) {
                dp[pos] = max(dp[pos], dp[i] + 1);
            }
        }
    }

    int ret = 0;
    for (int i=0; i < N; i++) {
        ret = max(ret, dp[i]);
    }

    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i < N; i++) {
        scanf("%d", &boxes[i]);
    }

    int ret = findMaxBoxes();
    printf("%d\n", ret);

    return 0;
}
