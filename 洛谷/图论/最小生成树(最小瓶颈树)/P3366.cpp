#include <bits/stdc++.h>

std::pair<int, bool> kruskal(int n, std::vector<std::array<int, 3>> &edges) {
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
	
	std::sort(edges.begin(), edges.end(), [](auto &x, auto &y) -> bool {
		return x[2] < y[2];
	});
	
	int weight = 0;
	for (auto &edge : edges) {
		if (find(edge[0]) != find(edge[1])) {
			weight += edge[2];
			merge(edge[0], edge[1]);
		}
	}
	
	return {weight, size == 1};
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::array<int, 3>> edges(m);
	for (int i = 0; i < m; i++) {
		auto &edge = edges[i];
		std::cin >> edge[0] >> edge[1] >> edge[2];
		edge[0]--;
		edge[1]--;
	}
	
	auto [ans, ok] = kruskal(n, edges);
	
	std::cout << (ok ? std::to_string(ans) : "orz") << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}