#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

set<ull> fuckshit;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 64; i++)
        fuckshit.insert((1LL << i));

    int T;
    cin >> T;
    while(T--){
        ull n;
        cin >> n;
        cout << (fuckshit.count(n) ? "T" : "F") << "\n";
    }
}
