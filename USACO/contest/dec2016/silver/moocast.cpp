#include <bits/stdc++.h>

#define MAXN 201

using namespace std;

int N, power[MAXN];
bool matrix[MAXN][MAXN];
vector<pair<double, double>> places;

double dist(int i, int j){
    double dx = places[i].first - places[j].first;
    double dy = places[i].second - places[j].second;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> N;
    for (int i = 0, a, b; i < N; i++){
        cin >> a >> b >> power[i];
        places.push_back({a, b});
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (dist(i, j) <= power[i]){
                matrix[i][j] = true;
            }
        }
    }

    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (matrix[i][k] && matrix[k][j])
                    matrix[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++){
        int tmp = 0;
        for (int j = 0; j < N; j++){
            if (matrix[i][j]) tmp++;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}

