#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll N, T;
string state;

void calc(int k){
    stringstream ss;
    for (int i = 0; i < N; i++){
        bool a = state[((i - (1LL << k)) % N + N) % N] == '1';
        bool b = state[(i + (1LL << k)) % N] == '1';
        ss << ((a ^ b) ? "1" : "0");
    }
    state = ss.str();
}

int main(){
    cin >> N >> T >> state;

    for (int i = 0; i < 61; i++){
        if (T & (1LL << i)){
            calc(i);
        }
    }

    cout << state << endl;
}
