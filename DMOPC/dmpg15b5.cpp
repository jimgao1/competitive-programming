
#include <bits/stdc++.h>

#define MAXN 501

using namespace std;

int N, K, L, cnt = 0, intense[MAXN];

int main(){
    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) cin >> intense[i];

    for (int i = 0; i < N; i++){
        int tl = max(abs(intense[i] - intense[(i + 1) % N]),
                     abs(intense[(i - 1 + N) % N] - intense[i]));

        int c = 0;
        if (tl <= L) c++;
        if (intense[i] >= K) c++;

        if (c == 1) cnt++;
    }

    cout << cnt << endl;
}
