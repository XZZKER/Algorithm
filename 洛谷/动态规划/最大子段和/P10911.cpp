#include <bits/stdc++.h>

typedef long long int64;

int flip(int x) {
	int j = -1, tmp = 0;
	for (int i = 31; i >= 0; i--) {
		if (((x >> i) & 1) == 0)
			continue;
		if (j == -1)
			j = i;
		tmp += 1 << (j - i);
	}
	return tmp;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int64> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	std::vector<int64> delta(n + 1);
	for (int i = 1; i <= n; i++)
		delta[i] = flip(a[i]) - a[i];
	
	std::vector<std::vector<int64>> f(n + 1, std::vector<int64>(m + 1, LLONG_MIN));
	std::vector<std::vector<int64>> dp(n + 1, std::vector<int64>(m + 1, LLONG_MIN));
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= m && j <= i; j++) {
			f[i][j] = std::max(dp[i - 1][j - 1], f[i - 1][j]) + delta[i];
			dp[i][j] = std::max(dp[i - 1][j], f[i][j]);
		}
	}
	
	int64 res = 0;
	for (int j = 0; j <= m; j++)
		res = std::max(res, dp[n][j]);
	
	std::cout << std::reduce(a.begin(), a.end(), 0LL) + res << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}