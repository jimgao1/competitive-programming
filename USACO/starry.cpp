/*
ID: jim.yub1
LANG: C++11
TASK: starry
*/

#include <bits/stdc++.h>

#define MAXN 101
#define INF 1e9

using namespace std;

int dr[] = {1, -1, 0, 0, 1, -1, 1, -1}, dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int R, C, dset[MAXN * MAXN], ans[MAXN][MAXN];
bool grid[MAXN][MAXN], visited[MAXN][MAXN], tmp[MAXN][MAXN];
vector<pair<int, int>> points;
map<int, int> mp;

struct shape {
    pair<int, int> dim, origin;
    bool content[MAXN][MAXN];

    void rotate() {
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i < dim.first; i++) {
            for (int j = 0; j < dim.second; j++) {
                tmp[j][dim.first - i - 1] = content[i][j];
            }
        }
        for (int i = 0; i < dim.second; i++) {
            for (int j = 0; j < dim.first; j++) {
                content[i][j] = tmp[i][j];
            }
        }
        swap(dim.first, dim.second);
    }

    void flip() {
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i < dim.first; i++) {
            for (int j = 0; j < dim.second; j++) {
                tmp[dim.first - i - 1][j] = content[i][j];
            }
        }
        for (int i = 0; i < dim.first; i++) {
            for (int j = 0; j < dim.second; j++) {
                content[i][j] = tmp[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < dim.first; i++) {
            for (int j = 0; j < dim.second; j++) {
                printf("%d", content[i][j]);
            }
            printf("\n");
        }
    }
};

void uinit() {
    for (int i = 0; i < MAXN * MAXN; i++) {
        dset[i] = i;
    }
}

int ufind(int n) {
    while (n != dset[n]) n = dset[n];
    return n;
}

void umerge(int a, int b) {
    int ra = ufind(a), rb = ufind(b);
    if (ra > rb) swap(ra, rb);
    dset[rb] = ra;
}

vector<shape> s;

void fill(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (!grid[r][c] || visited[r][c]) return;
    visited[r][c] = 1;
    points.push_back(make_pair(r, c));
    for (int i = 0; i < 8; i++) fill(r + dr[i], c + dc[i]);
}

bool match(int a, int b) {
    if (s[a].dim != s[b].dim) return 0;
    for (int i = 0; i < s[a].dim.first; i++) {
        for (int j = 0; j < s[a].dim.second; j++) {
            if (s[a].content[i][j] != s[b].content[i][j])
                return 0;
        }
    }
    return 1;
}

bool compare(int a, int b) {
    pair<int, int> x(s[a].dim.second, s[a].dim.first);
    if (s[a].dim != s[b].dim && x != s[b].dim) return 0;

    bool ans = 0;
    for (int i = 0; i < 2; i++) {
        s[a].flip();
        for (int j = 0; j < 4; j++) {
            s[a].rotate();
            ans |= match(a, b);
        }
    }

    return ans;
}

int main() {
    freopen("starry.in", "r", stdin);
    freopen("starry.out", "w", stdout);

    uinit();

    cin >> C >> R;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            grid[i][j] = (str[j] == '1');
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] && !visited[i][j]) {
                points.clear();
                fill(i, j);

                pair<int, int> a(INF, INF), b(-INF, -INF);
                for (pair<int, int> c : points) {
                    a.first = min(a.first, c.first);
                    a.second = min(a.second, c.second);
                    b.first = max(b.first, c.first);
                    b.second = max(b.second, c.second);
                }

                shape cur;
                memset(cur.content, 0, sizeof cur.content);
                cur.dim.first = b.first - a.first + 1;
                cur.dim.second = b.second - a.second + 1;
                cur.origin.first = a.first;
                cur.origin.second = a.second;

                for (pair<int, int> c : points) {
                    cur.content[c.first - a.first][c.second - a.second] = 1;
                }

                s.push_back(cur);
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (compare(i, j)) umerge(i, j);
        }
    }

    for (int k = 0; k < s.size(); k++) {
        for (int i = 0; i < s[k].dim.first; i++) {
            for (int j = 0; j < s[k].dim.second; j++) {
                if (s[k].content[i][j])
                    ans[s[k].origin.first + i][s[k].origin.second + j] = ufind(k) + 1;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (ans[i][j] != 0) {
                int id;
                if (mp.count(ans[i][j])) {
                    id = mp[ans[i][j]];
                } else {
                    id = mp.size();
                    mp[ans[i][j]] = id;
                }

                printf("%c", id + 'a');
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}
