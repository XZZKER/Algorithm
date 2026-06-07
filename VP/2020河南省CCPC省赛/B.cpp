#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> p(n), d(n);
	for (int i = 0; i < n; i++)
		std::cin >> p[i];
	for (int i = 0; i < n; i++)
		std::cin >> d[i];
	
	std::set<int> want;
	std::vector<int64> dp(m + 1);
	want.insert(m);
	dp[m] = 0;
	for (int i = 0; i < n; i++) {
		auto ndp = dp;
		for (int c : want) {
			ndp[c / d[i]] = std::max(ndp[c / d[i]], dp[c] + 1LL * c * p[i]);
			want.insert(c / d[i]);
		}
		dp = ndp;
	}
	
	int64 ans = 0;
	for (int64 v : dp)
		ans = std::max(ans, v);
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}