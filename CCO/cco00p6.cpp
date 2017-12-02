
#include <bits/stdc++.h>

using namespace std;

int N, M, total = 0;
bool dp[500 * 10 + 1];
double X, Y;
vector<int> wires;
vector<pair<int, pair<double, double>>> outlets;

double dist(int i){
    double dx = outlets[i].second.first - X;
    double dy = outlets[i].second.second - Y;

    return sqrt(dx * dx + dy * dy);
}

void calc(){
    dp[0] = true;
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= 500 * 10; j++){
            if (dp[j] && j + wires[i] <= 500 * 10)
                dp[j + wires[i]] = true;
        }
    }
}

int main(){
    cin >> X >> Y >> N >> M;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        wires.push_back(x);
        total += x;
    }
    for (int i = 0; i < M; i++){
        double x, y;
        int circ;
        cin >> x >> y >> circ;

        outlets.push_back({circ, {x, y}});
    }

    calc();
    for (int i = 0; i < M; i++){
        for (int j = i + 1; j < M; j++){
            if (outlets[i].first == outlets[j].first) continue;

            int d1 = dist(i), d2 = dist(j);
            bool found = false;

            for (int i = min(d1, d2); i <= total - max(d1, d2); i++){
                if (dp[i]) found = true;
            }

            if (found){
                printf("Harry can connect to outlets at (%.1f, %.1f) and (%.1f, %.1f).\n",
                       outlets[i].second.first, outlets[i].second.second, outlets[j].second.first, outlets[j].second.second);
                return 0;
            }
        }
    }

    printf("Harry is helpless.\n");
}

