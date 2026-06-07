#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1, INT_MAX));
	std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, INT_MAX));
	while (m--) {
		int u, v, d;
		std::cin >> u >> v >> d;
		g[u][v] = std::min(g[u][v], d);
		g[v][u] = g[u][v];
		dis[u][v] = g[u][v];
		dis[v][u] = g[u][v];
	}
	
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	
	int ans = INT_MAX;
	for (int m = 1; m <= n; m++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && dis[i][j] != INT_MAX && g[i][m] != INT_MAX && g[m][j] != INT_MAX)
					ans = std::min(ans, dis[i][j] + g[i][m] + g[m][j]);
				if (dis[i][m] != INT_MAX && dis[m][j] != INT_MAX)
					dis[i][j] = std::min(dis[i][j], dis[i][m] + dis[m][j]);
			}
		}
	}			
	
	if (ans == INT_MAX)
		std::cout << "No solution." << '\n';
	else
		std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}