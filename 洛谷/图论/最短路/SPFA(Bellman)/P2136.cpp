#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	while (m--) {
		int s, t, w;
		std::cin >> s >> t >> w;
		g[s].push_back({t, -w});
	}
	
	auto spfa = [&](int s, int t) -> std::pair<int, bool> {
		std::vector<int> dis(n + 1, INT_MAX), cnt(n + 1);
		std::vector<bool> enter(n + 1);
		std::queue<int> q;
		dis[s] = 0;
		enter[s] = true;
		q.push(s);
		
		while (q.size()) {
			int u = q.front();
			q.pop();
			enter[u] = false;
			for (auto [v, w] : g[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					cnt[v] = cnt[u] + 1;
					if (cnt[v] >= n) {
						return {-1, true};
					}
					if (!enter[v]) {
						enter[v] = true;
						q.push(v);
					}
				}
			}
		}
		return {dis[t], false};
	};
	
	auto [res1, ok1] = spfa(1, n);
	auto [res2, ok2] = spfa(n, 1);
	
	if (ok1 || ok2)
		std::cout << "Forever love" << '\n';
	else
		std::cout << std::min(res1, res2) << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}