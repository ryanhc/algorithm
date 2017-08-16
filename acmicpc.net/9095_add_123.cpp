#include <cstdio>

#define MAX 12

int dp[MAX];

int count(int n) {
    int& ret = dp[n];
    if (ret != -1) {
        return ret;
    }

    if (n == 0) {
        ret = 1;
        return ret;
    }

    ret = 0;
    if (n - 1 >= 0) {
        ret += count(n-1);
    }
    if (n - 2 >= 0) {
        ret += count(n-2);
    }
    if (n - 3 >= 0) {
        ret += count(n-3);
    }
    return ret;
}

int main() {
    for (int i = 0; i < MAX; i++) {
        dp[i] = -1;
    }

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        int ret = count(n);
        printf("%d\n", ret);
    }

    return 0;
}
