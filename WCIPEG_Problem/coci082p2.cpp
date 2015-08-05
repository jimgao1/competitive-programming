
#include <bits/stdc++.h>

using namespace std;

int N, K;
bool v[1001];

vector<int> erased;

int main(){
    cin >> N >> K;

    memset(v, false, sizeof v);
    v[1] = true;

    while(true){
        if (erased.size() >= K) break;

        for (int i = 1; i <= N; i++){
            if (!v[i]){
                for (int j = 1; j * i <= N; j++) {
                    if (!v[j * i]){
                        v[j * i] = true;
                        erased.push_back(j * i);
                    }
                }
            }
        }
    }

    cout << erased[K - 1] << endl;
}
