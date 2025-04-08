class Solution {
  public:
  
  void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,int c,int d){
      vis[node]=true;
      for(auto& it:adj[node]){
          if((node==c && it==d) || (node==d && it==c)) continue;
          if(!vis[it]){
              dfs(it,adj,vis,c,d);
          }
      }
  }
  
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
        dfs(c,adj,vis,c,d);
        if(vis[d]) return false;
        return true;
    }
};