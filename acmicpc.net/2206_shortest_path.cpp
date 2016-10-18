#include <cstdio>
#define MAX 1000

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX][2];

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

class State {
public:
    State() {
        x = 0;
        y = 0;
        d = 1;
        wallBrokenCount = 0;
    }

    int x;
    int y;
    int d;
    int wallBrokenCount;
};

State queue[MAX*MAX*4];
int head, tail;

void reset() {
    head = 0;
    tail = 0;
}

int size() {
    return head-tail;
}

void push(State s) {
    queue[tail] = s;
    tail++;
}

void pop() {
    head++;
}

bool isEmpty() {
    return size() == 0? true: false;
}

State front() {
    return queue[head];
}

int shortestPath() {
    State init;
    push(init);

    while(!isEmpty()) {
        State s = front();
        pop();

        if (s.x == M-1 && s.y == N-1) {
            return s.d;
        }

        for (int i = 0; i < 4; i++) {
            State si;
            si.x = s.x + dirX[i];
            si.y = s.y + dirY[i];
            si.d = s.d + 1;
            si.wallBrokenCount = s.wallBrokenCount;

            if (0 <= si.x && si.x <= M-1 &&
                0 <= si.y && si.y <= N-1) {
                if (map[si.y][si.x] == 0 && !visited[si.y][si.x][si.wallBrokenCount]) { // normal direction
                    visited[si.y][si.x][si.wallBrokenCount] = true;
                    push(si);
                } else if (map[si.y][si.x] == 1 &&
                           s.wallBrokenCount == 0 &&
                           !visited[si.y][si.x][si.wallBrokenCount]) { // break wall if possible
                    si.wallBrokenCount = 1;
                    visited[si.y][si.x][si.wallBrokenCount] = true;
                    push(si);
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int y=0; y < N; y++) {
        for (int x=0; x < M; x++) {
            scanf("%1d", &map[y][x]);
            for (int i=0; i < 2; i++) {
                visited[y][x][i] = 0;
            }
        }
    }
    reset();
    int ret = shortestPath();
    printf("%d\n", ret);
    return 0;
}

