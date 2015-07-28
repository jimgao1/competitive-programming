
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>


#define INF 0x3f3f3f3f

using namespace std;

int N, M, minDiff = INF;
vector<int> p;

int main(){
    cin >> M >> N;

    for (int i = 0, x; i < N; i++){
        cin >> x;
        p.push_back(x);
    }

    sort(p.begin(), p.end());

    for (int i = 0; i <= N - M; i++){
        minDiff = min(minDiff, abs(p[i] - p[i + M - 1]));
    }

    cout << minDiff << endl;

    return 0;
}
