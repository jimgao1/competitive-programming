
#include <iostream>
#include <string>

#define MAXN 70
#define ll long long

using namespace std;

ll dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};

ll X, Y, x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN], fib[MAXN];

void precompute() {
    fib[0] = fib[1] = 1;
    for (int i = 2; i < MAXN; i++) fib[i] = fib[i - 1] + fib[i - 2];

    ll curX = 1, curY = 0, dir = 0;
    for (int i = 0; i < MAXN; i++) {
        x1[i] = curX, y1[i] = curY;
        curX += fib[i] * dx[dir], curY += fib[i] * dy[dir];
        x2[i] = curX, y2[i] = curY;

        dir = (dir + 1) % 4;
        if (x1[i] > x2[i]) swap(x1[i], x2[i]);
        if (y1[i] > y2[i]) swap(y1[i], y2[i]);
    }
}

void solve() {
    cin >> X >> Y;
    for (int i = 0; i < MAXN; i++) {
        if (x1[i] <= X && X <= x2[i] && y1[i] <= Y && Y <= y2[i]) {
            printf("%d\n", i + 1);
            return;
        }
    }
}

int main() {
    freopen("/tmp/DATA41.txt", "r", stdin);

    precompute();

    int cases = 10;
    while (cases--) {
        solve();
    }
}
