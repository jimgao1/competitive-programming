#include <bits/stdc++.h>

#define ld long double

using namespace std;

struct point {
    ld x, y;
    point(ld a, ld b) {
        x = a, y = b;
    }

    bool operator<(const point p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }

    ld dist_to(point p) {
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }

    string to_string() {
        stringstream ss;
        ss << x << "," << y;
        return ss.str();
    }
};

int N;

vector<point> P;
set<point> PP;

int main() {
    cin >> N;
    assert(N > 1);

    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        P.push_back(point(x, y));
    }

    ld h = P[1].x - P[0].x, dist = 1e18, left = 0;
    PP.insert(P[0]);

    for (int i = 1; i < N; i++) {
        while (left < i && P[i].x - P[left].x > h) {
            PP.erase(PP.find(P[left]));
            left++;
        }

        for (set<point>::iterator it = PP.lower_bound(point(P[i].x - dist, P[i].y - dist));
             it != PP.end() && P[i].y + dist >= it->y; ++it) {

            dist = min(dist, P[i].dist_to(*it));
        }

        PP.insert(P[i]);
        h = min(h, dist);
    }

    cout << fixed << setprecision(10) << dist << endl;
}
