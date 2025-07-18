#include<iostream>
#include<vector>
#include<queue>

#define MAX 200001
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adjlist[MAX]; // 用于模拟邻接表的vector容器
    int inDegree[MAX] = {0}; // 用于记录每个顶点入度的数组，初始值全部设置为0
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adjlist[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> que;
    for(int i = 1; i <= n; i++)
    {
        if(inDegree[i] == 0) // 将初始入度为0的顶点全部入队
        {
            que.push(i);
        }
    }
    int cnt = 0; // 用于判断图中是否存在环的计数器
    vector<int> res; // 用于存储结果序列的数组
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        res.push_back(u); // 存储结果用于输出
        for(int i = 0; i < adjlist[u].size(); i++) // 遍历该顶点指向的其他顶点
        {
            int v = adjlist[u][i];
            inDegree[v]--; // 被指向的顶点的入度减一
            if(inDegree[v] == 0) // 若顶点的入度减为0，则将其入队
            {
                que.push(v);
            }
        }
        cnt++;
    }
    if(cnt == n) // 若计数器与顶点数相同则图无环，存在拓扑序列
    {
        for(int i = 0; i < res.size(); i++)
        {
            cout<<res[i];
            if(i != res.size() - 1) // 此处注意：本题最后一个数字后不能输出多余空格，因此需要进行该判断
            {
                cout<<" ";
            }
        }
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
