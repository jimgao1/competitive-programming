
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, H, cnt[MAXN], pos = 0;
bool pick = false;

int main(){
    cin >> N >> H;
    for (int i = 0; i < N; i++) cin >> cnt[i];

    while(true){
        int cmd; cin >> cmd;

        if (cmd == 1){
            pos = max(0, pos - 1);
        } else if (cmd == 2){
            pos = min(N - 1, pos + 1);
        } else if (cmd == 3){
            if (!pick && cnt[pos] > 0){
                pick = true;
                cnt[pos] --;
            }
        } else if (cmd == 4){
            if (pick && cnt[pos] + 1 <= H){
                pick = false;
                cnt[pos] ++;
            }
        } else {
            break;
        }
    }

    for (int i = 0; i < N; i++) printf("%d ", cnt[i]);
    printf("\n");
}

