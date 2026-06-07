#include <bits/stdc++.h>

std::vector<int> primes;

void init() {
	const int N = 1e5 + 10;
	std::vector<bool> is_prime(N, true);
	for (int i = 2; i < N; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (long long j = 1LL * i * i; j < N; j += i)
				is_prime[j] = false;
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	
	std::unordered_map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		for (int p : primes) {
			if (x % p == 0) {
				cnt[p]++;
				while (x % p == 0)
					x /= p;
			}
		}
	}
	
	int res = 0;
	for (auto [_, c] : cnt)
		res = std::max(res, c);
	
	std::cout << (res == 0 ? -1 : n - res) << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	init();
	
	int t;
	std::cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}