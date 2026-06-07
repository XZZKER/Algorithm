#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int l, r, k;
	std::cin >> l >> r >> k;
	
	int64 n = r - l + 1;
	int64 t = n / k, u = n % k;
	
	std::cout << (k - u) * t * (t - 1) / 2 + u * (t + 1) * t / 2 << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}