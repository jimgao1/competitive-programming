
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M;
ll cnt = 0;
vector<ll> num;

map<ll, ll> scnt;

int main(){
    scanf("%d%d", &N, &M);
    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);
        num.push_back(x);
    }
    for (int i = 0, x; i < M; i++){
        scanf("%d", &x);
        num.push_back(-1 * x);
    }

    int mid = num.size() / 2;

    vector<int> n1(num.begin(), num.begin() + mid);
    vector<int> n2(num.begin() + mid, num.end());

    for (int i = 0; i < (1 << n1.size()); i++){
        ll sum = 0;
        for (int j = 0; j < n1.size(); j++)
            if (i & (1 << j))
                sum += n1[j];
        scnt[sum] += 1;
    }

    for (int i = 0; i < (1 << n2.size()); i++){
        ll sum = 0;
        for (int j = 0; j < n2.size(); j++)
            if (i & (1 << j))
                sum += n2[j];

        cnt += scnt[0 - sum];
    }

    printf("%lld\n", cnt - 1);
}
