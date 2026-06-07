#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		if (a[x] != i)
			ok = false;
	}
	
	std::cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}