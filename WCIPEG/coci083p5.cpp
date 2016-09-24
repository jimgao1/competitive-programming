
#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int N;
ull cnt = 0;
map<int, ull> mp;

int main(){
    cin >> N;

    while(N--){
        int x;
        scanf("%d", &x);

        ull dep = 0;

        auto it = mp.lower_bound(x);
        if (it != mp.end()){
            dep = max(dep, it->second + 1);
        }

        if (it != mp.begin()){
            it--;
            dep = max(dep, it->second + 1);
        }

        mp.insert({x, dep});

        cnt += dep;
        printf("%lld\n", cnt);
    }


}

