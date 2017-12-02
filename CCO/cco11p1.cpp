
#include <bits/stdc++.h>

#define MAXN 100001
#define ll long long

using namespace std;

struct score{
    ll sc;
    double r;

    score(ll _, double __){
        sc = _, r = __;
    }
};

int N;
ll csc;
double range[MAXN];
vector<score> ss;

bool cmp(score a, score b){
    return a.sc > b.sc;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        ll sc;
        double r;
        cin >> sc >> r;
        ss.push_back(score(sc, r));
    }
    cin >> csc;
    sort(ss.begin(), ss.end(), cmp);

    int idx = -1;
    for (int i = 0; i < N; i++){
        if (ss[i].sc == csc) idx = i;
    }

    range[0] = ss[0].r - 1;
    for (int i = 1; i < N; i++){
        double rr = ss[i].r - (ss[i - 1].r + range[i - 1]) - 1;
        range[i] = rr;
    }

    ll low = (ll)(ss[idx].r - range[idx]);
    ll high = (ll)(ss[idx].r + range[idx]);

    cout << low << endl << high << endl;
}

