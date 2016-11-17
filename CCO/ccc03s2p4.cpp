
#include <bits/stdc++.h>

using namespace std;

int N, K, idx[11];
vector<pair<int, int>> cons;

int main(){
    cin >> N >> K;
    for (int i = 0, a, b; i < K; i++){
        cin >> a >> b;
        cons.push_back({a, b});
    }
    string str = string("123456789").substr(0, N);

    int cnt = 0;
    do{
        for (int i = 0; i < N; i++){
            idx[str[i] - '0'] = i;
        }

        bool flag = true;

        for (pair<int, int> i : cons){
            if (idx[i.first] > idx[i.second]){
                flag = false;
                break;
            }
        }

        if (flag) cnt++;
    } while(next_permutation(str.begin(), str.end()));

    cout << cnt << endl;
}

