class Solution {
  public:
     void dfs(int node,vector<bool> &vis,vector<int> &ls,vector<vector<int>>& adj){
           vis[node]=1;
           ls.push_back(node);
           for(auto it:adj[node]){
               if(!vis[it]){
                   vis[it]=1;
                    dfs(it,vis,ls,adj);
        }
           }
           
     }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>vis(n,0);
        int start=0;
        vector<int>ls;
        dfs(start,vis,ls,adj);
        return ls;
        
    }
};

| Measure   | Complexity |
| --------- | ---------- |
| **Time**  | O(V + E)   |
| **Space** | O(V)       |
