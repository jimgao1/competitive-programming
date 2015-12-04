
#include <bits/stdc++.h>

using namespace std;

int N;
double ans = 0;
vector<pair<double, double>> points;

double dist(pair<double, double> p1, pair<double, double> p2){
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;

    return sqrt(dx * dx + dy * dy);
}

int main(){
    scanf("%d", &N);
    for (int i = 0, a, b; i < N; i++){
        scanf("%d%d", &a, &b);
        points.push_back({a, b});
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                double d1 = dist(points[i], points[j]);
                double d2 = dist(points[j], points[k]);
                double d3 = dist(points[k], points[i]);

                if ((d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1) || true){
                    if ((d1 * d1 + d2 * d2 < d3 * d3) ||
                        (d2 * d2 + d3 * d3 < d1 * d1) ||
                        (d1 * d1 + d3 * d3 < d2 * d2)) {

                        ans = max(ans, max(d1, max(d2, d3)));
                    } else {

                        double s = (d1 + d2 + d3) / 2;
                        double r = 2 * (d1 * d2 * d3) / (4 * sqrt (s * (s - d1) * (s - d2) * (s - d3)));

                        ans = max(ans, r);
                    }
                }
            }
        }
    }

    printf("%.2f\n", round(ans * 100) / 100.0);
}
