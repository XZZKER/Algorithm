#include <bits/stdc++.h>

typedef long long int64;

const int mod = 10007;

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int64> num(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> num[i];
	
	std::vector<std::vector<std::vector<int>>> arr(m + 1, std::vector<std::vector<int>>(2));
	for (int i = 1; i <= n; i++) {
		int c;
		std::cin >> c;
		arr[c][i % 2].push_back(i);
	}
	
	int64 ans = 0;
	for (int c = 1; c <= m; c++) {
		for (int jo = 0; jo <= 1; jo++) {
			int len = arr[c][jo].size();
			if (len <= 1)
				continue;
			int64 s1 = arr[c][jo][0] % mod, s2 = num[arr[c][jo][0]] % mod, s3 = s1 * s2 % mod;
			for (int i = 1; i < len; i++) {
				int64 tmp1 = num[arr[c][jo][i]] * s1 % mod;
				int64 tmp2 = arr[c][jo][i] * s2 % mod;
				int64 tmp3 = arr[c][jo][i] * num[arr[c][jo][i]] * i % mod;
				ans = (ans + tmp1 + tmp2 + s3 + tmp3) % mod;
				s1 = (s1 + arr[c][jo][i]) % mod, s2 = (s2 + num[arr[c][jo][i]]) % mod;
				s3 = (s3 + arr[c][jo][i] * num[arr[c][jo][i]]) % mod;
			}
		}
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}