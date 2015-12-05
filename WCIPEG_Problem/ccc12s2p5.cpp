
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> num;

int main(){
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);
        num.push_back(x);
    }

    sort(num.begin(), num.end());

    for (double i = 1; i <= 100; i += 1){
        bool flag = true;
        int curMul = 0;

        for (int n : num){
            if (!flag) break;

            while(true){
                if (round(curMul * 100.0 / i) == n) break;
                curMul++;

                if (round(curMul * 100.0 / i) - n > (100.0 / i)){
                    flag = false;
                    break;
                }
            }
        }

        if (flag){
            cout << (int)(i) << endl;
            return 0;
        }
    }
}
