

#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll, ll>

using namespace std;

int N;
vector<pii > points;
vector<int> xx, yy;

void init() {
    points.clear();
    xx.clear();
    yy.clear();
}

void solve() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        xx.push_back(x);
        yy.push_back(y);
        points.push_back(make_pair(x, y));
    }

    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());
    sort(yy.begin(), yy.end());
    yy.erase(unique(yy.begin(), yy.end()), yy.end());

    ll ans = 3e9;

    for (int ax = 0; ax < xx.size(); ax++) {
        for (int ay = 0; ay < yy.size(); ay++) {
            for (int bx = 0; bx < xx.size(); bx++) {
                for (int by = 0; by < yy.size(); by++) {
                    ll low = 0, high = 2e9;
                    while (low <= high) {
                        ll mid = (low + high) / 2;

                        int minX = 1e9;
                        int maxX = -1e9;
                        int minY = 1e9;
                        int maxY = -1e9;
                        for (int i = 0; i < N; i++) {
                            int cx = points[i].first, cy = points[i].second;
                            if (cx >= xx[ax] && cx <= (xx[ax] + mid) && cy >= yy[ay] && cy <= (yy[ay] + mid)) {

                            } else if (cx >= xx[bx] && cx <= (xx[bx] + mid) && cy >= yy[by] && cy <= (yy[by] + mid)) {

                            } else {
                                minX = min(minX, cx);
                                maxX = max(maxX, cx);
                                minY = min(minY, cy);
                                maxY = max(maxY, cy);
                            }
                        }

                        if (maxY - minY <= mid && maxX - minX <= mid) {
                            high = mid - 1;
                            ans = min(ans, mid);
                        } else {
                            low = mid + 1;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    freopen("/home/jim/ecoo/DATA41.txt", "r", stdin);

    int T = 10;
    while (T--) {
        init();
        solve();
    }
}
