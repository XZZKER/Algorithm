#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<std::pair<int, int>> pos(n);
	for (auto &[x, y] : pos)
		std::cin >> x >> y;
	
	auto getDis = [&](int i, int j) -> double {
		double x = pos[i].first - pos[j].first, y = pos[i].second - pos[j].second;
		return std::sqrt(x * x + y * y);
	};
	
	int m;
	std::cin >> m;
	
	std::vector<std::vector<int>> g(n);
	while (m--) {
		int i, j;
		std::cin >> i >> j;
		i--, j--;
		g[i].push_back(j);
		g[j].push_back(i);
	}
	
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	
	std::vector<double> dis(n, -1);
	std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> q;
	dis[s] = 0;
	q.push({0, s});
	
	while (q.size()) {
		auto [uDis, u] = q.top();
		q.pop();
		if (uDis > dis[u])
			continue;
		if (u == t) {
			std::cout << std::fixed << std::setprecision(2) << uDis << '\n';
			return;
		}
		for (int v : g[u]) {
			double w = getDis(u, v);
			if (dis[v] == -1 || uDis + w < dis[v]) {
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