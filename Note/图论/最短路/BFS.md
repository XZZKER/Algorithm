# BFS

可以单源，也可多源

## 模板

### BFS

```c++
std::vector<int> bfs(std::vector<std::vector<int>> g, int st) {
	std::vector<int> dis(n, -1);
	std::queue<int> q;
	dis[st] = 0;
	q.push(st);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (dis[v] < 0) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis;
}
```

### 01BFS

由于只有两个权值，所以可以用双端队列替代dijkstra的优先队列

``````c++
std::vector<int> bfs01(int n, std::vector<std::vector<std::pair<int, int>>> g, int st) {
    std::vector<int> dis(n, INT_MAX);
    dis[st] = 0;
    deque<pair<int, int>> q;
    q.push_front(st);
    while (q.size()) {
        auto [u, uw] = q.front();
        q.pop_front();
        for (auto &[v, vw] : g[u]) {
            if (dis[u] >= dis[v] - vw)
                continue;
            dis[v] = dis[u] +vw;
            if (vw == 0)
                q.push_front({ni, nj});
            else
                q.push_back({ni, nj});
        }
    }
    return dis;
}
``````

## 题目

1. [多源+选好搜索反向，使只需一次搜索](https://leetcode.cn/problems/as-far-from-land-as-possible)
2. [建图+状态压缩](https://leetcode.cn/problems/stickers-to-spell-word)
3. [01BFS](https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner)
4. [01BFS](https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid)
5. [短板效应(小根堆)](https://leetcode.cn/problems/trapping-rain-water-ii)
6. [建图+回溯](https://leetcode.cn/problems/word-ladder-ii)

