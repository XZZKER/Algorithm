#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, k, m;
	std::cin >> n >> k >> m;
	
	std::vector<std::pair<int64, int>> vc(n);
	for (auto &[v, c] : vc)
		std::cin >> c >> v;
	
	std::sort(vc.begin(), vc.end(), std::greater<>());
	
	int64 ans = 0;
	std::set<int> visited;
	std::vector<bool> used(n);
	for (int i = 0; i < n; i++) {
		auto [v, c] = vc[i];
		if (visited.count(c))
			continue;
		if ((int)visited.size() >= m)
			break;
		ans += v;
		visited.insert(c);
		used[i] = true;
		k--;
	}
	
	for (int i = 0; i < n; i++) {
		auto [v, c] = vc[i];
		if (used[i])
			continue;
		if (k <= 0)
			break;
		ans += v;
		k--;
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}