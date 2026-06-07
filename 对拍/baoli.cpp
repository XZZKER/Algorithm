#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		ans += x;
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}