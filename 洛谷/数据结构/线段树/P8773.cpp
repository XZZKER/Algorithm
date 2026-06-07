#include <bits/stdc++.h>

void solve() {
	int n, m, x;
	std::cin >> n >> m >> x;
	
	std::vector<int> a(n);
	for (int &i : a)
		std::cin >> i;
	
	std::map<int, int> pos;
	std::vector<int> finally(n);
	for (int i = 0; i < n; i++) {
		pos[a[i]] = i + 1;
		if (pos.count(a[i] ^ x))
			finally[i] = pos[a[i] ^ x];
	}
	
	std::vector<int> tree(n * 4);
	auto build = [&](this auto &&build, int node, int l, int r) -> void {
		if (l == r) {
			tree[node] = finally[l];
			return;
		}
		int m = (l + r) >> 1;
		build(node * 2, l, m);
		build(node * 2 + 1, m + 1, r);
		tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
	};
	
	auto query = [&](this auto &&query, int node, int ql, int qr, int l, int r) -> int {
		if (ql <= l && r <= qr)
			return tree[node];
		int m = (l + r) >> 1;
		if (ql > m)
			return query(node * 2 + 1, ql, qr, m + 1, r);
		if (qr <= m)
			return query(node * 2, ql, qr, l, m);
		return std::max(query(node * 2, ql, qr, l, m), query(node * 2 + 1, ql, qr, m + 1, r));
	};
	
	build(1, 0, n - 1);
	
	while (m--) {
		int l, r;
		std::cin >> l >> r;
		std::cout << (query(1, l - 1, r - 1, 0, n - 1) >= l ? "yes" : "no") << '\n';
	}
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}