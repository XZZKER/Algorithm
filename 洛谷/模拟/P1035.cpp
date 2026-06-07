#include <bits/stdc++.h>

void solve() {
	int k;
	std::cin >> k;
	
	int n = 0;
	double s = 0;
	while (s <= k) {
		s += 1.0 / ++n;
	}
	
	std::cout << n << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}