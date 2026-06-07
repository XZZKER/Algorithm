#include <bits/stdc++.h>

// 0N 1E 2S 3W
const std::vector<std::pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> mt(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> mt[i][j];
	
	auto is_valid = [&](int i, int j) -> bool {
		if (i == 0 || j == 0 || i == n || j == m)
			return false;
		if (i - 1 >= 0 && j - 1 >= 0 && mt[i - 1][j - 1] == 1)
			return false;
		if (i - 1 >= 0 && j < m && mt[i - 1][j] == 1)
			return false;
		if (i < n && j - 1 >= 0 && mt[i][j - 1] == 1)
			return false;
		if (i < n && j < m && mt[i][j] == 1)
			return false;
		return true;
	};
	
	int st_i, st_j, ed_i, ed_j;
	std::cin >> st_i >> st_j >> ed_i >> ed_j;
	
	char tmp;
	std::cin >> tmp;
	int direction = tmp == 'N' ? 0 : (tmp == 'E' ? 1 : (tmp == 'S' ? 2 : 3));
	
	if (!is_valid(st_i, st_j)) {
		std::cout << -1 << '\n';
		return;
	}
	
	std::vector<std::vector<std::vector<int>>> dis(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(4, INT_MAX)));
	std::queue<std::tuple<int, int, int>> q;
	
	dis[st_i][st_j][direction] = 0;
	q.push({st_i, st_j, direction});
	
	while (q.size()) {
		auto [i, j, d] = q.front();
		q.pop();
		if (i == ed_i && j == ed_j) {
			std::cout << dis[i][j][d] << '\n';
			return;
		}
		int nd = (d + 1) % 4;
		if (dis[i][j][nd] > dis[i][j][d] + 1) {
			dis[i][j][nd] = dis[i][j][d] + 1;
			q.push({i, j, nd});
		}
		nd = (d + 3) % 4;
		if (dis[i][j][nd] > dis[i][j][d] + 1) {
			dis[i][j][nd] = dis[i][j][d] + 1;
			q.push({i, j, nd});
		}
		for (int len = 1; len <= 3; len++) {
			int ni = i + dir[d].first * len, nj = j + dir[d].second * len;
			if (ni < 0 || ni > n || nj < 0 || nj > m || !is_valid(ni, nj))
				break;
			if (dis[ni][nj][d] > dis[i][j][d] + 1) {
				dis[ni][nj][d] = dis[i][j][d] + 1;
				q.push({ni, nj, d});
			}
		}
	}
	
	std::cout << -1 << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}