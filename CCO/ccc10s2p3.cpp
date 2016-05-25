//Thanks Jeffrey Xiao


#include <bits/stdc++.h>

#define MAXN 1000001

using namespace std;

struct command{
    char cmd;
    int a, b;
    command(char cc, int ca, int cb){
        cmd = cc, a = ca, b = cb;
    }
};

int N, bit[MAXN], idToRating[MAXN], ratingToId[MAXN];
unordered_map<int, int> dictid, dictrating, revid;
vector<command> cmds;
vector<int> ids, ratings;

void add(int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        i += (i & -i);
    }
}

int sum(int i){
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        char cmd;
        int a, b;
        cin >> cmd;
        if (cmd == 'N' || cmd == 'M'){
            cin >> a >> b;
            cmds.push_back(command(cmd, a, b));
            ids.push_back(a);
            ratings.push_back(b);
        } else {
            cin >> a;
            cmds.push_back(command(cmd, a, 69));
        }
    }

    sort(ids.begin(), ids.end());
    sort(ratings.begin(), ratings.end());

    int cid = 1;
    for (int i = 0; i < ids.size(); i++){
        dictid[ids[i]] = cid;
        revid[cid] = ids[i];
        cid++;
    }

    cid = 1;
    for (int i = 0; i < ratings.size(); i++){
        dictrating[ratings[i]] = cid++;
    }

    int pcnt = 0;

    for (command cc : cmds){
        if (cc.cmd == 'N'){
            idToRating[dictid[cc.a]] = dictrating[cc.b];
            ratingToId[dictrating[cc.b]] = dictid[cc.a];
            add(idToRating[dictid[cc.a]], 1);
            pcnt++;
        } else if (cc.cmd == 'M'){
            int prevId = dictid[cc.a];
            add(idToRating[prevId], -1);
            idToRating[prevId] = dictrating[cc.b];
            ratingToId[dictrating[cc.b]] = prevId;
            add(idToRating[prevId], 1);
        } else {
            int low = 1, high = ratings.size();

            while(low <= high){
                //printf("low = %d, high = %d\n", low, high);

                int mid = (low + high) / 2;
                if (sum(mid) > pcnt - cc.a){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            cout << revid[ratingToId[low]] << "\n";
        }
    }
}
