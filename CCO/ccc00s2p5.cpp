
#include <bits/stdc++.h>

#define MAXN 101
#define INF 1e7

using namespace std;

int N;
double charge[MAXN];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> charge[i];

    double last = INF, cur = INF - 1;
    while(last != cur){
        last = cur;
        for (int i = 0; i < N; i++){
            int coef = charge[i] * 1.01 / cur;
            if (coef * cur < charge[i] * 0.99){
                cur = charge[i] * 1.01 / (double)(coef + 1);
            }
        }
    }

    printf("%.4f\n", cur);
}
