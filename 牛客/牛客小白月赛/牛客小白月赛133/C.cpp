#include <bits/stdc++.h>

typedef long long int64;

const std::string s1 = "awdec", s2 = "Fantasy_Blue";

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::string s;
	std::cin >> s;
	
	std::vector<std::vector<int>> pos1(k + 1), pos2(k + 1);
	for (int i = 0; i < n; i++) {
		if (i + 4 < n) {
			int cnt = 0;
			for (int j = 0; j < 5; j++)
				cnt += s[i + j] != s1[j];
			if (cnt <= k)
				pos1[cnt].push_back(i);
		}
		if (i + 11 < n) {
			int cnt = 0;
			for (int j = 0; j < 12; j++)
				cnt += s[i + j] != s2[j];
			if (cnt <= k)
				pos2[cnt].push_back(i);
		}
	}
	
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}