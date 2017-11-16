
#include <bits/stdc++.h>

#define MAXN 100006

using namespace std;

int N, H[MAXN], bit[MAXN], L[MAXN], R[MAXN];
vector<int> heights;
unordered_map<int, int> mp;

void update(int i, int val) {
    while (i < MAXN) {
        bit[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

int main() {
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        heights.push_back(H[i]);
    }

    sort(heights.begin(), heights.end());
    heights.erase(unique(heights.begin(), heights.end()), heights.end());

    for (int i = 0; i < heights.size(); i++) {
        mp[heights[i]] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        H[i] = mp[H[i]];
    }

    for (int i = 0; i < N; i++) {
        L[i] = i - query(H[i]);
        update(H[i], 1);
    }

    memset(bit, 0, sizeof bit);
    for (int i = N - 1; i >= 0; i--) {
        R[i] = (N - i - 1) - query(H[i]);
        update(H[i], 1);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (L[i] > R[i] * 2 || R[i] > L[i] * 2) {
            ans++;
        }
    }

    cout << ans << endl;
}
