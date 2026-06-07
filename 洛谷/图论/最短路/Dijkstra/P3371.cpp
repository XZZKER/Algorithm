#include <bits/stdc++.h>

void solve() {
	int n, m, s;
	std::cin >> n >> m >> s;
	
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	while (m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	
	std::vector<int> dis(n + 1, INT_MAX);
	dis[s] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
	q.push({0, s});
	
	while (q.size()) {
		auto [uDis, u] = q.top();
		q.pop();
		if (uDis > dis[u])
			continue;
		for (auto &[v, w] : g[u]) {
			if (uDis + w < dis[v]) {
				dis[v] = uDis + w;
				q.push({dis[v], v});
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		std::cout << dis[i] << " \n"[i == n];
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}