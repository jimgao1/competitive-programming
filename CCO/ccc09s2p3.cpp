
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, M, S, MA, G, T, matrix[101][101], duck[101];
int st[MAXN], mt[MAXN];
vector<int> stan, mario;

int main(){
    cin >> N >> M >> S >> MA >> G >> T;
    for (int i = 0, a, b, c; i < M; i++){
        cin >> a >> b >> c;
        a--, b--;
        matrix[a][b] = matrix[b][a] = c;
    }
    for (int i = 0, x; i < S; i++){
        cin >> x; stan.push_back(x - 1);
    }
    for (int i = 0, x; i < MA; i++){
        cin >> x; mario.push_back(x - 1);
    }
    for (int i = 0, x; i < G; i++){
        cin >> x; duck[x - 1] = true;
    }

    st[0] = 0;
    for (int i = 0; i < S - 1; i++){
        st[i + 1] = st[i] + matrix[stan[i]][stan[i + 1]];
        if (st[i + 1] > T) st[i + 1] = 1e5;
    }
    mt[0] = 0;
    for (int i = 0; i < MA - 1; i++){
        mt[i + 1] = mt[i] + matrix[mario[i]][mario[i + 1]];
        if (mt[i + 1] > T) mt[i + 1] = 1e5;
    }

    for (int i = 0; i < S; i++) {
        if (duck[stan[i]]) st[i] = 1e5;
        if (i > 0 && st[i - 1] == 1e5) st[i] = 1e5;
    }
    for (int i = 0; i < MA; i++) {
        if (duck[mario[i]]) mt[i] = 1e5;
        if (i > 0 && mt[i - 1] == 1e5) mt[i] = 1e5;
    }

    for (int i = 0; i < S; i++){
        for (int j = 0; j < MA; j++){
            if (stan[i] == mario[j] && st[i] == mt[j]){
                if (st[i] <= T && mt[i] <= T){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < S - 1; i++){
        for (int j = 0; j < MA - 1; j++){
            if (stan[i] == mario[j + 1] && stan[i + 1] == mario[j]){
                if ((T - st[i]) + (T - mt[j]) >= matrix[stan[i]][stan[j + 1]]){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < S - 1; i++){
        if (stan[i] == mario[MA - 1]){
            if (st[i] <= T && mt[MA - 1] <= T && mt[MA - 1] <= st[i]){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < MA - 1; i++){
        if (stan[S - 1] == mario[i]){
            if (st[S - 1] <= T && mt[i] <= T && st[S - 1] <= mt[i]){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    if (stan[S - 1] == mario[MA - 1]){
        if (st[S - 1] <= T && mt[MA - 1] <= T){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}

