#include <cstdio>

#define MAX 300

int N;
int stairs[MAX];
int dp[MAX];

/*
N = 6;
int stairs[] = {10, 20, 15, 25, 10, 20};
// ans: 75
*/

int max(int a, int b) {
    return a > b? a: b;
}

int step(int pos) {
    int& ret = dp[pos];

    if(ret != -1) {
        return ret;
    }

    if (pos == 0) {
        return ret = stairs[0];
    } else if (pos == 1) {
        return ret = stairs[0] + stairs[1];
    } else if (pos == 2) {
        return ret = max(stairs[0]+stairs[2], stairs[1] + stairs[2]);
    }

    ret = max(ret, stairs[pos] + step(pos-2));
    ret = max(ret, stairs[pos] + stairs[pos-1] + step(pos-3));
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i < N; i++) {
        scanf("%d", &stairs[i]);
    }

    for (int i=0; i < MAX; i++) {
        dp[i] = -1;
    }

    int ret = 0;
    ret = max(ret, step(N-1));
    printf("%d\n", ret);
}

