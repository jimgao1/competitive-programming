
#include <bits/stdc++.h>

using namespace std;

int N;
map<string, int> city[700];
vector<pair<string, string>> places;

int id(string st){
    return (st[0] - 'A') * 26 + (st[1] - 'A');
}

int main(){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++){
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2);
        city[id(b)][a] ++;
        places.push_back({a, b});
    }

    int ans = 0;
    for (int i = 0; i < N; i++){
        if (places[i].first != places[i].second)
            ans += (city[id(places[i].first)][places[i].second]);
    }

    cout << ans / 2 << endl;
}

