
#include <bits/stdc++.h>

#define MAXN 100010
#define INF 0x3f3f3f3f
#define ll long long

using namespace std;

int N, Q, num[MAXN];
ll bit[MAXN];

void add(int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        i += (-i & i);
    }
}

ll sum(int i){
    ll ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= (-i & i);
    }
    return ans;
}

int main(){

    while(cin >> N >> Q){
        memset(num, 0, sizeof num);
        memset(bit, 0, sizeof bit);
        for (int i = 1, x; i <= N; i++){
            cin >> x;
            if (x < 0){
                num[i] = 1;
            } else if (x > 0){
                num[i] = 0;
            } else {
                num[i] = MAXN + 1;
            }

            add(i, num[i]);
        }
        for (int i = 0; i < Q; i++){
            string cmd;
            int a, b;
            cin >> cmd >> a >> b;

            if (cmd == "C"){
                add(a, -1 * num[a]);
                if (b < 0){
                    num[a] = 1;
                } else if (b > 0){
                    num[a] = 0;
                } else {
                    num[a] = MAXN + 1;
                }
                add(a, num[a]);
            } else if (cmd == "P"){
                ll s = sum(b) - sum(a - 1);
                if (s > MAXN)
                    cout << "0";
                else if (s % 2 == 0)
                    cout << "+";
                else
                    cout << "-";
            }
        }
        cout << endl;
    }
}
