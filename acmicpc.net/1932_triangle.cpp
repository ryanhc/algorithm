#include <cstdio>
#define MAX 500

int N;
int m[MAX][MAX];
int sum[MAX][MAX];

int max(int a, int b) {
    return a > b? a: b;
}

int calMaxSum(int x, int y) {
    if (x >= N) {
        return 0;
    }

    int& ret = sum[y][x];
    if (ret != -1) {
        return ret;
    }

    if (y == N-1) {
        ret = m[y][x];
        return ret;
    }
    ret = max(ret, m[y][x] + calMaxSum(x, y+1));
    ret = max(ret, m[y][x] + calMaxSum(x+1, y+1));
    return ret;
}

int main() {
    scanf("%d", &N);
    int n=1;
    for (int i=0; i < N; i++) {
        for (int j=0; j < n; j++) {
            scanf("%d", &m[i][j]);
            sum[i][j] = -1;
        }
        n++;
    }

    int ret = calMaxSum(0, 0);
    printf("%d\n", ret);
    return ret;
}
