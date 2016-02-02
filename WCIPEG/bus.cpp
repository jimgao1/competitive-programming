
#include <bits/stdc++.h>

using namespace std;

unsigned long long N, B, C, T = 0, diff[1000001];

int main(){
    cin >> N >> B >> C;

    fill(diff, diff + 1000001, 0);
    for (int i = 0, src, tar; i < N; i++){
        cin >> src >> tar;

        diff[src] += 1, diff[tar] -= 1;
    }

    for (int i = 0; i < B; i++){
        diff[i] += diff[i - 1];

        if (diff[i] > C){
            T += (diff[i] - C) * 5 + C;
        } else if (diff[i] < C){
            T += diff[i];
        } else {
            T += C;
        }
    }

    cout << T << endl;

    return 0;
}
