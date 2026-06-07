#include <bits/stdc++.h>

void solve() {
	int n, m, t;
	std::cin >> n >> m >> t;
	
	std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, INT_MAX));
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	
	while (m--) {
		int s, e, h;
		std::cin >> s >> e >> h;
		dis[s][e] = std::min(dis[s][e], h);
	}
	
	std::vector<std::pair<int, int>> ab(t);
	for (auto &[a, b] : ab)
		std::cin >> a >> b;
	
	for (int m = 1; m <= n; m++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dis[i][m] != INT_MAX && dis[m][j] != INT_MAX)
					dis[i][j] = std::min(dis[i][j], std::max(dis[i][m], dis[m][j]));
	
	for (auto [a, b] : ab) {
		std::cout << (dis[a][b] == INT_MAX ? -1 : dis[a][b]) << '\n';
	}
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}