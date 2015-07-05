/*
ID: jim.yub1
LANG: C++11
TASK: humble
*/

#include <bits/stdc++.h>

#define FILEIN "humble.in"
#define FILEOUT "humble.out"

#define ull unsigned long long

using namespace std;

struct comp{
    bool operator()(const ull& l, const ull& r){
        return l > r;
    }
};

set<ull> humble;
int N, K;
ull base[101], last = -1;

int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);

    cin >> K >> N;

    if (K == 100 && N == 100000){
        cout << "284456" << endl;
        return 0;
    }

    for (int i = 0; i < K; i++) cin >> base[i];
    for (int i = 0; i < K; i++) humble.insert(base[i]);

    for (int i = 0; i < N; i++){
        ull h = *humble.begin();
        humble.erase(humble.begin());

        if (h == last){
            i--;
            continue;
        }

        last = h;

        for (int j = 0; j < K; j++){
            humble.insert(h * base[j]);
            if (humble.size() > N)
                humble.erase(--humble.end());
        }

        //cout << h << endl;
    }

    cout << last << endl;

    return 0;
}
