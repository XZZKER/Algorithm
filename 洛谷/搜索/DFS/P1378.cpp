#include <bits/stdc++.h>

const double pi = acos(-1);

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<double> edge_x(2), edge_y(2);
	std::cin >> edge_x[0] >> edge_y[0] >> edge_x[1] >> edge_y[1];
	
	std::sort(edge_x.begin(), edge_x.end());
	std::sort(edge_y.begin(), edge_y.end());
	
	std::vector<std::pair<double, double>> pos(n);
	for (auto &[x, y] : pos)
		std::cin >> x >> y;
	
	double ans = 0;
	std::vector<bool> used(n);
	std::vector<std::tuple<double, double, double>> circles(n);
	auto dfs = [&](this auto &&dfs, int l) -> void {
		if (l >= n) {
			double res = 0;
			for (auto &[_, __, r] : circles)
				res += pi * r * r;
			ans = std::max(ans, res);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (used[i])
				continue;
			auto &[x, y] = pos[i];
			double r = std::min({std::abs(edge_x[0] - x), std::abs(edge_x[1] - x), std::abs(edge_y[0] - y), std::abs(edge_y[1] - y)});
			for (int j = 0; j < l; j++) {
				auto &[xx, yy, rr] = circles[j];
				double dis = std::sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
				r = std::min(r, std::max(dis - rr, 0.0));
			}
			circles[l] = {x, y, r};
			used[i] = true;
			dfs(l + 1);
			used[i] = false;
		}
	};
	
	dfs(0);
	
	std::cout << std::fixed << std::setprecision(0) << (edge_x[0] - edge_x[1]) * (edge_y[0] - edge_y[1]) - ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}