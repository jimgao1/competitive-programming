
#include <bits/stdc++.h>

#define MAXN 251
#define ll long long

using namespace std;

int N, Q;
ll bit[MAXN][MAXN][MAXN];

// Adds val to point (i, j, k)
void update(int x, int y, int z, int val) {
    int y1 = y, z1 = z;

    while (x <= N) {
        y = y1;
        while (y <= N) {
            z = z1;
            while (z <= N) {
                bit[x][y][z] += val;
                z += (z & -z);
            }
            y += (y & -y);
        }
        x += (x & -x);
    }
}

// Returns the sum from (1, 1, 1) to (x, y, z)
ll query(int x, int y, int z) {
    ll sum = 0;
    int y1 = y, z1 = z;
    while (x > 0) {
        y = y1;
        while (y > 0) {
            z = z1;
            while (z > 0) {
                sum += bit[x][y][z];
                z -= (z & -z);
            }
            y -= (y & -y);
        }
        x -= (x & -x);
    }

    return sum;
}

//Queries values from (x1, y1, z1) to (x2, y2, z2), inclusive
ll queryRange(int x1, int y1, int z1, int x2, int y2, int z2) {
    x1--, y1--, z1--;
    return query(x2, y2, z2)
           - query(x1, y2, z2) - query(x2, y1, z2) - query(x2, y2, z1)
           + query(x1, y1, z2) + query(x1, y2, z1) + query(x2, y1, z1)
           - query(x1, y1, z1);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    ll ans = 0;
    while(Q--){
        string cmd; cin >> cmd;

        if (cmd == "C"){
            int x, y, z, l;
            cin >> x >> y >> z >> l;
            update(x, y, z, l - queryRange(x, y, z, x, y, z));
        } else {
            int a, b, c, d, e, f;
            cin >> a >> b >> c >> d >> e >> f;
            ans += queryRange(a, b, c, d, e, f);
        }
    }

    cout << ans << "\n";
}
