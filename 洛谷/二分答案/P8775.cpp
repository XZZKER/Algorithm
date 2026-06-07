#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, x;
	std::cin >> n >> x;
	
	std::vector<int64> h(n);
	for (int i = 1; i < n; i++)
		std::cin >> h[i];
	
	std::vector<int64> s(n);
	for (int i = 1; i < n; i++)
		s[i] = s[i - 1] + h[i];
	
	auto check = [&](int m) -> bool {
		for (int i = 1; i + m <= n; i++)
			if (s[i + m - 1] - s[i - 1] < x * 2)
				return false;
		return true;
	};
	
	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (check(m))
			r = m;
		else
			l = m;
	}
	
	std::cout << r << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}