//THE MOST FUCKING ANNOYING PROBLEM EVER

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct person{
    int id, score, curRank, worst;

    void print(){
        printf("id = %d, score = %d, curRank = %d, worst = %d\n", id, score, curRank, worst);
    }
};

bool cmp(person a, person b){
    if (a.score != b.score)
        return a.score > b.score;
    return a.id < b.id;
}

int N, K, sc[101];
vector<person> p;

int main(){
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++){
        person cur;
        cur.id = i, cur.score = 0, cur.curRank = 0, cur.worst = 0;
        p.push_back(cur);
    }

    for (int i = 0; i < K; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &sc[j]);
        }

        for (int j = 0; j < N; j++){
            p[j].score = p[j].score + sc[p[j].id];
            //printf("id = %d, score = %d\n", p[j].id, sc[p[j].id]);
        }

        sort(p.begin(), p.end(), cmp);

        int cnt = 0, prevScore = -1, prevRank = 0;
        for (int j = 0; j < N; j++){
            //p[j].print();

            if (p[j].score == prevScore){
                p[j].curRank = prevRank;
            } else {
                p[j].curRank = cnt;
                prevScore = p[j].score;
                prevRank = p[j].curRank;
            }

            p[j].worst = max(p[j].worst, p[j].curRank);

            cnt++;
        }
    }

    sort(p.begin(), p.end(), cmp);

    int maxScore = p[0].score;
    for (int i = 0; i < p.size(); i++){
        if (p[i].score < maxScore) break;

        printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n", p[i].id + 1, p[i].score, p[i].worst + 1);
    }
}
