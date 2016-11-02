
#include <bits/stdc++.h>

#define pii pair<int, int>
#define MAXN 100001

using namespace std;

int N, freq[MAXN];
deque<pii> stalk;

int main(){
    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        freq[x] ++;
    }

    for (int i = 0; i < MAXN; i++){
        if (freq[i] != 0){
            stalk.push_back({i, freq[i]});
        }
    }

    sort(stalk.begin(), stalk.end());

    while(stalk.size() >= 3){
        pii a = stalk.front();
        pii b = stalk.back();
        stalk.pop_front();
        stalk.pop_back();

        if (a.second <= b.second){
            b.second -= a.second;
            stalk.front().second += a.second;
            stalk.back().second += a.second;

            if (stalk.size() == 1){
                printf("Mirko\n");
                stalk.push_back(b);
                printf("%d %d\n", stalk.front().first, stalk.back().first);
                return 0;
            }

            if (b.second > 0) stalk.push_back(b);
        } else {
            a.second -= b.second;
            stalk.front().second += b.second;
            stalk.back().second += b.second;

            stalk.push_front(a);
        }
    }

    printf("Slavko\n");
    printf("%d %d\n", stalk.front().first, stalk.back().first);

}


