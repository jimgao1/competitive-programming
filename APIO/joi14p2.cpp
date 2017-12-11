
#include <bits/stdc++.h>

#define MAXN 600005
#define LOGMAXN 18

using namespace std;

int N, K, Q[MAXN], A[MAXN], B[MAXN];

// Compression
vector<int> vals;
unordered_map<int, int> mp;

// Last seen index
int last[MAXN], segtree[MAXN * 4];
vector<int> order, shits, todo[MAXN];

// Query count
int bit[MAXN];

void update(int i, int val) {
    i += 2;
    while (i < MAXN) {
        bit[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    i += 2;
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

void compress() {
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < vals.size(); i++) mp[vals[i]] = i;
    for (int i = 0; i < N; i++) A[i] = mp[A[i]], B[i] = mp[B[i]];
    for (int i = 0; i < K; i++) Q[i] = mp[Q[i]];
}

void build(int id, int left, int right){
    if (left == right){
        segtree[id] = last[left];
        return;
    }

    int mid = (left + right) / 2;
    build(id * 2, left, mid);
    build(id * 2 + 1, mid + 1, right);

    segtree[id] = max(segtree[id * 2], segtree[id * 2 + 1]);
}

int query(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft) return 0;
    if (qleft <= left && qright >= right) return segtree[id];

    int mid = (left + right) / 2;
    return max(query(id * 2, left, mid, qleft, qright),
               query(id * 2 + 1, mid + 1, right, qleft, qright));
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        vals.push_back(A[i]);
        vals.push_back(B[i]);
        order.push_back(i);
    }
    for (int i = 0; i < K; i++) {
        cin >> Q[i];
        vals.push_back(Q[i]);
    }

    compress();

    for (int i = 0; i < K; i++) {
        last[Q[i]] = i + 1;
    }
    build(1, 0, vals.size() - 1);

    for (int i = 0; i < N; i++) {
        int x = A[i], y = B[i];
        if (x > y) swap(x, y);

        int pos = query(1, 0, vals.size() - 1, x, y - 1);

        if (pos == 0) {
            shits.push_back(i);
        } else {
            todo[pos - 1].push_back(i);
        }
    }

    int total = 0;
    long long ans = 0;
    for (int i = K - 1; i >= 0; i--) {
        for (int card : todo[i]) {
            if ((total - query(max(A[card], B[card]) - 1)) % 2 == 1) {
                ans += vals[min(A[card], B[card])];
            } else {
                ans += vals[max(A[card], B[card])];
            }
        }

        total++;
        update(Q[i], 1);
    }

    for (int i : shits) {
        if ((total - query(max(A[i], B[i]) - 1)) % 2 == 1) {
            ans += vals[B[i]];
        } else {
            ans += vals[A[i]];
        }
    }

    cout << ans << endl;
}
