
#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll N, A, B, C;
vector<ll> w;

int main(){
    cin >> N;
    for (int i = 0; i < 3; i++){
        ll x;
        cin >> x;
        w.push_back(x);
    }
    cin >> A >> B >> C;

    sort(w.begin(), w.end());

    ll carry = 0;
    do{
        ll total = floor(A / w[0]) * floor(B / w[1]) * floor(C / w[2]);
        carry = max(carry, total);
    } while(next_permutation(w.begin(), w.end()));

    if (carry == 0)
        cout << "SCAMMED" << endl;
    else{
        if (N % carry == 0)
            cout << N / carry << endl;
        else
            cout << N / carry + 1 << endl;
    }
}

