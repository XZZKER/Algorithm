#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::array<int, 3>> uvc(m);
	for (int i = 0; i < m; i++) {
		std::cin >> uvc[i][0] >> uvc[i][1] >> uvc[i][2];
		uvc[i][0]--;
		uvc[i][1]--;
	}
	sort(uvc.begin(), uvc.end(), [](auto &x, auto &y) -> bool {
		return x[2] < y[2];
	});
	
	std::vector<int> pa(n);
	std::iota(pa.begin(), pa.end(), 0);
	
	auto find = [&](this auto &&find, int i) -> int {
		return pa[i] == i ? i : (pa[i] = find(pa[i]));
	};
	
	auto merge = [&](int i, int j) -> void {
		int x = find(i), y = find(j);
		if (x == y)
			return;
		pa[x] = y;
	};
	
	int ans = 0;
	for (auto &e : uvc) {
		if (find(e[0]) != find(e[1])) {
			ans = e[2];
			merge(e[0], e[1]);
		}
	}
	
	std::cout << n - 1 << ' ' << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}