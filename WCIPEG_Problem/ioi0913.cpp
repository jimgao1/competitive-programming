
#include <bits/stdc++.h>

using namespace std;

struct c{
    int id, cnt, points;
    c(int a, int b, int c) { id = a, cnt = b, points = c; }
};

int N, T, P, score[2001], weight[2001];
bool solved[2001][2001];

vector<c> cont;
bool comp(c a, c b){
    if (a.points != b.points)
        return a.points > b.points;
    if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    return a.id < b.id;
}

int main(){
    scanf("%d%d%d", &N, &T, &P);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < T; j++){
            scanf("%d", &solved[i][j]);
        }
    }

    for (int i = 0; i < T; i++){
        weight[i] = N;
        for (int j = 0; j < N; j++)
            if (solved[j][i]) weight[i] --;
    }

    for (int i = 0; i < N; i++){
        int cnt = 0;
        for (int j = 0; j < T; j++){
            if (solved[i][j]){
                score[i] += weight[j];
                cnt++;
            }
        }

        cont.push_back(c(i, cnt, score[i]));

    }

    sort(cont.begin(), cont.end(), comp);

    for (int i = 0; i < cont.size(); i++){
        if (cont[i].id == P - 1){
            printf("%d %d\n", cont[i].points, i + 1);
            return 0;
        }
        //printf("%d\n", cont[i].id + 1);
    }
}
