
#include <bits/stdc++.h>

#define MAXN 5001

using namespace std;

struct query{
    int x, y1, y2, val;
    query(int a, int b, int c, int d){
        x = a, y1 = b, y2 = c, val = d;
    }
};

bool cmp(query qa, query qb){
    if (qa.x == qb.x)
        return qa.val > qb.val;
    return qa.x < qb.x;
}

int N, sum[MAXN];
vector<query> hor, vert;
vector<int> xx, yy;

int main(){
    cin >> N;
    for (int i = 0, x1, y1, x2, y2; i < N; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        xx.push_back(x1); xx.push_back(x2);
        yy.push_back(y1); yy.push_back(y2);

        hor.push_back(query(y1, x1, x2, 1));
        hor.push_back(query(y2, x1, x2, -1));
        vert.push_back(query(x1, y1, y2, 1));
        vert.push_back(query(x2, y1, y2, -1));
    }

    sort(xx.begin(), xx.end()); xx.erase(unique(xx.begin(), xx.end()), xx.end());
    sort(yy.begin(), yy.end()); yy.erase(unique(yy.begin(), yy.end()), yy.end());

    sort(hor.begin(), hor.end(), cmp); sort(vert.begin(), vert.end(), cmp);

    int ans = 0;

    for (int i = 0; i < hor.size(); i++){
        int idx1 = lower_bound(xx.begin(), xx.end(), hor[i].y1) - xx.begin();
        int idx2 = lower_bound(xx.begin(), xx.end(), hor[i].y2) - xx.begin();

        for (int j = idx1 + 1; j <= idx2; j++){
            if (sum[j] == 0 || (sum[j] == 1 && hor[i].val == -1))
                ans += (xx[j] - xx[j - 1]);
            sum[j] += hor[i].val;
        }
    }

    memset(sum, 0, sizeof sum);

    for (int i = 0; i < vert.size(); i++){
        int idx1 = lower_bound(yy.begin(), yy.end(), vert[i].y1) - yy.begin();
        int idx2 = lower_bound(yy.begin(), yy.end(), vert[i].y2) - yy.begin();

        for (int j = idx1 + 1; j <= idx2; j++){
            if (sum[j] == 0 || (sum[j] == 1 && vert[i].val == -1))
                ans += (yy[j] - yy[j - 1]);
            sum[j] += vert[i].val;
        }
    }

    printf("%d\n", ans);
}

