#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> g(n + 1);
	std::vector<int> pre(n + 1);
	while (m--) {
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		pre[v]++;
	}
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for (int i = 1; i <= n; i++)
		if (pre[i] == 0)
			q.push(i);
	
	std::vector<int> topo;
	while (q.size()) {
		int u = q.top();
		q.pop();
		topo.push_back(u);
		for (int v : g[u]) {
			if (--pre[v] == 0)
				q.push(v);
		}
	}
	
	for (int i = 0; i < n; i++)
		std::cout << topo[i] << " \n"[i == n - 1];
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}