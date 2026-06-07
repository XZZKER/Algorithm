#include <bits/stdc++.h>

const int mod = 1e5 + 3;

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> g(n + 1);
	while (m--) {
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	std::vector<int> dis(n + 1, INT_MAX), cnt(n + 1);
	std::queue<int> q;
	dis[1] = 0;
	cnt[1] = 1;
	q.push(1);
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (dis[v] == INT_MAX) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			}
			else if (dis[v] == dis[u] + 1)
				cnt[v] = (cnt[v] + cnt[u]) % mod;
		}
	}
	
	for (int i = 1; i <= n; i++)
		std::cout << cnt[i] << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}