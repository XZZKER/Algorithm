#include <bits/stdc++.h>

void solve() {
	int n, l;
	std::cin >> n >> l;
	
	std::vector<std::pair<int, int>> d(n);
	for (int i = 0; i < n; i++) {
		std::cin >> d[i].first;
		d[i].second = i + 1;
	}
	
	if (l == 1) {
		std::cout << -1 << '\n';
		return;
	}
	
	std::sort(d.begin(), d.end(), std::greater<>());
	
	for (int i = n - l; i < n; i++)
		d[i].first = 1;
	
	int nx = 1;
	std::queue<int> q;
	std::vector<std::pair<int, int>> ans;
	q.push(0);
	
	while (q.size() && nx < n) {
		int u = q.front();
		q.pop();
		while (d[u].first && nx < n && q.size() < l) {
			ans.push_back({d[u].second, d[nx].second});
			d[u].first--;
			d[nx].first--;
			q.push(nx);
			nx++;
		}
	}
	
	if (nx < n) {
		std::cout << -1 << '\n';
		return;
	}
	
	for (auto [u, v] : ans)
		std::cout << u << ' ' << v << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}