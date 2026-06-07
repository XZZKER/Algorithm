#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, m, v;
	std::cin >> n >> m >> v;
	
	std::vector<std::string> mt(n);
	for (int i = 0; i < n; i++)
		std::cin >> mt[i];
	
	std::vector<std::vector<int>> s(n + 1, std::vector<int>(m + 1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + mt[i][j] - '0';
	
	int64 ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			std::map<int, int> cnt;
			for (int k = 0; k <= m; k++) {
				int tmp = s[j][k] - s[i - 1][k];
				if (cnt.count(tmp - v))
					ans += cnt[tmp - v];
				cnt[tmp]++;
			}
		}
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}