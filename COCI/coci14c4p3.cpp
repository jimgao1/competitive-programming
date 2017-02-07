
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll N, total = 0;
vector<ll> r;

int main(){
    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        r.push_back(x);

        total += x;
    }

    sort(r.begin(), r.end());
    //fuck coci

    cout << max(r[N - 1] * 2, total) << endl;
}

