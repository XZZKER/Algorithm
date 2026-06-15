#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> mp(n + 1);
	for (int i = 1; i <= n; i++) {
		int m;
		std::cin >> m;
		for (int j = 1; j <= m; j++) {
			int x;
			std::cin >> x;
			mp[x].push_back(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		std::cout << mp[i].size() << " \n"[mp[i].size() == 0];
		for (int j = 0; j < (int)mp[i].size(); j++)
			std::cout << mp[i][j] << " \n"[j == (int)mp[i].size() - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}