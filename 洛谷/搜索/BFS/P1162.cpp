#include <bits/stdc++.h>

const std::vector<std::pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> mt(n + 2, std::vector<int>(n + 2, 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> mt[i][j];
	
	std::queue<std::pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (mt[1][i] == 0)
			q.push({1, i});
		if (mt[i][1] == 0)
			q.push({i, 1});
		if (mt[n][i] == 0)
			q.push({n, i});
		if (mt[i][n] == 0)
			q.push({i, n});
	}
	
	while (q.size()) {
		auto [i, j] = q.front();
		q.pop();
		mt[i][j] = 2;
		for (auto &[di, dj] : dir) {
			int ni = i + di, nj = j + dj;
			if (mt[ni][nj] == 0)
				q.push({ni, nj});
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cout << (mt[i][j] == 0 ? 2 : (mt[i][j] == 1 ? 1 : 0)) << " \n"[j == n];
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}