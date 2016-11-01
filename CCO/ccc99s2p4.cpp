
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pdd pair<int, int>

double cross(pdd O, pdd A, pdd B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<pdd> cHull(vector<pdd> P){
    int k = 0;
    vector<pdd> H(2*P.size());
    sort(P.begin(), P.end());
    for(int i = 0; i < P.size(); i++){
        while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    //since last point is in the hull ignore it
    //dont destroy previous hull
    for(int i = P.size() - 2, t = k+1; i >= 0; i--){
        while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

double dist(pdd a, pdd b){
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int T, N;
vector<pdd> points;

int main(){
    cin >> T;
    while(T--){
        points.clear();
        cin >> N;
        for (int i = 0; i < N; i++){
            double x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        vector<pdd> hull = cHull(points);

        double total = 0;
        for (int i = 0; i < hull.size() - 1; i++){
            total += dist(hull[i], hull[i + 1]);
        }

        printf("%.2f\n", total);
    }
}

