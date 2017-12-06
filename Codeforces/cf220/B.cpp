#include <bits/stdc++.h>

#define MAXN 100005
#define blocksz 400
#define pii pair<int, int>

using namespace std;

int N, Q, A[MAXN];
int cl = 0, cr = -1, ans = 0;

vector<pii > queries, orig;
unordered_map<int, int> mp;
map<pii, int> mp_ans;

void update(int l, int r) {
    while (l < cl) {
        cl--;
        if (mp[A[cl]] == A[cl]) {
            ans--;
        } else if (mp[A[cl]] + 1 == A[cl]) {
            ans++;
        }
        mp[A[cl]]++;
    }

    while (r > cr) {
        cr++;
        if (mp[A[cr]] == A[cr]) {
            ans--;
        } else if (mp[A[cr]] + 1 == A[cr]) {
            ans++;
        }
        mp[A[cr]]++;
    }

    while (l > cl) {
        if (mp[A[cl]] == A[cl]) {
            ans--;
        } else if (mp[A[cl]] - 1 == A[cl]) {
            ans++;
        }
        mp[A[cl]]--;
        cl++;
    }

    while (r < cr) {
        if (mp[A[cr]] == A[cr]) {
            ans--;
        } else if (mp[A[cr]] - 1 == A[cr]) {
            ans++;
        }
        mp[A[cr]]--;
        cr--;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        queries.push_back(make_pair(a - 1, b - 1));
        orig.push_back(make_pair(a - 1, b - 1));
    }

    sort(queries.begin(), queries.end(), [](pii a, pii b) {
        if (a.first / blocksz != b.first / blocksz) return a.first / blocksz < b.first / blocksz;
        return a.second < b.second;
    });

    for (pii i : queries) {
        update(i.first, i.second);
        mp_ans[i] = ans;
    }

    for (pii i : orig) {
        int val = mp_ans[i];
        cout << val << endl;
    }
}
