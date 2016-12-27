
#include <bits/stdc++.h>

#define MAXN 12

using namespace std;

bool getBit(int i, int idx) { return i & (1 << idx); }
int setBit(int i, int idx) { return i | (1 << idx); }

int N, S, m[MAXN], dp[MAXN][1 << MAXN][20];

int calc(int id, int contain, int spark){
    if (dp[id][contain][spark] != -1) return dp[id][contain][spark];

    int ans = 0;

    if (contain == 0)
        return pow(m[id] + spark, 2) + spark;

    for (int s1 = 0; s1 <= spark; s1++){
        for (int s2 = 0; s1 + s2 <= spark; s2++){
            int s3 = spark - s1 - s2;

            for (int b1 = 0; b1 < N; b1++){
                if (!getBit(contain, b1)) continue;
                if (b1 == id) continue;
                for (int b2 = b1 + 1; b2 < N; b2++){
                    if (!getBit(contain, b2) || b2 == id) continue;
                    int shit = contain ^ (1 << b1);
                    shit = shit ^ (1 << b2);
                    ans = max(ans, min(calc(b1, shit, s1) * calc(b2, 0, s2), (int)(pow(m[id] + s3, 2))) + s3);
                }
            }
        }
    }

    //printf("id = %d, contain = %d, spark = %d, ans = %d\n", id, contain, spark, ans);
    return dp[id][contain][spark] = ans;
}

int main(){
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> m[i];

    memset(dp, -1, sizeof dp);

    int ans = 0;
    for (int i = 0; i < N; i++){
        ans = max(ans, calc(i, ((1 << N) - 1) ^ (1 << i), S));
    }

    cout << ans << endl;
}

