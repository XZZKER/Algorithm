#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int d, p, c, f;
	std::cin >> d >> p >> c >> f;
	
	std::vector<std::vector<int64>> dis(c + 1, std::vector<int64>(c + 1, LLONG_MAX));
	while (p--) {
		int a, b;
		std::cin >> a >> b;
		dis[a][b] = -d;
	}
	
	while (f--) {
		int j, k, t;
		std::cin >> j >> k >> t;
		dis[j][k] = std::min(dis[j][k], (int64)t - d);
	}
	
	for (int i = 1; i <= c; i++)
		dis[i][i] = 0;
	
	for (int m = 1; m <= c; m++) {
		for (int i = 1; i <= c; i++) {
			for (int j = 1; j <= c; j++) {
				if (dis[i][m] != LLONG_MAX && dis[m][j] != LLONG_MAX)
					dis[i][j] = std::min(dis[i][j], dis[i][m] + dis[m][j]);
			}
		}
	}
	
	for (int i = 1; i <= c; i++) {
		if (dis[i][i] < 0) {
			std::cout << "orz" << '\n';
			return;
		}
	}
	
	int64 ans = 0;
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= c; j++)
			if (dis[i][j] != LLONG_MAX)
				ans = std::max(ans, d - dis[i][j]);
			
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}