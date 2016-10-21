
#include <bits/stdc++.h>

#define MAXN 1000001
#define ll long long

using namespace std;

int N, C;
bool prime[MAXN];
set<ll> cuts, family;

ll gcd(ll a, ll b){ return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b){ return (a * b / gcd(a, b)); }

void sieve(){
    memset(prime, 1, sizeof prime);

    prime[0] = prime[1] = false;
    for (int i = 2; i < MAXN; i++){
        if (!prime[i]) continue;
        for (int j = i * 2; j < MAXN; j += i){
            prime[j] = false;
        }
    }
}

int main(){
    sieve();

    cin >> N >> C;
    ll x;
    for (int i = 0; i < C; i++){
        cin >> x;
        while(x > 1){
            if (prime[x]){
                cuts.insert(x);
                break;
            }

            for (int i = 2; i < x; i++){
                if (prime[i] && x % i == 0){
                    x = x / i;
                    cuts.insert(i);
                }
            }
        }
    }

    bool flag = false;
    for (int i = 0; i < N; i++){
        cin >> x;
        while(x > 1){
            if (prime[x]){
                family.insert(x);
                break;
            }

            for (int i = 2; i < x; i++){
                if (prime[i] && x % i == 0){
                    x = x / i;

                    family.insert(i);
                }
            }
        }
    }

    for (int i : family){
        if (cuts.find(i) == cuts.end()){
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "Y" << endl;
}

