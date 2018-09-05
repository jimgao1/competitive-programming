/*
ID: jim_yub1
LANG: C++11
TASK: window
*/

#include <bits/stdc++.h>

#define MAXN 256
#define y1 lol

using namespace std;

struct rect {
    int a, b, c, d;
    rect(int _a, int _b, int _c, int _d) {
        a = _a, b = _b, c = _c, d = _d;
    }

    bool valid() {
        return a < c && b < d;
    }

    int area() {
        return (c - a) * (d - b);
    }
};

int head = 0, tail = 1, before[MAXN], after[MAXN];
int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];

void removeNode(int id) {
    after[before[id]] = after[id];
    before[after[id]] = before[id];
}

void addFirst(int id) {
    before[after[head]] = id;
    after[id] = after[head];
    after[head] = id;
    before[id] = head;
}

void addLast(int id) {
    after[before[tail]] = id;
    before[id] = before[tail];
    before[tail] = id;
    after[id] = tail;
}

int main() {
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);

    before[head] = head, after[head] = tail;
    before[tail] = head, after[tail] = tail;

    string line, token;
    vector<string> args;

    while (cin >> line) {
        args.clear();
        char cmd = line[0];

        istringstream ss(line.substr(2, line.length() - 3));
        while (getline(ss, token, ',')) args.push_back(token);

        int id = line[2];
        if (cmd == 'w') {
            int a = stoi(args[1]);
            int b = stoi(args[2]);
            int c = stoi(args[3]);
            int d = stoi(args[4]);

            x1[id] = min(a, c), y1[id] = min(b, d);
            x2[id] = max(a, c), y2[id] = max(b, d);

            addLast(id);
        } else if (cmd == 't') {
            removeNode(id);
            addLast(id);
        } else if (cmd == 'b') {
            removeNode(id);
            addFirst(id);
        } else if (cmd == 'd') {
            removeNode(id);
        } else {
            vector<rect> A, B;
            A.push_back(rect(x1[id], y1[id], x2[id], y2[id]));

            int cid = after[id];
            while (cid != tail) {
                B.clear();

                for (rect cur : A) {
                    B.push_back(rect(cur.a, cur.b, min(cur.c, x1[cid]), cur.d));
                    B.push_back(rect(max(cur.a, x1[cid]), cur.b, min(cur.c, x2[cid]), min(cur.d, y1[cid])));
                    B.push_back(rect(max(cur.a, x1[cid]), max(cur.b, y2[cid]), min(cur.c, x2[cid]), cur.d));
                    B.push_back(rect(max(cur.a, x2[cid]), cur.b, cur.c, cur.d));
                }

                A.clear();
                for (rect cur : B) {
                    if (cur.valid()) A.push_back(cur);
                }

                cid = after[cid];
            }

            double total = 0;
            for (rect cur : A) {
                total += cur.area();
            }

            printf("%.3f\n", total / rect(x1[id], y1[id], x2[id], y2[id]).area() * 100.0);
        }
    }
}
