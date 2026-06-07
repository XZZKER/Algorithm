#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> m >> n;
	
	std::vector<std::array<int, 3>> edges;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int v;
			std::cin >> v;
			edges.push_back({i, j, v});
		}
	}
	
	std::sort(edges.begin(), edges.end(), [](auto &x, auto &y) -> bool {
		return x[2] < y[2];
	});
	edges.erase(std::unique(edges.begin(), edges.end()), edges.end());
	
	int size = n;
	std::vector<int> pa(n);
	std::iota(pa.begin(), pa.end(), 0);
	
	auto find = [&](this auto &&find, int i) -> int {
		return pa[i] == i ? i : (pa[i] = find(pa[i]));
	};
	
	auto merge = [&](int i, int j) -> void {
		int x = find(i), y = find(j);
		if (x == y)
			return;
		pa[x] = y;
		size--;
	};
	
	int money = 0;
	for (auto &edge : edges) {
		if (find(edge[0]) != find(edge[1]) && edge[2] != 0 && edge[2] < m) {
			money += edge[2];
			merge(edge[0], edge[1]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (find(i) == i)
			money += m;
	}
	
	std::cout << money << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}