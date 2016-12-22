#include <bits/stdc++.h>

#define MAXN 100010
#define ll long long

using namespace std;

int N, A, C, dstream[MAXN], dbusy[MAXN];
vector<int> points;
map<int, int> dict;
vector<pair<int, int>> stream, busy;

void compress(){
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    for (int i = 0; i < points.size(); i++) dict[points[i]] = i;

    for (int i = 0; i < stream.size(); i++)
        stream[i] = {dict[stream[i].first], dict[stream[i].second + 1]};

    for (int i = 0; i < busy.size(); i++)
        busy[i] = {dict[busy[i].first], dict[busy[i].second + 1]};
}

int main(){
    cin >> N >> A >> C;
    for (int i = 0, a, b; i < A; i++){
        cin >> a >> b;
        stream.push_back({a, b});
        points.push_back(a); points.push_back(b + 1);
    }
    for (int i = 0, a, b; i < C; i++){
        cin >> a >> b;
        busy.push_back({a, b});
        points.push_back(a); points.push_back(b + 1);
    }

    compress();

    for (int i = 0; i < stream.size(); i++){
        dstream[stream[i].first] ++;
        dstream[stream[i].second] --;
    }

    for (int i = 0; i < points.size(); i++){
        if (i > 0) dstream[i] += dstream[i - 1];
    }

    for (int i = 0; i < busy.size(); i++){
        dbusy[busy[i].first] ++;
        dbusy[busy[i].second] --;
    }

    for (int i = 0; i < points.size(); i++){
        if (i > 0) dbusy[i] += dbusy[i - 1];
    }

    ll total = 0;
    for (int i = 0; i < points.size(); i++){
        if (dstream[i] > 0 && dbusy[i] == 0)
            total += points[i + 1] - points[i];
    }

    cout << total << endl;
}
