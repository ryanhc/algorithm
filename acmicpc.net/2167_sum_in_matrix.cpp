#include <cstdio>

#define MAX 300

int N;
int M;
int K;

int m[MAX][MAX];
int sum[MAX][MAX];

int calSum(int x, int y) {
    if (x < 0 || y < 0) {
        return 0;
    } else if (x >= M || y >= N) {
        return 0;
    }

    int& ret = sum[y][x];
    if (x == 0 && y == 0) {
        ret = m[y][x];
        return ret;
    }

    if (ret != -1) {
        return ret;
    }
    ret = m[y][x] + calSum(x, y-1) + calSum(x-1, y) - calSum(x-1, y-1);
    return ret;
}

int calMatrix(int i, int j, int x, int y) {
    return calSum(x, y) - calSum(i-1, y) - calSum(x, j-1) + calSum(i-1, j-1);
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);

    for (int y=0; y < N; y++) {
        for (int x=0; x < M; x++) {
            scanf("%d", &m[y][x]);
        }
    }

    for (int y=0; y < N; y++) {
        for (int x=0; x < M; x++) {
            sum[y][x] = -1;
        }
    }

    calSum(M-1, N-1);

    int i, j;
    int x, y;
    scanf("%d", &K);
    for (int k=0; k < K; k++) {
        scanf("%d", &j);
        scanf("%d", &i);
        scanf("%d", &y);
        scanf("%d", &x);

        int ret = calMatrix(i-1, j-1, x-1, y-1);
        printf("%d\n", ret);
    }
}

