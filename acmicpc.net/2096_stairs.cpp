#include <cstdio>

#define MAX 100000
#define INF 999999999

int N;

char seq[MAX][3]; // valid range: 0 <= num <= 9
int dp[MAX][3];

int max(int a, int b) {
    return a > b? a: b;
}

int min(int a, int b) {
    return a < b? a: b;
}

int findMaxScore() {
    for (int i=0; i < 3; i++) {
        dp[0][i] = seq[0][i];
    }

    for (int level=1; level < N; level++) {
        for (int pos=0; pos < 3; pos++) {
            if (pos == 0) {
                dp[level][0] = max(dp[level][0], dp[level-1][0] + seq[level][0]);
                dp[level][0] = max(dp[level][0], dp[level-1][1] + seq[level][0]);
            } else if (pos == 1) {
                dp[level][1] = max(dp[level][1], dp[level-1][0] + seq[level][1]);
                dp[level][1] = max(dp[level][1], dp[level-1][1] + seq[level][1]);
                dp[level][1] = max(dp[level][1], dp[level-1][2] + seq[level][1]);
            } else {
                dp[level][2] = max(dp[level][2], dp[level-1][1] + seq[level][2]);
                dp[level][2] = max(dp[level][2], dp[level-1][2] + seq[level][2]);
            }
        }
    }

    int ret = 0;
    for (int i=0; i < 3; i++) {
        ret = max(ret, dp[N-1][i]);
    }
    return ret;
}

int findMinScore() {
    for (int i=0; i < 3; i++) {
        dp[0][i] = seq[0][i];
    }

    for (int level=1; level < N; level++) {
        for (int pos=0; pos < 3; pos++) {
            if (pos == 0) {
                dp[level][0] = min(dp[level][0], dp[level-1][0] + seq[level][0]);
                dp[level][0] = min(dp[level][0], dp[level-1][1] + seq[level][0]);
            } else if (pos == 1) {
                dp[level][1] = min(dp[level][1], dp[level-1][0] + seq[level][1]);
                dp[level][1] = min(dp[level][1], dp[level-1][1] + seq[level][1]);
                dp[level][1] = min(dp[level][1], dp[level-1][2] + seq[level][1]);
            } else {
                dp[level][2] = min(dp[level][2], dp[level-1][1] + seq[level][2]);
                dp[level][2] = min(dp[level][2], dp[level-1][2] + seq[level][2]);
            }
        }
    }

    int ret = INF;
    for (int i=0; i < 3; i++) {
        ret = min(ret, dp[N-1][i]);
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    int a, b, c;
    for (int i=0; i < N; i++) {
        scanf("%d %d %d", &a, &b, &c);
        seq[i][0] = (char)a;
        seq[i][1] = (char)b;
        seq[i][2] = (char)c;
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }

    int retMax = findMaxScore();

    for (int i=0; i < N; i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = INF;
    }

    int retMin = findMinScore();

    printf("%d %d\n", retMax, retMin);

    return 0;
}
