
#include <bits/stdc++.h>

#define MAXN 100010
#define pii pair<int, int>

using namespace std;

int N;
bool visited[2][MAXN];
vector<pii > points;
vector<int> adjList[2][MAXN];

vector<int> xx, yy;
unordered_map<int, int> dx, dy;
queue<pair<int, pii>> q;

void compress() {
    for (pii i : points) {
        xx.push_back(i.first);
        yy.push_back(i.second);
    }

    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());
    yy.erase(unique(yy.begin(), yy.end()), yy.end());

    for (int i = 0; i < xx.size(); i++) dx[xx[i]] = i;
    for (int i = 0; i < yy.size(); i++) dy[yy[i]] = i;

    for (int i = 0; i < points.size(); i++) {
        points[i].first = dx[points[i].first];
        points[i].second = dy[points[i].second];
    }
}

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);

    cin >> N;
    for (int i = 0, x, y; i < N + 2; i++) {
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    compress();

    for (int i = 0; i < points.size(); i++) {
        adjList[0][points[i].second].push_back(i);
        adjList[1][points[i].first].push_back(i);
    }

    q.push(make_pair(0, make_pair(0, 0)));
    q.push(make_pair(0, make_pair(1, 0)));

    while (!q.empty()) {
        int cost = q.front().first, dir = q.front().second.first, cur = q.front().second.second;
        q.pop();

        int x = points[cur].first, y = points[cur].second;
//        printf("Current position: (%d, %d)\n", x, y);

        if (cur == 1 || x == points[1].first || y == points[1].second) {
            cout << cost << "\n";
            return 0;
        }

        int pos = dir == 0 ? y : x;

        for (int i : adjList[dir][pos]) {
            if (!visited[1 - dir][i]) {
                visited[1 - dir][i] = 1;
                q.push(make_pair(cost + 1, make_pair(1 - dir, i)));
            }
        }
    }

    cout << -1 << "\n";
}
