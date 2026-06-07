#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		int m;
		std::cin >> m;
		for (int j = 1; j <= m; j++) {
			int x;
			std::cin >> x;
			a[i].push_back(x);
		}
	}
	
	int x, y;
	std::cin >> x >> y;
	
	std::cout << a[x][y - 1] << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}