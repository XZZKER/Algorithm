#include <bits/stdc++.h>

void solve() {
	std::string s;
	std::cin >> s;
	
	std::cout << (s == "awdec" ? "Fantasy_Blue" : (s == "Fantasy_Blue" ? "awdec" : "other"));
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}