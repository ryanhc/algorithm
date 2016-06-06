#include <cstdio>

#define MAX 1000
#define INF 999999999

int N;
int M;

int map[MAX][MAX];
int dp[MAX][MAX];

int max(int a, int b) {
    return a > b? a: b;
}

int min(int a, int b) {
    return a < b? a: b;
}

void calSquare() {
    // x
    for (int x=0; x < M; x++) {
        dp[0][x] = map[0][x];
    }

    // y
    for (int y=0; y < N; y++) {
        dp[y][0] = map[y][0];
    }

    // all
    for (int y=1; y < N; y++) {
        for (int x=1; x < M; x++) {
            if (map[y][x] == 1) {
                int v=INF;
                v = min(v, dp[y][x-1]);
                v = min(v, dp[y-1][x]);
                v = min(v, dp[y-1][x-1]);
                dp[y][x] = v + 1;
            } else {
                dp[y][x] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);

    char buf[MAX+2];
    char c;
    fgets(buf, MAX+2, stdin); // remove \n

    for (int y=0; y < N; y++) {
        fgets(buf, MAX+2, stdin);
        for (int x=0; x < M; x++) {
            c = buf[x];
            map[y][x] = c - '0';
            dp[y][x] = 0;
        }
    }

    calSquare();
    int ret = 0;
    for (int y=0; y < N; y++) {
        for (int x=0; x < M; x++) {
            ret = max(ret, dp[y][x]);
        }
    }
    printf("%d\n", ret*ret);
    return 0;
}
