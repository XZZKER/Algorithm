#include <bits/stdc++.h>

typedef long long int64;

template<typename T> class FenwickTree {
	std::vector<T> tree;
	
public:
	FenwickTree(int n) : tree(n + 1) {}
	
	void update(int i, T v) {
		while (i < (int)tree.size()) {
			tree[i] += v;
			i += i & -i;
		}
	}
	
	T pre(int i) {
		T res = 0;
		while (i > 0) {
			res += tree[i];
			i -= i & -i;
		}
		return res;
	}
};

void solve() {
	int n, q;
	std::cin >> n >> q;
	
	std::vector<int> row(n + 1), col(n + 1);
	FenwickTree<int64> rows(q + 2), cols(q + 2);
	
	rows.update(1, n);
	cols.update(1, n);
	
	int64 ans = 0;
	for (int i = 1; i <= q; i++) {
		int op, x;
		std::cin >> op >> x;
		if (op == 1) {
			int64 black = cols.pre(row[x]);
			ans += cols.pre(i) - black;
			rows.update(row[x] + 1, -1);
			row[x] = i;
			rows.update(i + 1, 1);
		} else {
			int64 black = n - rows.pre(col[x] + 1);
			ans -= black;
			cols.update(col[x] + 1, -1);
			col[x] = i;
			cols.update(i + 1, 1);
		}
		std::cout << ans << '\n';
	}
	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}