#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> lsh;
	std::vector<std::array<int, 3>> abw(n);
	for (auto &i : abw) {
		std::cin >> i[0] >> i[1] >> i[2];
		lsh.push_back(i[0]);
		lsh.push_back(i[1] + 1);
	};
	
	std::sort(lsh.begin(), lsh.end());
	lsh.erase(std::unique(lsh.begin(), lsh.end()), lsh.end());
	int m = lsh.size();
	auto getId = [&](int x) -> int {
		return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin();
	};
	
	std::vector<std::vector<int64>> suf(m + 1, std::vector<int64>(2));
	for (auto &i : abw) {
		int lId = getId(i[0]), rId = getId(i[1] + 1);
		suf[lId][0]++;
		suf[rId][0]--;
		suf[lId][1] ^= i[2];
		suf[rId][1] ^= i[2];
	}
	
	for (int i = 1; i <= m; i++) {
		suf[i][0] += suf[i - 1][0];
		suf[i][1] ^= suf[i - 1][1];
	}
	
	int64 ans = -1;
	for (auto &i : suf) {
		if (i[0] >= k)
			ans = std::max(ans, i[1]);
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}