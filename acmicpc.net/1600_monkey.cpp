#include <stdio.h>
#include <queue>

#define MAX 200
#define MAX_K 31

int W, H;
int K;
int map[MAX][MAX];
int visited[MAX][MAX][MAX_K];

int dirX[] = { 2,1,-1,-2,-2,-1,1,2, 1,0,-1,0 }; //jump and 4 directions
int dirY[] = { 1,2,2,1,-1,-2,-2,-1, 0,1,0,-1 };

class State {
public:
    State() {
        x = 0;
        y = 0;
        k = 0;
        d = 0;
    }
    int x;
    int y;
    int k;
    int d;
};


int findMinPath() {
    State s;
    std::queue<State> q;
    q.push(s);

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        if (s.x == W - 1 && s.y == H - 1) {
            return s.d;
        }

        //  jump if possible
        if (s.k < K) {
            for (int i = 0; i < 8; i++) {
                State si;
                si.x = s.x + dirX[i];
                si.y = s.y + dirY[i];
                si.k = s.k + 1;
                si.d = s.d + 1;

                if (map[si.y][si.x] == 0 &&
                    0 <= si.x && si.x <= W - 1 &&
                    0 <= si.y && si.y <= H - 1) {
                    if (visited[si.y][si.x][si.k] == -1) {
                        visited[si.y][si.x][si.k] = 1;
                        q.push(si);
                    }
                }
            }
        }

        for (int i = 8; i < 12; i++) {
            State si;
            si.x = s.x + dirX[i];
            si.y = s.y + dirY[i];
            si.k = s.k;
            si.d = s.d + 1;

            if (map[si.y][si.x] == 0 &&
                0 <= si.x && si.x <= W - 1 &&
                0 <= si.y && si.y <= H - 1) {
                if (visited[si.y][si.x][si.k] == -1) {
                    visited[si.y][si.x][si.k] = 1;
                    q.push(si);
                }
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d", &K);
    scanf("%d %d", &W, &H);

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            scanf("%d", &map[y][x]);
            for (int k = 0; k < MAX_K; k++) {
                visited[y][x][k] = -1;
            }
        }
    }

    int ret = findMinPath();
    printf("%d\n", ret);
    return 0;
}

