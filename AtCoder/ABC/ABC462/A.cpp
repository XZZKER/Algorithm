#include <bits/stdc++.h>

void solve() {
	std::string s;
	std::cin >> s;
	
	std::string ans;
	for (char c : s)
		if ('0' <= c && c <= '9')
			ans += c;
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}