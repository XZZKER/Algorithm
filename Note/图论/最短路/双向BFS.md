# 双向BFS

## 模板

``````c++
int BidirectionalBFS(int n, std::vector<std::vector<int>> &g, int st, int ed) {
    std::vector<int> dis1(n), dis2(n);
    dis1[st] = 0;
    dis2[ed] = 0;
    queue<int> q1, q2;
    q1.push(st);
    q2.push(ed);

    while (q1.size() && q2.size()) {
        auto &q = q1.size() < q2.size() ? q1 : q2;
        auto &dis = q1.size() < q2.size() ? dis1 : dis2;
        int size = q.size();
        while (size--) {
            int u = q.front();
            q.pop();
            for (auto &v : g[u]) {
                if (dis.count(v) != 0)
                    continue;
                dis[v] = dis[u] + 1;
                q.push(v);
                if (dis1.count(v) && dis2.count(v))
                    return dis1[v] + dis2[v] + 1;
            }
        }
    }
    return -1;
}
``````



## 题目

[模板](https://leetcode.cn/problems/word-ladder)