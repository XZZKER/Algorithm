#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> h(n);
	for (int i = 0; i < n; i++)
		std::cin >> h[i];
	
	std::vector<std::vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		int fa;
		std::cin >> fa;
		fa--;
		g[fa].push_back(i);
	}
	
	std::vector<int> w(n);
	for (int i = 1; i < n; i++)
		std::cin >> w[i];
	
	std::vector<int64> filled(n);
	auto dfs1 = [&](this auto &&dfs1, int u, int f) -> int64 {
		int64 tmp = h[u];
		for (int v : g[u]) {
			if (v == f)
				continue;
			tmp += dfs1(v, u);
		}
		return filled[u] = tmp;
	};
	
	dfs1(0, -1);
	
	for (int i = 0; i < n; i++) {
		std::sort(g[i].begin(), g[i].end(), [&](int x, int y) -> bool {
			return w[x] < w[y];
		});
	}
	
	std::vector<int64> base(n);
	auto dfs2 = [&](this auto &&dfs2, int u, int f) -> void {
		int64 tmp = 0;
		for (int v : g[u]) {
			base[v] = base[u] + tmp + w[v];
			tmp += filled[v];
			dfs2(v, u);
		}
	};
	
	dfs2(0, -1);
	
	std::vector<int64> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = base[i] + h[i];
		for (int v : g[i])
			ans[i] += filled[v];
	}
	
	for (int i = 0; i < n; i++)
		std::cout << ans[i] <<  " \n"[i == n - 1];
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}