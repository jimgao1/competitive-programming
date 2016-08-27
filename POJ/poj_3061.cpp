
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int T, N, S, ans = 0x3f3f3f3f, num[MAXN];
vector<int> sum;

int main(){
    cin >> T;
    while(T--){
        sum.clear();
        ans = 0x3f3f3f3f;

        cin >> N >> S;
        for (int i = 1; i <= N; i++) cin >> num[i];
        for (int i = 1; i <= N; i++){
            num[i] += num[i - 1];
            sum.push_back(num[i]);
        }

        for (int i = 0; i < N; i++){
            auto it = lower_bound(sum.begin(), sum.end(), sum[i] + S);
            if (it != sum.end()){
                int len = (int)(it - sum.begin()) - i;
                ans = min(ans, len);
            }
        }

        if (ans == 0x3f3f3f3f)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
}
