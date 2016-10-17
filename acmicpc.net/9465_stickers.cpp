#include <cstdio>
#define MAX 100001

int N;
int scores[2][MAX];
int dp[3][MAX];

int max(int a, int b) {
    return a > b? a: b;
}

int getMaxScore(int pos, int mode) {
    if (pos >= N) {
        return 0;
    }

    int& ret = dp[mode][pos];
    if (ret != -1) {
        return ret;
    }

    if (mode == 0) { // top
        ret = max(ret, getMaxScore(pos+1, 1) + scores[0][pos]);
        ret = max(ret, getMaxScore(pos+1, 2));
    } else if (mode == 1) { // bottom
        ret = max(ret, getMaxScore(pos+1, 0) + scores[1][pos]);
        ret = max(ret, getMaxScore(pos+1, 2));
    } else { // all possible cases
        ret = max(ret, getMaxScore(pos+1, 0) + scores[1][pos]);
        ret = max(ret, getMaxScore(pos+1, 1) + scores[0][pos]);
        ret = max(ret, getMaxScore(pos+1, 2));
    }

    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc=1; tc <= T; tc++) {
        scanf("%d", &N);

        for (int y=0; y < 2; y++) {
            for (int x=0; x < N; x++) {
                scanf("%d", &scores[y][x]);
                dp[2][x] = dp[1][x] = dp[0][x] = -1;
            }
        }
        int ret = getMaxScore(0,2);
        printf("%d\n", ret);
    }

    return 0;
}
