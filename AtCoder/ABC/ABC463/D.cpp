#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<std::pair<int, int>> rl(n);
	for (auto &[r, l] : rl)
		std::cin >> l >> r;
	
	std::sort(rl.begin(), rl.end());
	
	auto check = [&](int m) -> bool {
		int cnt = 1, lst = rl[0].first;
		for (int i = 1; i < n; i++) {
			if (rl[i].second < lst + m)
				continue;
			cnt++;
			lst = rl[i].first;
		}
		return cnt >= k;
	};
	
	int l = 0, r = 1e9 + 1;
	while (l + 1 < r) {
		int m = (r - l) / 2 + l;
		if (check(m))
			l = m;
		else
			r = m;
	}
	
	std::cout << (l == 0 ? -1 : l) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}