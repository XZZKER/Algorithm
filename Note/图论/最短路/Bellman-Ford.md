# Bellman-Ford

## 模板

### SPFA优化

正常最多更新n - 1次，节点更新次数>=n次，就表示有负环

``````c++
bool spfa(int n, std::vector<std::pair<int, int>> &g, int st) {
	std::vector<int> dis(n + 1, INT_MAX);
	dis[1] = 0;
	std::vector<bool> enter(n + 1);
	enter[1] = true;
	std::queue<int> q;
	q.push(1);
	std::vector<int> update(n + 1);
	update[1]++;
	
	while (q.size()) {
		int u = q.front();
		enter[u] = false;
		q.pop();
		for (auto &[v, w] : g[u]) {
			if (dis[u] + w >= dis[v])
				continue;
			dis[v] = dis[u] + w;
			if (!enter[v]) {
				enter[v] = true;
				q.push(v);
				if (++update[v] >= n) {
					return true;
				}
			}
		}
	}
    
    return false;
}
``````

## 题目

### 基础

1. [改造点](https://leetcode.cn/problems/cheapest-flights-within-k-stops)
2. [负环判断](https://www.luogu.com.cn/problem/P3385)