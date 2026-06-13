# Dijkstra

## 模板

### 普通

``````c++
std::vector<int> Dijkstra(int n, std::vector<std::vector<int>> &g, int st) {
    vector<int> dis(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    dis[st] = 0;
    q.push({0, st});
    
    while (q.size()) {
        auto [uDis, u] = q.top();
        q.pop();
        if (uDis > dis[u])
            continue;
        for (auto &[v, w] : g[u]) {
            if (uDis + w >= dis[v])
                continue;
            dis[v] = uDis + w;
            q.push({dis[v], v});
        }
    }
    return dis;
}
``````



### 反向索引堆优化



## 题目

1. [模板](https://leetcode.cn/problems/network-delay-time)
1. [最值版](https://leetcode.cn/problems/path-with-minimum-effort)
1. [最值版](https://leetcode.cn/problems/swim-in-rising-water)

