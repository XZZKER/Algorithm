#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<std::pair<int, int>> lh(n);
	for (auto &[l, h] : lh)
		std::cin >> h >> l;
	
	std::sort(lh.begin(), lh.end(), std::greater<>());
	
	int q;
	std::cin >> q;
	
	std::vector<std::pair<int, int>> qi(q);
	for (int i = 0; i < q; i++) {
		qi[i].second = i;
		std::cin >> qi[i].first;
	}
	
	std::sort(qi.begin(), qi.end(), std::greater<>());
	
	int res = 0;
	std::vector<int> ans(q);
	for (int i = 0, j = 0; i < q; i++) {
		while (j < n && lh[j].first > qi[i].first) {
			res = std::max(res, lh[j].second);
			j++;
		}
		ans[qi[i].second] = res;
	}
	
	for (int i = 0; i < q; i++)
		std::cout << ans[i] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}