#include <bits/stdc++.h>

const std::vector<std::pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
	std::string st;
	std::cin >> st;
	
	auto bfs = [](std::string st, std::string ed) -> int {
		std::unordered_set<std::string> visited1, visited2;
		std::queue<std::string> q1, q2;
		visited1.insert(st);
		q1.push(st);
		visited2.insert(ed);
		q2.push(ed);
		
		int deep = 0;
		while (q1.size() && q2.size()) {
			auto &visited = q1.size() < q2.size() ? visited1 : visited2;
			auto &q = q1.size() < q2.size() ? q1 : q2;
			int size = q.size();
			while (size--) {
				auto u = q.front();
				q.pop();
				if (visited1.count(u) && visited2.count(u))
					return deep;
				for (int i = 0; i < 9; i++) {
					if (u[i] != '0')
						continue;
					int row = i / 3, col = i % 3;
					for (auto &[dr, dc] : dir) {
						int newRow = row + dr, newCol = col + dc;
						if (newRow < 0 || newRow >= 3 || newCol < 0 || newCol >= 3)
							continue;
						auto v = u;
						std::swap(v[i], v[newRow * 3 + newCol]);
						if (visited.count(v) != 0)
							continue;
						visited.insert(v);
						q.push(v);
					}
					break;
				}
			}
			deep++;
		}
		return -1;
	};
	
	std::cout << bfs(st, "123804765") << '\n';
}

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	solve();
	
	return 0;
}