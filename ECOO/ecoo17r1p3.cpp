
#include <bits/stdc++.h>

#define MAXN 10010
#define ld long double

using namespace std;

int N, h[MAXN];

void doit(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> h[i];

    int top = 0, id = 1;
    for (int i = 0; i < N; i++){
        int cnt = 0;
        ld lastSlope = -1e9;

        for (int j = i + 1; j < N; j++){
            ld curSlope = 1.0 * (ld)(h[j] - h[i]) / (j - i);
            if (curSlope > lastSlope){
                lastSlope = curSlope;
                cnt++;
            }
        }

        lastSlope = 1e9;
        for (int j = i - 1; j >= 0; j--){
            ld curSlope = 1.0 * (ld)(h[j] - h[i]) / (j - i);
            if (curSlope < lastSlope){
                lastSlope = curSlope;
                cnt++;
            }
        }

        if (cnt > top){
            top = cnt;
            id = i + 1;
        } else if (cnt == top){
            id = min(id, i + 1);
        }
    }

    cout << id << endl;
}

int main() {
    int T = 10;
    while(T--) doit();
}

