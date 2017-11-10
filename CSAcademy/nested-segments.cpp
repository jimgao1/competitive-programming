
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N;
bool nested[MAXN];
vector<pair<int, int>> v;

int main() {
    cin >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i].first > v[j].first && v[i].second < v[j].second) {
                nested[i] = true;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans += nested[i];

    cout << ans << endl;
}
