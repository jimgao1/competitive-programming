
#include <bits/stdc++.h>

using namespace std;

int N;
vector<double> pos;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        string str;
        double p;
        cin >> str >> p;

        pos.push_back(p);
    }

    sort(pos.begin(), pos.end());

    double ans = 360;

    for (int i = 0; i < pos.size(); i++){
        double st = pos[i];
        double ed = pos[(i + N - 1) % N];

        if (ed < st){
            ans = min(ans, (ed - st + 360));
        } else {
            ans = min(ans, ed - st);
        }
    }

    cout << ceil(ans / 360 * 72 * 60) << endl;
}
