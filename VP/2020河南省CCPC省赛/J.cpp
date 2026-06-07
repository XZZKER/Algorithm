#include <bits/stdc++.h>

typedef long long int64;

const int MOD = 998244353;

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	std::vector<std::vector<int>> pa(25, std::vector<int>(n + 2));
	auto find_next = [&](this auto &&find_next, int bit, int i) -> int {
		return pa[bit][i] == i ? i : (pa[bit][i] = find_next(bit, pa[bit][i]));
	};
	
	for (int bit = 0; bit < 25; bit++) {
		std::iota(pa[bit].begin(), pa[bit].end(), 0);
		for (int i = 1; i <= n; i++)
			if (((a[i] >> bit) & 1) == 0)
				pa[bit][i] = i + 1;
	}
	
	std::vector<int64> tree(n + 1);
	auto update = [&](int i, int64 v) -> void {
		while (i < tree.size()) {
			tree[i] += v;
			i += i & -i;
		}
	};
	
	auto pre = [&](int i) -> int64 {
		int64 tmp = 0;
		while (i > 0) {
			tmp += tree[i];
			i -= i & -i;
		}
		return tmp;
	};
	
	for (int i = 1; i <= n; i++) {
		int64 tmp = 1LL * a[i] * a[i] % MOD;
		update(i, tmp);
	}
	
	int q;
	std::cin >> q;
	
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			for (int bit = 0; bit < 25; bit++) {
				if (((x >> bit) & 1) == 1)
					continue;
				int pos = find_next(bit, l);
				while (pos <= r) {
					int64 tmp = 1LL * a[pos] * a[pos] % MOD;
					a[pos] -= 1 << bit;
					tmp = (((1LL * a[pos] * a[pos]) % MOD) - tmp + MOD) % MOD;
					update(pos, tmp);
					pa[bit][pos] = pos + 1;
					pos = find_next(bit, pos);
				}
			}
		}
		else {
			int l, r;
			std::cin >> l >> r;
			std::cout << (pre(r) - pre(l - 1) + MOD) % MOD << '\n';
		}
	}
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}