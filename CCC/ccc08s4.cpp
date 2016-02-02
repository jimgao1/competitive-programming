
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int T, ans = 0;

int oper(int a, int b, int op){
    if (op == 0) return a + b;
    if (op == 1) return a - b;
    if (op == 2) return a * b;
    if (op == 3 && b != 0 && a % b == 0) return a / b;
    return INF;
}

void solve(vector<int> num){

    if (num.size() == 1){
        if (num[0] <= 24){
            ans = max(ans, num[0]);
        }
        return;
    }

    for (int i = 0; i < num.size(); i++){
        for (int j = 0; j < num.size(); j++){
            if (i == j) continue;

            for (int k = 0; k < 4; k++){
                if (k == 3 && (j == 0 || i % j != 0)) continue;

                vector<int> next;
                for (int l = 0; l < num.size(); l++)
                    if (l != i && l != j)
                        next.push_back(num[l]);

                next.push_back(oper(num[i], num[j], k));

                solve(next);
            }
        }
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        ans = 0;

        vector<int> num;
        for (int i = 0, x; i < 4; i++){
            scanf("%d", &x);
            num.push_back(x);
        }
        solve(num);

        printf("%d\n", ans);
    }
}
