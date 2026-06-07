#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	int x;
	std::cin >> x;
	
	std::cout << a[x] << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}