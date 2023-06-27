#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
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
int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    vector<vector<int>> graph(n+1,vector<int>(n+1,0));
    graph=input(graph,n,m);
    vector<vector<int>> dist=dijkstra(graph);
    int max=0;
    for(int i=1;i<=n;i++)
    {
        int q;
        q=dist[i][x]+dist[x][i];
        if(q>max)
        {
            max=q;
        }
    }
    cout<<max<<endl;
}
