#include <bits/stdc++.h>

typedef long long int64;

void solve() {
	int n, d;
	std::cin >> n >> d;
	
	std::vector<int64> a(1000010);
	while (n--) {
		int s, t;
		std::cin >> s >> t;
		if (s + d <= t)
		{
			a[s]++;
			a[t - d + 1]--;
		}
	}
	
	int64 s = 0, ans = 0;
	for (int i = 1; i < 1000010; i++) {
		s += a[i];
		ans += s * (s - 1) / 2;
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve();
	
	return 0;
}