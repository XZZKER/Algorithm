#include <bits/stdc++.h>

typedef long long int64;

const int64 mod = 998244353;

int64 qsm(int64 a, int64 n) {
	int64 res = 1;
	while (n) {
		if (n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int64> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	std::vector<std::array<int64, 2>> tree(n + 1);
	
	auto update = [&](int i, int64 v0, int64 v1)  {
		while (i <= n) {
			tree[i][0] = (tree[i][0] + v0) % mod;
			tree[i][1] = (tree[i][1] + v1) % mod;
			i += i & -i;
		}
	};
	
	auto pre = [&](int i) -> std::pair<int64, int64> {
		int64 res0 = 0, res1 = 0;
		while (i > 0) {
			res0 = (res0 + tree[i][0]) % mod;
			res1 = (res1 + tree[i][1]) % mod;
			i -= i & -i;
		}
		return {res0, res1};
	};
	
	auto query = [&](int i, int j) -> std::pair<int64, int64> {
		auto [p0, f0] = pre(i - 1);
		auto [p1, f1] = pre(j);
		return {((p1 - p0) % mod + mod) % mod, ((f1 - f0) % mod + mod) % mod};
	};
	
	for (int i = 1; i <= n; i++)
		update(i, a[i], a[i] * a[i] % mod);
	
	while (m--) {
		int64 op, i, j;
		std::cin >> op >> i >> j;
		if (op == 1) {
			auto [p, f] = query(i, j);
			int64 c = qsm(j - i + 1, mod - 2);
			std::cout << p * c % mod << ' ' << ((f - p * p % mod * c % mod) % mod + mod) % mod << '\n';
		}
		else {
			update(i, ((j - a[i]) % mod + mod) % mod, ((j * j % mod - a[i] * a[i] % mod) % mod + mod) % mod);
			a[i] = j;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}