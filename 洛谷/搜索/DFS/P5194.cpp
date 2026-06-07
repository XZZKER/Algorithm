#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, c;
	std::cin >> n >> c;
	
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	std::vector<int64> s(n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	
	int64 ans = 0;
	auto dfs = [&](this auto &&dfs, int64 res, int st) -> void {
		if (res + s[st] <= c) {
			ans = std::max(ans, res + s[st]);
			return;
		}
		ans = std::max(ans, res);
		for (int i = st; i > 0; i--)
			if (res + a[i] <= c)
				dfs(res + a[i], i - 1);
	};
	
	dfs(0, n);
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}