Lowest Common Ancestor
======

Declare an array with size `N` by `Log[N]`. Where `dp[a][i]` is the `2^i`th ancestor of node `a`.

When getting the `k`th parent of a node `n`, it is not necessary to count from the node. Instead, we can "jump" to one of the previous nodes. 

```cpp
	dp[N][K] = dp[ dp[U][K - 1] ][K - 1]
```

When finding the LCA of 2 nodes `u` and `v`, we first need to find the node with the greater depth. Let `depth[u]` indicate the depth of the node `u`. The goal is to get the two nodes `u` and `v` onto the same depth.

#### Step 1: Calculating Depth
```cpp
int depth[MAXN];

void dfs(int cur, int prev){
	for (int i : adjList[cur]){
		if (i != prev){
			depth[i] = depth[cur] + 1;
			dfs(i, cur);
		}
	}
}
```

#### Step 2: Building the `dp` array
```cpp
int dp[MAXN][LOG_MAXN];

void build(){
	for (int i = 1; i < LOG_MAXN; i++){
		for (int j = 0; j < N; j++){
			if (dp[j][i - 1] != -1){
				dp[j][i] = dp[ dp[j][i - 1] ][i - 1];
			}
		}
	}
}
```

After that, we can simply loop through the `dp` array with a decreasing depth. The last pair of equivalent nodes in this process is the lowest common ancestor. 

