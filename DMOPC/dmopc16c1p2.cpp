
#include <iostream>
#include <map>
#include <set>

#define ll long long

using namespace std;

int N;
set<pair<int, int>> ext;
map<int, int> cnt;

int main(){
    cin >> N;
    for (int i = 0, m, b; i < N; i++){
        cin >> m >> b;

        if (ext.find({m, b}) != ext.end()){
            cout << "Infinity" << endl;
            return 0;
        }

        ext.insert({m, b});

        if (cnt.find(m) != cnt.end()){
            cnt[m] ++;
        } else {
            cnt[m] = 1;
        }
    }

    ll fuckshit = 0;

    for (const auto p : cnt){
        fuckshit += p.second * (N - p.second);
    }

    cout << fuckshit / 2 << endl;
}
