
#include <bits/stdc++.h>

#define MAXN 2001

using namespace std;

int N, M, K;
bool found[MAXN];
vector<int> la[MAXN], lb[MAXN];

int main(){
    cin >> N >> M >> K;
    for (int i = 0, a, b; i < K; i++){
        cin >> a >> b;
        la[a].push_back(b);
        lb[b].push_back(a);
    }

    for (int i = 0; i < N; i++){
        memset(found, 0, sizeof found);

        for (int n : la[i]){
            for (int m : lb[n]){
                if (!found[m] && m != i){
                    found[m] = true;
                } else if (found[m]){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;
}
