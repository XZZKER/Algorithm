#include <bits/stdc++.h>

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	
	int s, t;
	std::cin >> s >> t;
	
	std::vector<std::vector<std::pair<int, int>>> g(n);
	while (m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	std::vector<std::vector<int>> money(n, std::vector<int>(k + 1, INT_MAX));
	std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> q;
	money[s][0] = 0;
	q.push({0, s, 0});
	
	while (q.size()) {
		auto [uMoney, u, uFree] = q.top();
		q.pop();
		if (uMoney > money[u][uFree])
			continue;
		if (u == t) {
			std::cout << uMoney << '\n';
			return;
		}
		for (auto &[v, need] : g[u]) {
			if (uFree < k) {
				int vFree = uFree + 1;
				if (money[u][uFree] < money[v][vFree]) {
					money[v][vFree] = uMoney;
					q.push({uMoney, v, vFree});
				}
			}
			int vMoney = uMoney + need;
			if (vMoney < money[v][uFree]) {
				money[v][uFree] = vMoney;
				q.push({vMoney, v, uFree});
			}
		}
	}
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}