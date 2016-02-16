
#include <bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

struct query{
    ll x, top, bottom, tint;
    query(ll a, ll b, ll c, ll d){
        x = a, top = b, bottom = c, tint = d;
    }
};

bool cmp(query a, query b) { return a.x < b.x; }

int N, T;
ll tint[2001];

vector<ll> Y;
vector<query> X;

unordered_map<ll, int> dict;

int main(){
    cin >> N >> T;
    for (int i = 0; i < N; i++){
        ll x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;

        Y.push_back(y1);
        Y.push_back(y2);

        X.push_back(query(x1, y2, y1, t));
        X.push_back(query(x2, y2, y1, -1 * t));
    }

    sort(X.begin(), X.end(), cmp);

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    for (int i = 0; i < Y.size(); i++) dict[Y[i]] = i;

    ll ans = 0, lastX = X[0].x;

    for (query q : X){
        for (int i = 0; i < Y.size() - 1; i++){
            if (tint[i] >= T){
                ans += (Y[i + 1] - Y[i]) * (q.x - lastX);
            }
        }

        for (int i = dict[q.bottom]; i < dict[q.top]; i++){
            tint[i] += q.tint;
        }

        lastX = q.x;
    }

    cout << ans << endl;
}
