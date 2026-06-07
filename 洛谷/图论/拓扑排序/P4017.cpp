#include <bits/stdc++.h>

typedef long long int64;

const int mod = 80112002;

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
	
	std::queue<int> q;
	std::vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		if (pre[i] == 0) {
			q.push(i);
			dp[i] = 1;
		}
	}
			
	int64 ans = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		if (g[u].size() == 0)
			ans = (ans + dp[u]) % mod;
		for (int v : g[u]) {
			if (--pre[v] == 0)
				q.push(v);
			dp[v] = (dp[v] + dp[u]) % mod;
		}
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}