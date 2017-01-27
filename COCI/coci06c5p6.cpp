
#include <bits/stdc++.h>

#define MAXN 200001
#define MOD 1000000000007LL
#define ll long long

using namespace std;

int N;
ll powers[MAXN];
string str;
unordered_set<ll> found;

void calc(){
    powers[0] = 1;
    for (int i = 1; i <= N; i++){
        powers[i] = powers[i - 1] * 29;
        powers[i] %= MOD;
    }
}

bool test(int i){
    found.clear();

    ll cur = 0;
    for (int j = 0; j < i; j++){
        cur = cur + ((ll)(str[j] - 'a' + 1) * powers[i - j - 1]);
    }

    found.insert(cur);

    for (int j = 1; j + i < N; j++){
        ll a = str[j - 1] - 'a' + 1;
        ll b = str[j + i - 1] - 'a' + 1;

        cur = (cur - (a * powers[i - 1]) % MOD + MOD) % MOD;
        cur = (cur * 29) % MOD;
        cur = (cur + b) % MOD;

        if (found.count(cur)){
            return true;
        }

        found.insert(cur);
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> str;
    calc();

    int low = 0, high = N;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if (test(mid)){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << high << "\n";
}

