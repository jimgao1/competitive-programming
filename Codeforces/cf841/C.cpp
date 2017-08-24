#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, B, BB;
multiset<pair<int, int>> m;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0, x; i < N; i++){
        cin >> x;
        B.push_back(x);
        BB.push_back(x);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    for (int i = 0; i < N; i++){
        m.insert(make_pair(B[i], A[i]));
    }

    for (int i = 0; i < N; i++){
        auto it = m.lower_bound(make_pair(BB[i], 0));
        printf("%d ", it->second);
        m.erase(it);
    }

    printf("\n");
}
