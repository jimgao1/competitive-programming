
#include <bits/stdc++.h>

#define MAXN 400001
#define ll long long

using namespace std;

int N;
ll H[MAXN];
ll ans = 0;
stack<pair<ll, ll>> st;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];

    for (int i = 0; i < N; i++) {
        pair<ll, int> cur(H[i], 1);

        while (!st.empty()) {
            if (st.top().first < H[i]) {
                // Adjacent hills can be immediately connected
                ans += st.top().second;
                st.pop();
            } else if (st.top().first == H[i]) {
                ans += st.top().second;
                cur.second += st.top().second;
                st.pop();
            } else {
                break;
            }
        }

        if (!st.empty()) ans++;
        st.push(cur);
    }

    cout << ans << endl;
}
