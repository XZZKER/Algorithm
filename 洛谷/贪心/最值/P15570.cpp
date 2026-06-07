#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::map<int, std::vector<int>> mp;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		mp[x % k].push_back(x / k);
	}
	
	int64 ans = 0;
	for (auto &[_, v] : mp) {
		std::sort(v.begin(), v.end());
		int mx = INT_MIN;
		for (int i : v) {
			if (i <= mx) {
				ans += mx + 1 - i;
				mx++;
			}
			else
				mx = i;
		}
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}