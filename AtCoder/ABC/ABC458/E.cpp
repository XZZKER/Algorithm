#include <bits/stdc++.h>

typedef long long int64;

const int mod = 998244353;

class Math {
	typedef long long int64;

	int n, mod;
	std::vector<int64> fac, ifac;
	
	int64 power(int64 a, int64 n) {
		int64 tmp = 1;
		a %= mod;
		while (n) {
			if (n & 1) tmp = tmp * a % mod;
			a = a * a % mod;
			n >>= 1;
		}
		return tmp;
	}
	
public:
	Math(int n, int mod) : n(n), mod(mod), fac(n), ifac(n) {
		// 阶层
		fac[0] = 1;
		for (int i = 1; i < n; i++)
			fac[i] = fac[i - 1] * i % mod;
		ifac[n - 1] = power(fac[n - 1], mod - 2);
		for (int i = n - 2; i >= 0; i--)
			ifac[i] = ifac[i + 1] * (i + 1) % mod;
	}
	
	int64 A(int n, int k) {
		return fac[n] * ifac[n - k] % mod;
	}
	
	int64 C(int n, int k) {
		return A(n, k) * ifac[k] % mod;
	}
};

void solve() {
	int x1, x2, x3;
	std::cin >> x1 >> x2 >> x3;
	
	int64 ans = 0;
	int g = x2 + 1;
	int lim = std::min({x1, x3, g});
	Math math(2000010, 998244353);
	for (int i = 0; i <= lim; i++) {
		// g个间隙选i个当违规间隙
		int64 cur = math.C(g, i);
		// i个违规间隙先都放1个1，剩下x1 - i个1分配到g个间隙（隔板法）
		cur = cur * math.C(g + x1 - i - 1, x1 - i) % mod;
		// i个违规间隙先都放1个3，剩下x1 - i个3分配到g个间隙（隔板法）
		cur = cur * math.C(g + x3 - i - 1, x3 - i) % mod;
		// 容斥原理
		ans = i & 1 ? (ans - cur + mod) % mod : (ans + cur) % mod;
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}