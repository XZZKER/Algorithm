#include <bits/stdc++.h>

void solve() {
	std::vector<std::array<int, 10>> v(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 10; j++)
			std::cin >> v[i][j];
	
	std::vector<std::array<int, 9>> s(5);
	for (int i = 0; i < 5; i++)
		for (int j = 1; j < 10; j++)
			s[i][j - 1] = v[i][j] - v[i][j - 1];
	
	auto cmp = [&](auto &x, auto &y) -> bool {
		return s[x.first][x.second] > s[y.first][y.second];
	};
	
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q(cmp);
	for (int i = 0; i < 5; i++)
		q.push({i, 0});
	
	std::vector<int> path(5);
	for (int i = 1; i <= 20; i++) {
		auto [j, m] = q.top();
		q.pop();
		path[j]++;
		if (m + 1 < 9)
			q.push({j, m + 1});
	}
	
	int ans = 0;
	for (int i = 0; i < 5; i++)
		ans += v[i][path[i]];
	
	std::cout << ans << '\n';
	for (int i = 0; i < 5; i++)
		std::cout << path[i] + 1 << " \n"[i == 4];
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}