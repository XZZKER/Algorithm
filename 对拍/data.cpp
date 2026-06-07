#include <bits/stdc++.h>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	
	int n = rng() % 10 + 1;
	std::cout << n << '\n';
	
	for (int i = 0; i < n; i++) {
		std::cout << rng() % 100 + 1 << ' ';
	}
	std::cout << '\n';
	
	return 0;
}