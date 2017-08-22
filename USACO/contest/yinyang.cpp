
#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

using namespace std;

int N, parent[MAXN], treeSize[MAXN];
bool blocked[MAXN];
vector<pair<int, int>> adjList[MAXN];
queue<int> q;

int depthSeen[2 * MAXN], pathSat[2 * MAXN], pathUnsat[2 * MAXN];
vector<pair<int, bool>> paths;

void calcTreeSize(int cur, int par) {
    treeSize[cur] = 1;
    parent[cur] = par;
    for (pair<int, int> e : adjList[cur]) {
        if (e.first != par && !blocked[e.first]) {
            calcTreeSize(e.first, cur);
            treeSize[cur] += treeSize[e.first];
        }
    }
}

void findPaths(int cur, int pre, int sum) {
    paths.push_back(make_pair(sum, depthSeen[sum + MAXN] > 0));
    depthSeen[sum + MAXN]++;

    for (pair<int, int> e : adjList[cur]) {
        if (e.first != pre && !blocked[e.first]) {
            findPaths(e.first, cur, sum + e.second);
        }
    }

    depthSeen[sum + MAXN]--;
}

ll solveTree(int node, int compSize) {
    ll ans = 0;

    for (int i = -compSize + MAXN; i <= compSize + MAXN; i++) {
        pathSat[i] = 0;
        pathUnsat[i] = 0;
    }

    for (pair<int, int> e : adjList[node]) {
        if (!blocked[e.first]) {
            paths.clear();
            findPaths(e.first, node, e.second);

            for (pair<int, bool> p : paths) {
                if (p.second || p.first == 0) {
                    // If a rest stop has occurred, or can occur at the current node,
                    // this path can be paired with a unsatisfied path
                    ans += pathUnsat[MAXN - p.first];
                }
                // A satisfied path can pair with both a satisfied and an unsatisfied path
                ans += pathSat[MAXN - p.first];

                // Paths ending at the current node
                if (p.second && p.first == 0) ans ++;
            }

            for (pair<int, bool> p : paths) {
                if (p.second) {
                    pathSat[p.first + MAXN] ++;
                } else {
                    pathUnsat[p.first + MAXN] ++;
                }
            }
        }
    }

    return ans;
}

ll solve(int entryNode) {
    calcTreeSize(entryNode, -1);

    int centroid = entryNode, bestSize = treeSize[entryNode];
    int compSize = 0;

    // BFS through the current subtree to find a more optimal centroid
    q.push(entryNode);
    while (!q.empty()) {
        // Assuming the current node as the centroid
        int cur = q.front();
        q.pop();

        compSize++;

        // Size of the parent component, including the entryNode, but excluding the subtree rooted at cur
        int tmp = treeSize[entryNode] - treeSize[cur];

        for (pair<int, int> e : adjList[cur]) {
            if (e.first != parent[cur] && !blocked[e.first]) {
                tmp = max(tmp, treeSize[e.first]);
                q.push(e.first);
            }
        }

        // Replace centroid if cur is more optimal
        if (tmp < bestSize) {
            centroid = cur;
            bestSize = tmp;
        }
    }

    // Remove the centroid from the graph
    blocked[centroid] = true;

    // Finds the solution for the current tree
    ll ans = solveTree(centroid, compSize);

    // Find centroid in all connected components
    for (pair<int, int> e : adjList[centroid]) {
        if (!blocked[e.first]) {
            ans += solve(e.first);
        }
    }

    return ans;
}

int main() {
    freopen("yinyang.in", "r", stdin);
    freopen("yinyang.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0, a, b, type; i < N - 1; i++) {
        cin >> a >> b >> type;
        a--, b--, type = type * 2 - 1;

        adjList[a].push_back(make_pair(b, type));
        adjList[b].push_back(make_pair(a, type));
    }

    cout << solve(0) << "\n";
}
