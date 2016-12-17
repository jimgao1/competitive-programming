Lowest Common Ancestor
======

Declare an array with size `N` by `Log[N]`. Where `dp[a][i]` is the `2^i`th ancestor of node `a`.

When getting the `k`th parent of a node `n`, it is not necessary to count from the node. Instead, we can "jump" to one of the previous nodes. 

```cpp
	dp[N][K] = dp[ dp[U][K - 1] ][K - 1]
```
