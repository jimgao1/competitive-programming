
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int T, N, dset[MAXN], dsize[MAXN];
map<string, int> dict;

void init(){
    for (int i = 0; i < MAXN; i++)
        dset[i] = i, dsize[i] = 1;
}

int ufind(int n){
    while(n != dset[n])
        n = dset[n];
    return n;
}

void umerge(int a, int b){
    int ra = ufind(a), rb = ufind(b);
    if (ra == rb) return;

    dset[rb] = ra;
    dsize[ra] += dsize[rb];
}

int main(){
    cin >> T;
    while(T--){
        dict.clear();
        init();
        cin >> N;
        for (int i = 0; i < N; i++){
            string sa, sb;
            cin >> sa >> sb;

            if (dict.find(sa) == dict.end()) dict[sa] = dict.size() - 1;
            if (dict.find(sb) == dict.end()) dict[sb] = dict.size() - 1;

            umerge(dict[sa], dict[sb]);
            cout << dsize[ufind(dict[sa])] << endl;
        }
    }
}
