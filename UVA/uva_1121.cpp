
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, S, num[MAXN];

int main(){

    while(cin >> N >> S) {
        memset(num, 0, sizeof num);
        for (int i = 0; i < N; i++)
            cin >> num[i];

        int a = 0, b = 0, sum = num[0], ans = MAXN + 1;
        while(true){
            if (b >= N) break;

            if (sum >= S) {
                ans = min(ans, b - a + 1);
                sum -= num[a];
                a++;
            } else {
                sum += num[b + 1];
                b++;
            }
        }

        if (ans == MAXN + 1)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
}
