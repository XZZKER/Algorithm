#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	
	int ans = INT_MIN;
	for (int i = 0, pre = INT_MIN; i < n; i++) {
		pre = pre > 0 ? pre + a[i] : a[i];
		ans = std::max(ans, pre);
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}