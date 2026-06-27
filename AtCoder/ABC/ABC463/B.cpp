#include <bits/stdc++.h>

void solve() {
	int n;
	char x;
	std::cin >> n >> x;
	
	std::vector<std::string> s(n);
	for (auto &i : s)
		std::cin >> i;
	
	bool ok = false;
	for (auto i : s)
		ok |= i[x - 'A'] == 'o';
	
	std::cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}