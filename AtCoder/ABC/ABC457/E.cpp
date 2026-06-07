#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::map<std::pair<int, int>, int> cnt;
	std::map<int, std::vector<int>> by_l, by_r;
	std::vector<int> min_r(n + 2, INT_MAX);
	for (int i = 0; i < m; i++) {
		int l, r;
		std::cin >> l >> r;
		cnt[{l, r}]++;
		by_l[l].push_back(r);
		by_r[r].push_back(l);
		if (r < min_r[l])
			min_r[l] = r;
	}
	
	for (auto &[_, v] : by_l) {
		std::sort(v.begin(), v.end());
	}
	for (auto &[_, v] : by_r) {
		std::sort(v.begin(), v.end());
	}
	
	std::vector<int> suf_min_r(n + 3, INT_MAX);
	for (int i = n + 1; i >= 1; i--) {
		suf_min_r[i] = std::min(min_r[i], suf_min_r[i + 1]);
	}
	
	int q;
	std::cin >> q;
	
	while (q--) {
		int s, t;
		std::cin >> s >> t;
		
		if (cnt[{s, t}] > 0) {
			bool ok = false;
			ok |= cnt[{s, t}] >= 2;
			ok |= suf_min_r[s] <= t - 1;
			ok |= suf_min_r[s + 1] <= t;
			std::cout << (ok ? "Yes" : "No") << '\n';
			continue;
		}
		
		auto &s_r = by_l[s];
		auto s_r_pos = upper_bound(s_r.begin(), s_r.end(), t) - s_r.begin() - 1;
		
		auto &t_l = by_r[t];
		auto t_l_pos = lower_bound(t_l.begin(), t_l.end(), s) - t_l.begin();
		
		bool ok = false;
		if (s_r_pos >= 0 && t_l_pos < (int)t_l.size()) {
			ok |= s_r[s_r_pos] >= t_l[t_l_pos] - 1;
		}
		
		std::cout << (ok ? "Yes" : "No") << '\n';
	}
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}