#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	int m;
	std::cin >> m;
	
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	while (m--) {
		int i, j, k;
		std::cin >> i >> j >> k;
		g[i].push_back({j, k});
		g[j].push_back({i, k});
	}
	
	int d;
	std::cin >> d;
	
	std::vector<std::vector<bool>> destroy(n + 1, std::vector<bool>(n + 1));
	while (d--) {
		int i, j;
		std::cin >> i >> j;
		destroy[i][j] = true;
		destroy[j][i] = true;
	}
	
	int a, b;
	std::cin >> a >> b;
	
	std::vector<int> dis(n + 1, INT_MAX);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
	dis[a] = 0;
	q.push({0, a});
	
	while (q.size()) {
		auto [uDis, u] = q.top();
		q.pop();
		if (uDis > dis[u])
			continue;
		if (u == b) {
			std::cout << uDis << '\n';
			return;
		}
		for (auto &[v, w] : g[u]) {
			w = destroy[u][v] ? w : 0;
			if (uDis + w < dis[v]) {
				dis[v] = uDis + w;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}