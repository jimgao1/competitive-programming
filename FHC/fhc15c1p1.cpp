
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int T, a, b, k, cnt[10000001];
bool prime[10000001];

vector<int> ps[10];

int main(){
    memset(prime, 1, sizeof prime);
    for (int i = 2; i <= 10000000; i++){
        if (prime[i]){
            for (int j = i * 2; j <= 10000000; j += i){
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= 10000000; i++){
        if (prime[i]){
            for (int j = i; j <= 10000000; j += i){
                cnt[j] += 1;
            }
        }
    }

    for (int i = 2; i <= 10000000; i++){
        ps[cnt[i]].push_back(i);
    }

    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        scanf("%d%d%d", &a, &b, &k);
        auto ia = lower_bound(ps[k].begin(), ps[k].end(), a);
        auto ib = upper_bound(ps[k].begin(), ps[k].end(), b);

        printf("Case #%d: %d\n", i + 1, ib - ia);
    }
}
