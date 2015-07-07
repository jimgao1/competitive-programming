
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int dset[1000001], nodeCount, edgeCount;
vector<int> usedNodes;
vector<pair<int, int>> edges;
unordered_map<int, int> dict;

void build()
{
    for (int i = 0; i < 1000001; i++)
        dset[i] = i;
}

int ufind(int n)
{
    int root = n;

    while(root != dset[root])
        root = dset[root];

    while(root != n)
    {
        int temp = dset[n];
        dset[n] = root;
        n = temp;
    }

    return root;
}

void umerge(int a, int b)
{
    int ra = ufind(a), rb = ufind(b);
    dset[rb] = ra;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> nodeCount >> edgeCount;

    build();

    for (int i = 0; i < edgeCount; i++)
    {
        int ra, rb;
        cin >> ra >> rb;

        usedNodes.push_back(ra - 1);
        usedNodes.push_back(rb - 1);

        edges.push_back({ra - 1, rb - 1});
    }

    sort(usedNodes.begin(), usedNodes.end());
    usedNodes.erase(unique(usedNodes.begin(), usedNodes.end()), usedNodes.end());

    for (int i = 0; i < usedNodes.size(); i++){
        dict[usedNodes[i]] = i;
    }

    for (int i = 0; i < edgeCount; i++){
        int a = edges[i].first, b = edges[i].second;
        umerge(dict[a], dict[b]);
    }

    int c = 0;
    for (int i = 0; i < usedNodes.size(); i++)
    {
        if (dict[usedNodes[i]] == ufind(dict[usedNodes[i]])) c++;
    }

    cout << c + (nodeCount - usedNodes.size()) << endl;

    return 0;
}

