#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	while (m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
		if (w >= 0)
			g[v].push_back({u, w});
	}
	
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
					std::cout << "YES" << '\n';
					return;
				}
			}
		}
	}
	
	std::cout << "NO" << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}