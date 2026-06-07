#include <bits/stdc++.h>

void solve() {
	int n;
	long long k;
	std::cin >> n >> k;
	
	std::vector<std::vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		int m;
		std::cin >> m;
		for (int j = 0; j < m; j++) {
			int x;
			std::cin >> x;
			a[i].push_back(x);
		}
	}
	
	std::vector<int> c(n);
	for (int i = 0; i < n; i++)
		std::cin >> c[i];
	
	for (int i = 0; i < n; i++) {
		int len = a[i].size();
		if (k - 1LL * len * c[i] > 0) {
			k -= 1LL * len * c[i];
			continue;
		}
		std::cout << a[i][(k + len - 1) % len] << '\n';
		break;
	}
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}