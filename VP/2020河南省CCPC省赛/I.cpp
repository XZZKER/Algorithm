#include <bits/stdc++.h>

typedef long long int64;

const int N = 5e6 + 10, MOD = 1e9 + 7;

std::vector<int64> fac(N), ifac(N);

int64 qsm(int64 a, int64 b) {
	a %= MOD;
	int64 tmp = 1;
	while (b) {
		if (b & 1)
			tmp = tmp * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return tmp;
}

int64 A(int64 n, int64 m) {
	return fac[n] * ifac[n - m] % MOD;
}

int64 C(int64 n, int64 m) {
	return A(n, m) * ifac[m] % MOD;
}

void init() {
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = fac[i - 1] * i % MOD;
	ifac[N - 1] = qsm(fac[N - 1], MOD - 2);
	for (int i = N - 1; i > 0; i--)
		ifac[i - 1] = ifac[i] * i % MOD;
}

void solve() {
	int n, r1, r2, r, a, h;
	std::cin >> n >> r1 >> r2 >> r >> a >> h;
	
	int t = (h + a - 1) / a;
	
	if (t > n) {
		std::cout << 0 << '\n';
		return;
	}
	if (r1 + r >= r2) {
		std::cout << 1 << '\n';
		return;
	}

	r1 += r;
	int64 s1 = 1LL * r1 * r1 % MOD, s2 = 1LL * r2 * r2 % MOD;
	int64 p = s1 * qsm(s2, MOD - 2) % MOD, q = (1 - p + MOD) % MOD, iq = qsm(q, MOD - 2);
	
	int64 ans = 0, pm = qsm(p, t), qm = qsm(q, n - t);
	for (int i = t; i <= n; i++) {
		int64 tmp = C(n, i) * pm % MOD * qm % MOD;
		ans = (ans + tmp) % MOD;
		pm = pm * p % MOD;
		qm = qm * iq % MOD;
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	init();
	
	solve();
	
	return 0;
}