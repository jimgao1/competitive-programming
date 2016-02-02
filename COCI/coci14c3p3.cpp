
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

struct segment{
    int l, r, val;
    segment(int a, int b, int c){
        l = a, r = b, val = c;
    }
};

int mHeight = 0, mWidth = 0, leftIdx = INF, per = 0;
int N, L[10001], R[10001], H[10001], height[1001];
bool ans[1001][1001];

vector<segment> seg;

bool cmp(segment a, segment b){
    return a.l < b.l;
}

int main(){
    memset(ans, 0, sizeof ans);
    memset(height, 0, sizeof height);

    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d%d%d", &L[i], &R[i], &H[i]);
        R[i] -= 1;

        mHeight = max(mHeight, H[i]);
        leftIdx = min(leftIdx, L[i]);
        mWidth = max(mWidth, R[i]);
        seg.push_back(segment(L[i], R[i], H[i]));
    }

    sort(seg.begin(), seg.end(), cmp);

    for (int i = 1; i <= 1000; i++){
        bool flag = false;

        for (segment j : seg){
            if (j.l > i) break;
            if (i >= j.l && i <= j.r){
                height[i] = max(height[i], j.val);
            }
        }

        if (height[i] != 0)
            per += abs(height[i] - height[i - 1]) + 1;
        else
            per += abs(height[i] - height[i - 1]);

        for (int j = min(height[i], height[i - 1]); j <= max(height[i], height[i - 1]); j++){
            if (height[i] >= height[i - 1])
                ans[i][j] = true;
            else
                ans[i - 1][j] = true;
        }

        ans[i][height[i]] = true;
    }

    for (int i = 1; i <= 1000; i++){
        if (height[i] == 0)
            ans[i][0] = false;
    }

    printf("%d\n", per);

    for (int i = mHeight; i >= 1; i--){
        for (int j = leftIdx; j <= mWidth; j++){
            if (ans[j][i])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }

    for (int i = leftIdx; i <= mWidth; i++)
        printf("*");
    printf("\n");

}
