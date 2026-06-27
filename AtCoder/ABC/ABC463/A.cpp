#include <bits/stdc++.h>

void solve() {
	int x, y;
	std::cin >> x >> y;
	
	std::cout << (x * 9 == y * 16 ? "Yes" : "No") << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}