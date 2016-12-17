
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int C, D, K, v[MAXN], cnt[MAXN];
vector<pair<int, double>> denom;
double w[MAXN], dp[2][200001];

double calcWeight(int val){
    double ww = 0;
    for (int i = 0; i < D; i++){
        int cc = val / denom[i].first;
        val -= cc * denom[i].first;
        ww += denom[i].second * cc;
    }
    return ww;
}

bool cmp(pair<int, double> a, pair<int, double> b){
    return a.first > b.first;
}

int main(){
    cin >> C >> D >> K;
    for (int i = 0; i < D; i++) cin >> v[i] >> w[i];
    for (int i = 0, x; i < K; i++) {
        cin >> x;
        cnt[x - 1] ++;
    }
    double curWeight = 0;
    int curChange = 0;
    for (int i = 0; i < D; i++){
        curWeight += w[i] * cnt[i];
        curChange += v[i] * cnt[i];
        denom.push_back({v[i], w[i]});
    }

    if (C > curChange){
        printf("too poor\n");
        return 0;
    }

    sort(denom.begin(), denom.end(), cmp);

    for (int i = 0; i < 200001; i++) dp[0][i] = dp[1][i] = 1e9;

    for (int i = 0; i * v[i] <= 200001 && i <= cnt[0]; i++){
        dp[0][i * v[0]] = i * w[0];
    }
    for (int i = 1; i < D; i++){
        for (int j = 0; j < 200001; j++) dp[i % 2][j] = 1e9;

        for (int j = 0; j < 200001; j++){
            for (int k = 0; k * v[i] <= j && k <= cnt[i]; k++){
                dp[i % 2][j] = min(dp[i % 2][j], dp[(i + 1) % 2][j - k * v[i]] + w[i] * k);
            }
        }
    }

    double ans = 1e9;
    for (int i = C; i <= curChange; i++){
        double tmp = dp[(D + 1) % 2][curChange - i];
        if (tmp == 1e9) continue;

        tmp += calcWeight(i - C);
        ans = min(ans, tmp);
    }

    printf("%.2f\n", ans);
}

