#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int N, ans = 0;
vector<int> groups;

int pow2(int p){
    int pp = 1;
    for (int i = 0; i < p; i++){
        pp = (2 * pp) % MOD;
    }
    return pp % MOD;
}

int main(){
    cin >> N;
    char pre = '~';
    int cnt = 0;
    for (int i = 0; i < N; i++){
        string name;
        cin >> name;

        if (name[0] == pre){
            cnt++;
        } else {
            groups.push_back(cnt);
            cnt = 1;
            pre = name[0];
        }
    }

    groups.push_back(cnt);
    groups.erase(groups.begin());

    for (int n : groups){
        ans = (ans + (n * (n + 1) / 2)) % MOD;
    }

    cout << (ans % MOD) << endl;
}
