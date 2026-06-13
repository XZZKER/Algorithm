# Floyd

任意两点间的距离

## 代码

``````c++
std::vector<std::vector<int>> floyd(int n, std::vector<std::vector<int>> &edges) {
	std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
	for (auto &edge : edges)
        dis[edge[0]][edge[1]] = edge[2];
    
	for (int mid = 1; mid <= n; mid++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = std::min(dis[i][j], dis[i][mid] + d[mid][j]);
			}
		}
	}
    
    return dis;
}
``````



## 题目

### 基础

1. [模板](https://www.luogu.com.cn/problem/P2910)
2. 