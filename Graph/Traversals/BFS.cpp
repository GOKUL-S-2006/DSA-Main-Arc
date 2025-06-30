class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<bool> visited(adj.size(),0);
        queue<int>q;
        visited[0]=1;
        q.push(0);
        vector<int>bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
                
            }
        }
        return bfs;
        
        
        
    }
};
Measure	Complexity
Time	O(V + E)
Space	O(V)
