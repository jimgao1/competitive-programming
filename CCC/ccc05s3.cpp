
#include <bits/stdc++.h>

#define MAXN 2000

using namespace std;

int N;
pair<int, int> sa, sb, sans;
int na[MAXN][MAXN], nb[MAXN][MAXN], ans[MAXN][MAXN];

void multiply(){
    sans.first = sa.first * sb.first;
    sans.second = sa.second * sb.second;
    for (int i = 0; i < sa.first * sb.first; i++){
        for (int j = 0; j < sa.second * sb.second; j++){
            ans[i][j] = na[i / sb.first][j / sb.second] *
                        nb[i % sb.first][j % sb.second];
        }
    }
}

int main(){
    cin >> N;
    sa = {1, 1};
    na[0][0] = 1;

    for (int k = 0, r, c; k < N; k++){
        cin >> r >> c;
        sb = {r, c};
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> nb[i][j];
            }
        }
        multiply();
        sa = sans;
        for (int i = 0; i < sa.first; i++)
            for (int j = 0; j < sa.second; j++)
                na[i][j] = ans[i][j];
    }

    int ans1 = na[0][0], ans2 = na[0][0];
    for (int i = 0; i < sa.first; i++){
        for (int j = 0; j < sa.second; j++){
            ans1 = max(ans1, na[i][j]);
            ans2 = min(ans2, na[i][j]);
        }
    }
    printf("%d\n%d\n", ans1, ans2);

    int ans3 = -1e9, ans4 = 1e9;
    for (int i = 0; i < sa.first; i++){
        int tmp = 0;
        for (int j = 0; j < sa.second; j++){
            tmp += na[i][j];
        }
        ans3 = max(ans3, tmp);
        ans4 = min(ans4, tmp);
    }

    printf("%d\n%d\n", ans3, ans4);

    int ans5 = -1e9, ans6 = 1e9;
    for (int i = 0; i < sa.second; i++){
        int tmp = 0;
        for (int j = 0; j < sa.first; j++){
            tmp += na[j][i];
        }
        ans5 = max(ans5, tmp);
        ans6 = min(ans6, tmp);
    }

    printf("%d\n%d\n", ans5, ans6);
}
