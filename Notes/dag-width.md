## Partially Ordered Sets
[Wikipedia Link](https://en.wikipedia.org/wiki/Partially_ordered_set)

The width of the DAG is determined by getting the maximum number of nodes whose orders cannot be determined in the partially ordered set. (Largest antichain)

## Calculating Width
"What is the least number of paths that can cover the entire graph?"

### Bipartite Graph
**Definition:** A graph that can be split into 2 parts (L and R) where there is no vertices to connect any two nodes in the same part. 

**Checking**: DFS Coloring (Red, Black) without conflict

#### Maximum Bipartite Matching
Not unique. 

##### Method 1: Max Flow
[code](https://github.com/jimgao1/competitive-programming/blob/master/USACO/stall4.cpp)

##### Method 2: DFS

