#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, M, cnt[MAXN];
vector<int> radius, points, freq;

int calc(double dist){
    return lower_bound(radius.begin(), radius.end(), ceil(dist)) - radius.begin();
}

int main(){
    //freopen("target.in", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        radius.push_back(x);
    }

    for (int i = 0, x; i < N; i++){
        cin >> x;
        points.push_back(x);
    }

    sort(radius.begin(), radius.end());

    for (int i = 0; i < M; i++){
        double x, y;
        cin >> x >> y;
        double dist = sqrt(x * x + y * y);

        int ring = calc(dist);
        cnt[ring] ++;
    }

    for (int i = 0; i < N; i++){
        if (cnt[i] != 0) freq.push_back(cnt[i]);
    }

    sort(points.begin(), points.end());
    sort(freq.begin(), freq.end(), greater<int>());

    int fuckshit = 0;
    for (int i = 0; i < freq.size(); i++){
        fuckshit += points[i] * freq[i];
    }

    cout << fuckshit << "\n";
    reverse(points.begin(), points.end());

    fuckshit = 0;
    for (int i = 0; i < freq.size(); i++){
        fuckshit += points[i] * freq[i];
    }

    cout << fuckshit << "\n";

}

