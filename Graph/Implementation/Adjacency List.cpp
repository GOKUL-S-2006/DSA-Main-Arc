Undirected graph:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    for(int i=1;i<n;i++){
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}

SC->O(2E)

Directed graph:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    
    for(int i=1;i<n;i++){
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}

sc->(E)
