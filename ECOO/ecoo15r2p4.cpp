
#include <bits/stdc++.h>

#define MAXN 40

using namespace std;

struct state{
    int x, y, used;
    state(){}
    state(int _, int __, int ___){
        x = _, y = __, used = ___;
        if (x > y) swap(x, y);
    }
};

bool operator< (const state& a, const state& b){
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.used < b.used;
}

int N;
set<state> rect[MAXN], done;
queue<state> q;

void doit(){
    done.clear();
    for (int i = 0; i < MAXN; i++) rect[i].clear();
    while(!q.empty()) q.pop();

    cin >> N;
    for (int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        state s(x, y, 1 << i);
        rect[x].insert(s); rect[y].insert(s);
        q.push(s);
    }

    int ans = -1;

    while(!q.empty()){
        state cur = q.front(); q.pop();
        if (cur.used == (1 << N) - 1){
            ans = max(ans, cur.x * 2 + cur.y * 2);
            continue;
        }

        if (done.count(cur)) continue;
        done.insert(cur);

        set<state> check;
        check.insert(rect[cur.x].begin(), rect[cur.x].end());
        check.insert(rect[cur.y].begin(), rect[cur.y].end());

        for (state s : check){
            if (s.used & cur.used) continue;

            for (int i = 0; i < 2; i++){
                if (s.x == cur.x){
                    state nxt(cur.x, cur.y + s.y, cur.used | s.used);
                    q.push(nxt);
                    rect[nxt.x].insert(nxt);
                    rect[nxt.y].insert(nxt);
                }

                if (s.y == cur.y){
                    state nxt(cur.x + s.x, cur.y, cur.used | s.used);
                    q.push(nxt);
                    rect[nxt.x].insert(nxt);
                    rect[nxt.y].insert(nxt);
                }

                swap(s.x, s.y);
            }
        }
    }

    if (ans == -1)
        printf("Not Possible\n");
    else
        printf("%d\n", ans);
}

int main(){
    //freopen("rectangle1.txt", "r", stdin);

    int T = 10;
    while(T--) doit();
}

