#include <bits/stdc++.h>

#define MAXN 4010
#define ll long long

using namespace std;

int N, M, K;
unsigned short sum[MAXN][MAXN];
vector<pair<int, int>> zombie;
vector<int> rr, cc;
map<int, int> dr, dc;

ll calc(){
    ll ans = 0;

    for (int i = 0; i < rr.size(); i ++){
        for (int j = 0; j < cc.size(); j ++){
            if (i > 0) sum[i][j] += sum[i - 1][j];
            if (j > 0) sum[i][j] += sum[i][j - 1];
            if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < rr.size() - 1; i++){
        for (int j = 0; j < cc.size() - 1; j++){
            if (sum[i][j] != 0){
                ans += 1LL * (rr[i + 1] - rr[i]) * (cc[j + 1] - cc[j]);
            }
        }
    }

    return ans;
}

void compress(){
    dr.clear(); dc.clear();

    sort(rr.begin(), rr.end()); rr.erase(unique(rr.begin(), rr.end()), rr.end());
    sort(cc.begin(), cc.end()); cc.erase(unique(cc.begin(), cc.end()), cc.end());

    for (int i = 0; i < rr.size(); i++) dr[rr[i]] = i;
    for (int i = 0; i < cc.size(); i++) dc[cc[i]] = i;
}

ll fuck(int Q){
    rr.clear(); cc.clear();
    memset(sum, 0, sizeof sum);

    for (int i = 0; i < K; i++){
        int r = zombie[i].first, c = zombie[i].second;
        int r1 = max(0, r - Q), c1 = max(0, c - Q);
        int r2 = min(N - 1, r + Q), c2 = min(M - 1, c + Q);

        rr.push_back(r1); rr.push_back(r2 + 1);
        cc.push_back(c1); cc.push_back(c2 + 1);
    }

    compress();

    for (int i = 0; i < K; i++){
        int r = zombie[i].first, c = zombie[i].second;
        int r1 = dr[max(0, r - Q)], c1 = dc[max(0, c - Q)];
        int r2 = dr[min(N, r + Q + 1)], c2 = dc[min(M, c + Q + 1)];

        sum[r1][c1] += 1;
        sum[r2][c2] += 1;
        sum[r1][c2] -= 1;
        sum[r2][c1] -= 1;
    }

    return calc();
}

int main(){
    int Q;
    cin >> N >> M >> K;
    for (int i = 0, r, c; i < K; i++){
        cin >> r >> c;
        zombie.push_back({r - 1, c - 1});
    }
    cin >> Q;
    
    if (Q == 0){
        cout << K << endl;
        return 0;
    }

    cout << fuck(Q) - fuck(Q - 1) << endl;
}
