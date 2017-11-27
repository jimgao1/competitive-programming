
#include <bits/stdc++.h>

#define MAXN 4100

using namespace std;

int M, N, offset = MAXN;
int diff[MAXN * 2][MAXN * 2];
vector<pair<int, int>> magnet, metal;

void add(pair<int, int> loc, int rad) {
    int r1 = max(0, loc.first - rad), r2 = min(MAXN * 2 - 1, loc.first + rad + 1);
    int c1 = max(0, loc.second - rad), c2 = min(MAXN * 2 - 1, loc.second + rad + 1);

    diff[r1][c1]++;
    diff[r1][c2]--;
    diff[r2][c1]--;
    diff[r2][c2]++;
}

pair<int, int> rotate(pair<int, int> point) {
    return make_pair(point.first + point.second, point.second - point.first + offset);
}

int main() {
    cin >> M;
    for (int i = 0, r, c; i < M; i++) {
        cin >> r >> c;
        magnet.push_back({r, c});
    }
    cin >> N;
    for (int i = 0, r, c; i < N; i++) {
        cin >> r >> c;
        metal.push_back({r, c});
    }

    for (int i = 0; i < N; i++) {
        int minDist = 1e9;
        for (int j = 0; j < M; j++) {
            minDist = min(minDist, abs(metal[i].first - magnet[j].first) + abs(metal[i].second - magnet[j].second));
        }

        if (minDist != 1e9 && minDist >= 1) {
            add(rotate(metal[i]), minDist - 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < MAXN * 2; i++) {
        for (int j = 0; j < MAXN * 2; j++) {
            if (i > 0) diff[i][j] += diff[i - 1][j];
            if (j > 0) diff[i][j] += diff[i][j - 1];
            if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];

            ans = max(ans, diff[i][j]);
        }
    }

    cout << ans << endl;
}
