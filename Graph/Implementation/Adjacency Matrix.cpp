#inlude<bits/stdc++.h>
using namespace std;


UnDirected Graph
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}
Time Complexity:O(N^2)



Directed Graph

int main()
{
    int n, m;
    cin >> n >> m;
    
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
      
    }
    return 0;
}
// adjacency matrix for undirected graph
 time complexity: O(n)
