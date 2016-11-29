
#include <bits/stdc++.h>

using namespace std;

struct state{
    int steps = 0, stacks[9];

    state(){ memset(stacks, 0, sizeof stacks); }

    bool getBit(int i, int j) {
        return stacks[i] & (1 << j);
    }

    void setBit(int i, int j){
        stacks[i] = stacks[i] | (1 << j);
    }

    void unsetBit(int i, int j){
        stacks[i] = stacks[i] & (~(1 << j));
    }

    void toggleBit(int i, int j){
        stacks[i] = stacks[i] ^ (1 << j);
    }
};

int N;
set<string> visited;
queue<state> q;

string state_hash(state st){
    stringstream ss;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (st.getBit(i, j))
                ss << j;
        }
        ss << ",";
    }
    return ss.str();
}

int lastBit(int num){
    if (num == 0) return -1;
    return num & (-num);
}

int main(){
    while(true){
        cin >> N;
        if (N == 0) break;
        while(!q.empty()) q.pop();
        visited.clear();
        state init;
        init.steps = 0;
        for (int i = 0, x; i < N; i++){
            cin >> x;
            init.setBit(i, x - 1);
        }
        q.push(init);

        bool fuckshit = false;
        while(!q.empty()){
            state cur = q.front();
            q.pop();

            string sh = state_hash(cur);
            if (visited.find(sh) != visited.end()) continue;
            visited.insert(sh);

            bool flag = true;
            for (int i = 0; i < N; i++){
                if (!cur.getBit(i, i)){
                    flag = false;
                    break;
                }
            }

            if (flag){
                printf("%d\n", cur.steps);
                fuckshit = true;
                break;
            }

            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    if (i == j) continue;
                    if (abs(i - j) > 1) continue;
                    if (cur.stacks[i] == 0) continue;
                    int la = lastBit(cur.stacks[i]), lb = lastBit(cur.stacks[j]);
                    if (lb != -1 && lb < la) continue;

                    state next;
                    next.steps = cur.steps + 1;
                    for (int k = 0; k < N; k++)
                        next.stacks[k] = cur.stacks[k];

                    next.stacks[j] |= la;
                    next.stacks[i] &= (~la);

                    q.push(next);
                }
            }
        }

        if (!fuckshit) printf("IMPOSSIBLE\n");
    }
}
