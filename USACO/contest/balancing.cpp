
#include <bits/stdc++.h>

using namespace std;

int N, B, ans = 0x3f3f3f3f;
map<int, int> dx, dy;
vector<int> cx, cy;
vector<pair<int, int>> pos;

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    cin >> N >> B;
    for (int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        pos.push_back({x, y});
        cx.push_back(x);
        cy.push_back(y);
    }

    sort(cx.begin(), cx.end());
    cx.erase(unique(cx.begin(), cx.end()), cx.end());

    sort(cy.begin(), cy.end());
    cy.erase(unique(cy.begin(), cy.end()), cy.end());

    for (int i = 0; i < cx.size(); i++) dx[cx[i]] = i * 2;
    for (int i = 0; i < cy.size(); i++) dy[cy[i]] = i * 2;

    for (int i = 0; i < pos.size(); i++){
        pos[i].first = dx[pos[i].first];
        pos[i].second = dy[pos[i].second];
    }

    for (int i = 0; i < cx.size(); i++){
        for (int j = 0; j < cy.size(); j++){
            int wx = i * 2 + 1, wy = j * 2 + 1;
            int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

            for (int k = 0; k < pos.size(); k++){
                if (pos[k].first < wx){
                    if (pos[k].second < wy){
                        c1 ++;
                    } else {
                        c2 ++;
                    }
                } else {
                    if (pos[k].second < wy){
                        c3 ++;
                    } else {
                        c4 ++;
                    }
                }
            }

            ans = min(ans, max(max(c1, c2), max(c3, c4)));
        }
    }

    cout << ans << endl;
}

