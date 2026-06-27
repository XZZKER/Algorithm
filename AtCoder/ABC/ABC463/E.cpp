#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, m, y;
	std::cin >> n >> m >> y;
	
	std::vector<std::vector<std::pair<int, int64>>> g(n + 1);
	while (m--) {
		int u, v, t;
		std::cin >> u >> v >> t;
		g[u].push_back({v, t});
		g[v].push_back({u, t});
	}
	
	for (int i = 1; i <= n; i++) {
		int64 x;
		std::cin >> x;
		g[0].push_back({i, x});
		g[i].push_back({0, x + y});
	}
	
	std::vector<int64> dis(n + 1, LLONG_MAX);
	std::priority_queue<std::pair<int64, int>, std::vector<std::pair<int64, int>>, std::greater<>> q;
	dis[1] = 0;
	q.push({0, 1});
	
	while (q.size()) {
		auto [uDis, u] = q.top();
		q.pop();
		if (uDis > dis[u])
			continue;
		for (auto [v, w] : g[u]) {
			if (dis[v] > uDis + w) {
				dis[v] = uDis + w;
				q.push({dis[v], v});
			}
		}
	}
	
	for (int i = 2; i <= n; i++)
		std::cout << dis[i] << " \n"[i == n];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}