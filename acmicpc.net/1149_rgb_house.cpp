#include <cstdio>

#define MAX 1000
#define INF 99999999

int N;
int cost[MAX][3];
int cache[MAX][3];

/*
N = 3;
int cost[][3] = {
    {26, 40, 83}, //rgb
    {49, 60, 57},
    {13, 89, 99},
};
// ans: 96
*/

int min(int a, int b) {
    return a < b? a: b;
}

int rgbHouse(int pos, int color) {
    if (pos == N-1) {
        cache[pos][color] = cost[pos][color];
        return cost[pos][color];
    }

    int& ret = cache[pos][color];
    if (ret != INF) {
        return ret;
    }

    for (int i=0; i < 3; i++) { // for each color
        if (i != color) {
            ret = min(ret, cost[pos][color] + rgbHouse(pos+1, i));
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int y=0; y < N; y++) {
        for (int c=0; c < 3; c++) {
            scanf("%d", &cost[y][c]);
            cache[y][c] = INF;
        }
    }

    int ret = INF;
    for (int i=0; i < 3; i++) {
        ret = min(ret, rgbHouse(0, i));
    }
    printf("%d\n", ret);
}

