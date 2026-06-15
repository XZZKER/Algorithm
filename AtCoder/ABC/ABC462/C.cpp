#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> y(n + 1);
	for (int i = 0; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		y[u] = v;
	}
	
	int pre = n + 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (y[i] < pre) {
			ans++;
			pre = y[i];
		}
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}