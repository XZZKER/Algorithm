#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n;
	int64 m;
	std::cin >> n >> m;
	
	std::vector<int64> w(n);
	for (int i = 0; i < n; i++)
		std::cin >> w[i];
	
	std::vector<int64> res1, res2;
	auto dfs = [&](this auto &&dfs, auto &res, int i, int ed, int64 s) -> void {
		if (s > m)
			return;
		if (i == ed) {
			res.push_back(s);
			return;
		}
		dfs(res, i + 1, ed, s);
		dfs(res, i + 1, ed, s + w[i]);
	};
	
	dfs(res1, 0, n >> 1, 0);
	dfs(res2, n >> 1, n, 0);
	
	std::sort(res1.begin(), res1.end());
	std::sort(res2.begin(), res2.end());
	
	int64 ans = 0;
	for (int i = 0, j = res2.size() - 1; i < res1.size(); i++) {
		while (j >= 0 && res1[i] + res2[j] > m)
			j--;
		ans += j + 1;
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}