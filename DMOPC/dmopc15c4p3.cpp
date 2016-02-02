#include <bits/stdc++.h>

using namespace std;

inline bool getBit(int n, int bit) { return n & (1 << bit); }
inline int setBit(int n, int bit) { return n | (1 << bit); }

int T, N, hi, hm, attack[8];

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for (int i = 0; i < N; i++) scanf("%d", &attack[i]);
        cin >> hi >> hm;

        bool flag = false;
        for (int i = 0; i < (1 << N); i++){
            int s1 = 0, s2 = 0;
            for (int j = 0; j < N; j++){
                if (getBit(i, j))
                    s1 += attack[j];
                else
                    s2 += attack[j];
            }

            if (s1 >= hi && s2 >= hm) flag = true;
            if (s2 >= hi && s1 >= hm) flag = true;
        }

        if (flag)
            cout << "LETHAL" << endl;
        else
            cout << "NOT LETHAL" << endl;
    }
}
