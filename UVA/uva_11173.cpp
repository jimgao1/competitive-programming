
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int T, N, K;

ll calc(int term, ll id){
    if (term == 1){
        if (id == 1)
            return 1;
        return 0;
    }

    if (id < (1LL << (term - 1))){
        return calc(term - 1, id);
    }
    ll cnt = (1LL << (term - 1));
    return cnt + calc(term - 1, cnt * 2 - id - 1);
}

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        cout << calc(N, K) << endl;
    }
}

