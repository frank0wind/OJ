#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
//输入：图graph，起点start
//输出：从起点start到其他点的最短距离
//时间复杂度：O(n^2)
//Dijkstra算法（邻接矩阵）
vector<int> dijkstra(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}
//输入：图graph，起点start
//输出：从起点start到其他点的最短距离
//时间复杂度：O(nlogn)
//Dijkstra算法（邻接表）
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
vector<int> dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            int weight = graph[u][i].weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}
//输入：图graph
//输出：从任意点到任意点的最短距离
//时间复杂度：O(n^3)
//Flyod算法
vector<vector<int>> flyod(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u][k] != numeric_limits<int>::max() && dist[k][v] != numeric_limits<int>::max() && dist[u][k] + dist[k][v] < dist[u][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
    return dist;
}
//输入：图graph，节点数n，边数m
//输出：图graph
//时间复杂度：O(m)
//输入图(有向带权图，从0-0开始)
vector<vector<int>> input(vector<vector<int>>& graph,int n,int m)
{
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a][b]=c;
    }
    return graph;
}
//输入图(有向带权图，从1-1开始)
vector<vector<int>> input(vector<vector<int>>& graph,int n,int m)
{
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        graph[a][b]=c;
    }
    return graph;
}
//输入：图graph，节点数n，边数m
//输出：图graph
//时间复杂度：O(m)
//输入图(无向带权图，从0-0开始)
vector<vector<int>> input(vector<vector<int>>& graph,int n,int m)
{
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    return graph;
}
//输入图(无向图带权图，从1-1开始)
vector<vector<int>> input(vector<vector<int>>& graph,int n,int m)
{
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    return graph;
}
//输入：图graph
//输出图
void output(vector<vector<int>>& graph)
{
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
//输入：图graph，节点数n，边数m
//输出：图graph
//输入图（有向带权邻接表法）
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
vector<vector<Edge>> input(vector<vector<Edge>>& graph,int n,int m)
{
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a].push_back(Edge(b,c));
    }
    return graph;
}
//输入：图graph，反向图graph2，节点数n，边数m
//输入图（有向带权邻接表法-正反图）
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
vector<vector<vector<Edge>>> input(vector<vector<Edge>>& graph,vector<vector<Edge>>& graph2,int n,int m)
{
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a].push_back(Edge(b,c));
        graph2[b].push_back(Edge(a,c));
    }
    vector<vector<vector<Edge>>> graph3;
    graph3.push_back(graph);
    graph3.push_back(graph2);
    return graph3;
}

