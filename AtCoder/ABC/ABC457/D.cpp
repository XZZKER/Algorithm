#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n;
	int64 k;
	std::cin >> n >> k;
	
	int64 mn = LLONG_MAX, mx = LLONG_MIN;
	std::vector<int64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		mn = std::min(mn, a[i]);
		mx = std::max(mx, a[i]);
	}
	
	auto check = [&](int64 m) -> bool {
		int64 cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= m)
				continue;
			int64 add = (m - a[i]) / (i + 1) + ((m - a[i]) % (i + 1) != 0);
			if (cnt > k - add)
				return false;
			cnt += add;
		}
		return cnt <= k;
	};
		
	int64 l = 0, r = LLONG_MAX;
	while (l + 1 < r) {
		int64 m = (r - l) / 2 + l;
		if (check(m))
			l = m;
		else
			r = m;
	}
	
	std::cout << l << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	solve();
	
	return 0;
}