
#include <bits/stdc++.h>

#define MAXN 21

using namespace std;

int T, N;
double speed1[MAXN], speed2[MAXN], total[MAXN];

int main(){
    cin >> T >> N;
    for (int i = 0; i < N; i++) cin >> speed1[i] >> speed2[i];

    double ans = -1e7, t1, t2;
    for (double ct = 0; ct <= T; ct += 0.001){
        ct = round(ct * 1000) / 1000.0;
        for (int i = 0; i < N; i++){
            total[i] = ct / speed1[i] + (T - ct) / speed2[i];
        }
        double tmp = 1e9 * 2;
        for (int i = 0; i < N - 1; i++) tmp = min(tmp, total[i]);

        double diff = (tmp - total[N - 1]) * 3600;
        if (diff >= 0){
            if (diff > ans){
                ans = diff;
                t1 = ct, t2 = T - ct;
            }
        }
    }

    if (ans < 0){
        printf("The cheater cannot win.\n");
    } else {
        printf("The cheater can win by %.0f seconds with r = %.2fkm and k = %.2fkm.\n",
               ans, t1, t2);
    }
}
