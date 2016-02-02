
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> num, a, b;
vector<pair<int, int>> freq;
map<int, int> num_cnt;

int main(){
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);
        num.push_back(x);

        num_cnt[x] += 1;
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    int mA = 0, mB = 0;
    for (int i : num){
        if (num_cnt[i] > mA){
            mB = mA;
            mA = num_cnt[i];
        } else if (num_cnt[i] > mB){
            mB = num_cnt[i];
        }
    }

    for (int i : num){
        if (num_cnt[i] == mA)
            a.push_back(i);

        if (num_cnt[i] == mB)
            b.push_back(i);
    }

    int ans = 0;

    for (int na : a)
        for (int nb : b)
            ans = max(ans, abs(na - nb));

    printf("%d\n", ans);
}
