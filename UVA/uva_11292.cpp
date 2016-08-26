
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> head, knight;

int main(){
    while(true){
        cin >> N >> M;

        if (N == 0 && M == 0) break;
        head.clear();
        knight.clear();

        for (int i = 0, x; i < N; i++){
            cin >> x;
            head.push_back(x);
        }
        for (int i = 0, x; i < M; i++){
            cin >> x;
            knight.push_back(x);
        }

        sort(head.begin(), head.end());
        sort(knight.begin(), knight.end());

        int idx = 0, ans = 0;
        bool doom = false;
        for (int i = 0; i < N; i++){
            while(true){
                if (idx >= knight.size()){
                    doom = true;
                    break;
                }

                if (knight[idx] >= head[i]){
                    ans += knight[idx];
                    break;
                }

                idx++;
            }
            idx++;
        }

        if (doom)
            cout << "Loowater is doomed!" << endl;
        else
            cout << ans << endl;

    }
}

