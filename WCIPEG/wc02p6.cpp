
#include <bits/stdc++.h>

using namespace std;

int T, N;
double x, y, rate, rad;
vector<pair<double, double>> obs;

double dist(double x1, double y1, double x2, double y2){
    double dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    cin >> T;
    while(T--){
        obs.clear();
        cin >> N;
        for (int i = 0; i < N; i++){
            double a, b;
            cin >> a >> b;
            obs.push_back({a, b});
        }
        cin >> x >> y >> rate >> rad;

        double minrad = 1000000;
        for (int i = 0; i < N; i++){
            double penetration = dist(x, y, obs[i].first, obs[i].second);
            minrad = min(minrad, penetration);
        }

        if (minrad >= rad){
            printf("The monkeys need help!\n");
            continue;
        }

        vector<int> ids;
        for (int i = 0; i < N; i++){
            double penetration = dist(x, y, obs[i].first, obs[i].second);
            if (abs(penetration - minrad) <= 0.00001){
                ids.push_back(i);
            }
        }

        printf("%.3f\n", minrad / rate);
        for (int i = 0; i < ids.size(); i++){
            if (i != 0) printf(" ");
            printf("%d", ids[i] + 1);
        }
        printf("\n");
        printf("%.3f\n", minrad);
        printf("\n");
    }
}

