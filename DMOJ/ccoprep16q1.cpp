#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int T, N, M, height[MAXN];
char grid[MAXN][MAXN];

int solve(){
    deque<pair<int, int>> q;
    int ans = 0;

    for (int i = 0; i <= N; i++){
        int diff = 0;

        while(!q.empty() && height[i] < q.front().first){
            int tmp = q.front().first * (i - q.front().second);
            ans = max(ans, tmp);

            q.pop_front();
            diff++;
        }

        q.push_front({height[i], i - diff});
    }

    return ans;
}

int main(){
    cin >> T;
    while(T--){
        memset(height, 0, sizeof height);
        cin >> M >> N;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                cin >> grid[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] == 'R')
                    height[j] = 0;
                else
                    height[j] ++;
            }

            ans = max(ans, solve());
        }

        cout << ans * 3 << endl;
    }
}
