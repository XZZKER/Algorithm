#include <bits/stdc++.h>

const std::vector<std::pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> c(n, std::vector<int>(n, -1));
	while (m--) {
		int i, j, color;
		std::cin >> i >> j >> color;
		c[i - 1][j - 1] = color;
	}
	
	std::vector<std::vector<std::vector<int>>> dis(n, std::vector<std::vector<int>>(n, std::vector<int>(3, INT_MAX)));
	std::priority_queue<std::tuple<int, int, int, int>, std::vector<std::tuple<int, int, int, int>>, std::greater<>> q;
	
	dis[0][0][2] = 0;
	q.push({0, 0, 0, 2});
	
	while (q.size()) {
		auto [d, i, j, st] = q.top();
		q.pop();
		if (d > dis[i][j][st])
			continue;
		if (i == n - 1 && j == n - 1) {
			std::cout << d << '\n';
			return;
		}
		for (auto [di, dj] : dir) {
			int ni = i + di, nj = j + dj;
			if (ni < 0 || ni >= n || nj < 0 || nj >= n)
				continue;
			if (st == 2) {
				int w = c[ni][nj] == -1 ? 2 : (c[i][j] == c[ni][nj] ? 0 : 1);
				int state = c[ni][nj] == -1 ? c[i][j] : 2;
				if (dis[ni][nj][state] > d + w) {
					dis[ni][nj][state] = d + w;
					q.push({dis[ni][nj][state], ni, nj, state});
				}
			}
			else {
				if (c[ni][nj] == -1)
					continue;
				int w = c[ni][nj] == st ? 0 : 1;
				if (dis[ni][nj][2] > d + w) {
					dis[ni][nj][2] = d + w;
					q.push({dis[ni][nj][2], ni, nj, 2});
				}
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