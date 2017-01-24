
#include <bits/stdc++.h>

#define MAXN 1100
#define ll long long

using namespace std;

struct point{
    int x, y;
    bool checkpoint;
    point(){}
    point(int a, int b, bool c){
        x = a, y = b, checkpoint = c;
    }

};

int N, I, D, S, dp[MAXN][MAXN];
map<ll, int> mp;
set<pair<ll, ll>> check, points;
vector<ll> xx, pp[MAXN];

bool cmp(point a, point b){
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.checkpoint < b.checkpoint;
}

void compress(){
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());

    for (int i = 0; i < xx.size(); i++) mp[xx[i]] = i;

    for (pair<ll, ll> i : points){
        pp[mp[i.first]].push_back(i.second);
    }

    for (int i = 0; i < xx.size(); i++){
        sort(pp[i].begin(), pp[i].end());
        pp[i].erase(unique(pp[i].begin(), pp[i].end()), pp[i].end());
    }
}

int main(){
    cin >> N >> I >> D >> S;
    for (int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        xx.push_back(x);
        points.insert({x, y});
        check.insert({x, y});
        if (y >= S)
            points.insert({x, y - S});
    }
    xx.push_back(0);
    points.insert({0, 0});

    compress();
    memset(dp, -1, sizeof dp);

    dp[0][0] = 0;
    for (int i = 0; i < xx.size(); i++){
        for (int p1 = 0; p1 < pp[i].size(); p1++){
            for (int j = 0; j < i; j++){
                for (int p2 = 0; p2 < pp[j].size(); p2++){
                    if (dp[j][p2] == -1) continue;

                    // (j, p2) -> (i, p1)
                    double m = (double)(pp[i][p1] - pp[j][p2]) / (xx[i] - xx[j]);

                    if (m > 0 && fabs(m) > I) continue;
                    if (m < 0 && fabs(m) > D) continue;

                    int alt = dp[j][p2];
                    if (check.find({xx[i], pp[i][p1]}) != check.end()) alt++;
                    if (S != 0 && check.find({xx[i], pp[i][p1] + S}) != check.end()) alt++;

                    dp[i][p1] = max(dp[i][p1], alt);
                    //printf("x = %d, y = %d, val = %d\n", xx[i], pp[i][p1].first, alt);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < xx.size(); i++){
        for (int j = 0; j < pp[i].size(); j++){
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}

