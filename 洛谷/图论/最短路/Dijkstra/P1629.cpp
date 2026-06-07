#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<std::pair<int, int>>> g(n + 1), rg(n + 1);
	while (m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
		rg[v].push_back({u, w});
	}
	
	auto dijkstra = [](auto &g, auto &dis) -> void {
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
		dis[1] = 0;
		q.push({0, 1});
		
		while (q.size()) {
			auto [uDis, u] = q.top();
			q.pop();
			if (uDis > dis[u])
				continue;
			for (auto [v, w] : g[u]) {
				if (uDis + w < dis[v]) {
					dis[v] = uDis + w;
					q.push({dis[v], v});
				}
			}
		}
	};
	
	std::vector<int> dis(n + 1, INT_MAX), rdis(n + 1, INT_MAX);
	dijkstra(g, dis);
	dijkstra(rg, rdis);
	
	int64 ans = 0;
	for (int i = 2; i <= n; i++)
		ans += dis[i] + rdis[i];
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}