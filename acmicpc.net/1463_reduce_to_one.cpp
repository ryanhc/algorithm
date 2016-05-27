#include <cstdio>

#define INF 9999999
#define MAX 1000001

int N;
int cache[MAX];
/*
N = 2;
// ans: 1
N = 10;
// ans: 3
*/

int min(int a, int b) {
    return a < b? a: b;
}

int make1(int num) {
    if (num <= 1) {
        return 0;
    }

    int& ret = cache[num];
    if (ret != INF) {
        return ret;
    }

    if (num % 3 == 0) {
        ret = min(ret, 1 + make1(num/3));
    }
    if (num % 2 == 0) {
        ret = min(ret, 1 + make1(num/2));
    }
    if (num > 1) {
        ret = min(ret, 1 + make1(num-1));
    }

    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i < N+1; i++) {
        cache[i]=INF;
    }
    int ret = make1(N);
    printf("%d\n", ret);
}

