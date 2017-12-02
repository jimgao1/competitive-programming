
#include <bits/stdc++.h>

using namespace std;

int N, P, cnt = 0, fuel = 0;
vector<pair<int, int>> pl, ans;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first - a.second < 0) return false;
    if (b.first - b.second < 0) return true;

    return a.second < b.second;
}

int main(){
    scanf("%d%d", &N, &P);
    for (int i = 0, a, b; i < N; i++){
        scanf("%d%d", &a, &b);

        if (i == P - 1){
            cnt = 1, fuel = a;
        } else {
            pl.push_back({a, b});
        }
    }

    ans.push_back({fuel, cnt});
    sort(pl.begin(), pl.end(), cmp);


    for (auto i : pl){
        if (fuel >= i.second && i.first >= i.second){
            fuel += (i.first - i.second);
            cnt++;
        } else {
            break;
        }

        ans.push_back({fuel, cnt});
    }

    sort(ans.begin(), ans.end(), greater<pair<int, int>>());

    int mf = ans[0].first, mcnt = 0;
    for (int i = 0; i < ans.size(); i++){
        if (ans[i].first == mf){
            mcnt = max(mcnt, ans[i].second);
        }
    }

    printf("%d\n%d\n", mf, mcnt);
}
