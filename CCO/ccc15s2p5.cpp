
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, D, t[MAXN], n[MAXN];
double dp[MAXN][9000];
vector<int> st;

bool getBit(int n, int idx){
    return n & (1 << idx);
}

int popcount(int n){
    int a = 0;
    for (int i = 0; i < 12; i++){
        if (getBit(n, i)) a++;
    }
    return a;
}

int compare(int a, int b){
    int cnt = 0;
    while(a > 0){
        int la = (a & -a), lb = (b & -b);
        if (la != lb) cnt++;
        a -= la, b -= lb;
    }
    return cnt;
}

double calc(int cur, int state){
    if (dp[cur][state] != -1) return dp[cur][state];

    if (popcount(state) != D) return 0;
    if (!getBit(state, n[cur])) return 0;
    if (cur == N - 1) return 1e9;

    double ans = 0;
    for (int nxt : st){
        int diff = compare(state, nxt);

        if (diff == 0){
            ans = max(ans, calc(cur + 1, state));
        } else {
            ans = max(ans, min((double)(t[cur + 1] - t[cur]) / diff, calc(cur + 1, nxt)));
        }
    }

    return dp[cur][state] = ans;
}

int main(){
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> n[i];
        n[i] --;
    }

    for (int i = 0; i < (1 << 12); i++){
        if (popcount(i) == D){
            st.push_back(i);
        }
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < 9000; j++)
            dp[i][j] = -1;

    double ans = 0;
    for (int i : st){
        ans = max(ans, calc(0, i));
    }

    if (ans == 1e9)
        printf("0.00\n");
    else
        printf("%.2f\n", ans);
}

