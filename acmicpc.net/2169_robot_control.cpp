#include <cstdio>
#define MAX 1000
#define MIN -999999999
#define max(a,b) (a>b?a:b)

int N, M;
int map[MAX][MAX];
int dp[MAX][MAX][2]; // right, left

int maxPath(int x, int y, int dir) {
    if (x == M-1 && y == N-1) {
        return map[N-1][M-1];
    }
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return MIN;
    }

    int& ret = dp[y][x][dir];
    if (ret != MIN) {
        return ret;
    }

    if (dir == 0) { // right
        ret = max(ret, maxPath(x+1, y, 0) + map[y][x]);
    } else {        // left
        ret = max(ret, maxPath(x-1, y, 1) + map[y][x]);
    }
    
    // go down
    ret = max(ret, maxPath(x, y+1, 0) + map[y][x]);
    ret = max(ret, maxPath(x, y+1, 1) + map[y][x]);
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int y=0; y < N; y++) {
        for (int x=0; x < M; x++) {
            scanf("%d", &map[y][x]);
            for (int k=0; k < 2; k++) {
                dp[y][x][k] = MIN;
            }
        }
    }

    int ret = max(maxPath(0, 0, 0), maxPath(0, 0, 1));
    printf("%d\n", ret);
    return 0;
}
