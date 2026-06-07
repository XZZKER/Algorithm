#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++)
		std::cin >> a[i];
	
	std::vector<std::vector<int>> d(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> d[i][j];
	
	for (int mid = 1; mid <= n; mid++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = std::min(d[i][j], d[i][mid] + d[mid][j]);
			}
		}
	}
	
	long long ans = 0;
	for (int i = 2; i <= m; i++) {
		ans += d[a[i - 1]][a[i]];
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}