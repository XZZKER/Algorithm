#include <bits/stdc++.h>

void solve() {
	int n, m, x;
	std::cin >> n >> m >> x;
	
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	std::map<int, int> pos;
	// pos[x] : x的最晚出现时的下标
	std::vector<int> dp(n + 1);
	// dp[i] : 前i个数能找到两个数异或和为x的左边那个数的下标的最大值
	// 若前i - 1能找到x ^ a[i], 那dp[i]为dp[i - 1]与pos[x ^ a[i]]的最大值, 否则为dp[i - 1]
	for (int i = 1; i <= n; i++) {
		int b = x ^ a[i];
		dp[i] = pos.count(b) ? std::max(dp[i - 1], pos[b]) : dp[i - 1];
		pos[a[i]] = i;
	}
	
	while (m--) {
		int l, r;
		std::cin >> l >> r;
		std::cout << (dp[r] >= l ? "yes" : "no") << '\n';
	}
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}