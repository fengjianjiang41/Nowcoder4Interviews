#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, vector<int>> mp;  // 邻接表存储图结构
// 使用map实现的邻接表，键是顶点编号，值是该顶点的邻接顶点列表
int dist[5001];            // 存储从起点到各顶点的距离
// 数组，dist[i]表示从起点到顶点i的最短距离，初始化为-1表示不可达

void Dijkstra(int start, int n) {
    bool ans = false;
    queue<int> qu;
    qu.push(start);
    dist[start] = 0;
    while (!qu.empty()) {
        start = qu.front();
        qu.pop();
        for (int i = 0; i < mp[start].size(); ++i) {
            int pos = mp[start][i];
            if (dist[pos] == -1) {
                dist[pos] = dist[start] + 1;
                if (pos == n) {
                    ans = true;
                    break;
                }
                qu.push(pos);
            }
        }
        if (ans)
            break;
    }
}

/* 虽然函数名为"Dijkstra"，但实际上实现的是BFS算法：

初始化：将起点加入队列，设置起点距离为0

处理队列：

取出队首顶点

遍历其所有邻接顶点

如果邻接顶点未被访问过（dist为-1），则：

设置其距离为当前顶点距离+1

如果找到目标顶点n，设置标志并提前退出

将该邻接顶点加入队列

提前终止：如果找到目标顶点，提前结束搜索 */

int main() {
    int n, m, from, to;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> from >> to;
        mp[from].push_back(to);
        mp[to].push_back(from);
    }
    for (int i = 0; i <= 5000; i++) {
        dist[i] = -1;
    }
    Dijkstra(1, n);
    cout << dist[n];
}
// 64 位输出请用 printf("%lld")

/*

时间复杂度：

O(V + E)，其中V是顶点数，E是边数

每个顶点和边最多被访问一次

空间复杂度：

O(V)用于存储距离

O(E)用于存储图结构 */

/*
与真正Dijkstra算法的区别
队列类型：

这里使用普通队列（FIFO）

Dijkstra使用优先队列（按距离排序）

边权处理：

这个算法假设所有边权相同（隐含为1）

Dijkstra可以处理不同权重的边

效率：

对于无权图，这个实现更高效

对于有权图，这个实现不适用 */
