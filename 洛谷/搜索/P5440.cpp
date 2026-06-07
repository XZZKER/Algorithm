#include <bits/stdc++.h>

bool is_prime(const int x) {
	if (x == 1)
		return false;
	if (x == 2)
		return true;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

std::set<int> legal;

void init() {
	const std::vector<int> md = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	for (int y = 1; y <= 9999; y++) {
		bool is_leap = y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
		for (int m = 1; m <= 12; m++) {
			for (int d = 1; d <= md[m] + (m == 2 && is_leap); d++) {
				if (!is_prime(d) || !is_prime(m * 100 + d) || !is_prime(y * 10000 + m * 100 + d))
					continue;
				legal.insert(y * 10000 + m * 100 + d);
			}
		}
	}
}

const std::vector<std::pair<char, char>> limit = {{'0', '9'}, {'0', '9'}, {'0', '9'}, {'0', '9'}, {'0', '1'}, {'0', '9'}, {'0', '3'}, {'0', '9'}};

void solve() {
	std::string s;
	std::cin >> s;
	
	std::vector<int> want;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '-')
			want.push_back(i);
	
	int ans = 0;
	for (int date : legal) {
		bool ok = true;
		for (int i = 7; i >= 0; i--) {
			if (s[i] != '-')
				ok &= s[i] - '0' == date % 10;
			date /= 10;
		}
		if (ok)
			ans++;
	}
	
	std::cout << ans << '\n';
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