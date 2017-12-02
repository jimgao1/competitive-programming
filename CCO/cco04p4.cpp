
#include <bits/stdc++.h>

using namespace std;

pair<int, int> sa, sb;
vector<pair<int, int>> da, db;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }

double dist(pair<int, int> a, pair<int, int> b){
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    int A, B;
    cin >> sa.first >> sa.second >> A;
    for (int i = 0; i < A; i++){
        int n; char c;
        cin >> n >> c;
        for (int j = 0; j < abs(n); j++){
            if (c == 'X'){
                if (n < 0)
                    sa.first --;
                else
                    sa.first ++;
            } else {
                if (n < 0)
                    sa.second --;
                else
                    sa.second ++;
            }
            da.push_back(sa);
        }
    }
    cin >> sb.first >> sb.second >> B;
    for (int i = 0; i < B; i++){
        int n; char c;
        cin >> n >> c;
        for (int j = 0; j < abs(n); j++){
            if (c == 'X'){
                if (n < 0)
                    sb.first --;
                else
                    sb.first ++;
            } else {
                if (n < 0)
                    sb.second --;
                else
                    sb.second ++;
            }
            db.push_back(sb);
        }
    }

    double ans = 1e20;
    for (int i = 0; i < da.size() * db.size(); i++){
        ans = min(ans, dist(da[i % da.size()], db[i % db.size()]));
    }

    printf("%.2f\n", ans);
}

