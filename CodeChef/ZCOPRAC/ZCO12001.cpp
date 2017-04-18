
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, nums[MAXN], match[MAXN], depth = 0;

int main(){
    cin >> N;
    int ans1 = 0, ans2 = -1, ans3 = 0, ans4 = -1;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];

        if (nums[i] == 1){
            depth++;
            match[depth] = i;

            if (depth > ans1){
                ans1 = depth;
                ans2 = i;
            }
        } else {
            int len = i - match[depth] + 1;
            if (len > ans3){
                ans3 = len;
                ans4 = match[depth];
            }

            depth--;
        }
    }

    printf("%d %d %d %d\n", ans1, ans2 + 1, ans3, ans4 + 1);
}

