
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M;
map<int, int> loc;
vector<int> x;

int main(){
    cin >> N >> M;
    for (int i = 0, r, c; i < M; i++){
        cin >> r >> c;
        r--, c--;
        x.push_back(c);
        loc[c] = max(loc[c], N - r);
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    for (int i = 1; i < x.size(); i++){
        loc[x[i]] = max(loc[x[i]], loc[x[i - 1]] - (x[i] - x[i - 1]));
    }

    ll ans = 0;
    for (int i = 0; i < x.size(); i++){
        ll R = loc[x[i]];
        ll D = R;
        if (i < x.size() - 1)
            D = min(D, (ll)(x[i + 1] - x[i]));

        ll area = (R + (R - D + 1)) * D / 2;
        ans += area;
    }

    cout << ans << endl;
}
