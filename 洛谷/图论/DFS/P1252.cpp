#include <bits/stdc++.h>

void solve() {
	std::vector<std::array<int, 10>> v(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 10; j++)
			std::cin >> v[i][j];
	
	int ans = INT_MAX;
	std::vector<int> res;
	auto dfs = [&](this auto &&dfs, int i, int m, int t, std::vector<int> path) -> void {
		if (i >= 5) {
			if (m == 25 && t < ans) {
				ans = t;
				res = path;
			}
			return;
		}
		for (int j = 1; j <= 10; j++) {
			path.push_back(j);
			dfs(i + 1, m + j, t + v[i][j - 1], path);
			path.pop_back();
		}
	};
	
	dfs(0, 0, 0, {});
	
	std::cout << ans << '\n';
	for (int i = 0; i < 5; i++)
		std::cout << res[i] << " \n"[i == 4];
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}