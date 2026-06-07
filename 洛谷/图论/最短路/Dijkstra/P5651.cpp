#include <bits/stdc++.h>

void solve() {
	int n, m, p;
	std::cin >> n >> m >> p;
	
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	while (m--) {
		int x, y, v;
		std::cin >> x >> y >> v;
		g[x].push_back({y, v});
		g[y].push_back({x, v});
	}
	
	std::vector<std::pair<int, int>> xy(p);
	for (auto &[x, y] : xy)
		std::cin >> x >> y;
	
	std::vector<int> dis(n + 1, INT_MAX);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
	dis[1] = 0;
	q.push({0, 1});
	
	while (q.size()) {
		auto [uDis, u] = q.top();
		q.pop();
		if (uDis > dis[u])
			continue;
		for (auto [v, w] : g[u]) {
			if ((uDis ^ w) < dis[v]) {
				dis[v] = uDis ^ w;
				q.push({dis[v], v});
			}
		}
	}
	
	for (auto [x, y] : xy)
		std::cout << (dis[x] ^ dis[y]) << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}