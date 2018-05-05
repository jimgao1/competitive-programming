
#include <bits/stdc++.h>

#define MAXN 2001

using namespace std;

int N, T;
double P, dp[MAXN][MAXN];

double calc(int people, int time) {
    if (time == 0) return 0;
    if (people == 0) return 0;
    if (dp[people][time] != -1) return dp[people][time];

    return dp[people][time] = P * (1.0 + calc(people - 1, time - 1))
           + (1 - P) * calc(people, time - 1);
}

int main() {
    cin >> N >> P >> T;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = -1;

    printf("%6f\n", calc(N, T));
}
