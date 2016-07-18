#include<bits/stdc++.h>

using namespace std;
#define x first
#define y second
typedef pair<double, double> pdd;

//negative turn right
//positive turn left
double cross(pdd O, pdd A, pdd B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<pdd> cHull(vector<pdd> P) {
    int k = 0;
    vector<pdd> H(2 * P.size());
    sort(P.begin(), P.end());
    for (int i = 0; i < P.size(); i++) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    //since last point is in the hull ignore it
    //dont destroy previous hull
    for (int i = P.size() - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

double area(vector<pdd> P) {

    double area = 0;
    int N = P.size();
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        area += P[i].x * P[j].y;
        area -= P[j].x * P[i].y;
    }
    area /= 2.0;
    return area;

}

int main() {
    int N;
    cin >> N;
    vector<pdd> points;

    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        points.push_back({a, b});
    }

    double total = 0;
    vector<pdd> res = cHull(points);

    for (int i = 0; i < points.size(); i++) {
        double dx = res[i].x - res[(i + 1) % N].x;
        double dy = res[i].y - res[(i + 1) % N].y;

        total += sqrt(dx * dx + dy + dy);
    }

    cout << floor(area(res) / 50.0) << endl;
}
