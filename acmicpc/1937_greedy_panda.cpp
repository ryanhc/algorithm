#include <cstdio>

#define MAX 500

int N;
int map[MAX][MAX];
int maxSteps[MAX][MAX];

int dirX[] = {0, 1, 0, -1};
int dirY[] = {-1, 0, 1, 0};

/*
int map[][4] = {
    {14, 9, 12, 10},
    {1, 11, 5, 4},
    {7, 15, 2, 13},
    {6, 3, 16, 8},
};
// ans: 4
int maxSteps[][4] = {
    {-1,-1,-1,-1},
    {-1,-1,-1,-1},
    {-1,-1,-1,-1},
    {-1,-1,-1,-1},
};
*/

int max(int a, int b) {
    return a > b? a: b;
}

int panda(int x, int y) {
    if (maxSteps[y][x] >= 0) {
        return maxSteps[y][x];
    }
    if (x < 0 || x >= N) {
        return 0;
    }
    if (y < 0 || y >= N) {
        return 0;
    }

    // basecase
    int& ret = maxSteps[y][x];
    bool canMove = false;
    for (int dir=0; dir < 4; dir++) {
        int nextX = x + dirX[dir];
        int nextY = y + dirY[dir];

        if (map[y][x] < map[nextY][nextX]) {
            canMove = true;
            break;
        }
    }
    if (!canMove) {
        ret = 1;
        return ret;
    }

    for (int dir=0; dir < 4; dir++) {
        int nextX = x + dirX[dir];
        int nextY = y + dirY[dir];

        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
            if (map[y][x] < map[nextY][nextX]) {
                ret = max(ret, 1 + panda(nextX, nextY));
            }
        }
    }

    return ret;
}

int main() {
    scanf("%d", &N);
    for (int y=0; y < N; y++) {
        for (int x=0; x < N; x++) {
            scanf("%d", &map[y][x]);
            maxSteps[y][x] = -1;
        }
    }

    int ret = 0;
    for (int y=0; y < N; y++) {
        for (int x=0; x < N; x++) {
            ret = max(ret, panda(y, x));
        }
    }

    printf("%d\n", ret);
}

