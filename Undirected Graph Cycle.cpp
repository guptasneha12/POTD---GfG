class Solution {
  public:
  
  bool detect(int src,vector<vector<int>>& adj,vector<bool> &vis){
      vis[src]=true;
      queue<pair<int,int>> q;
      q.push({src,-1});
      while(!q.empty()){
          int node=q.front().first;
          int par=q.front().second;
          q.pop();
          for(auto& it:adj[node]){
              if(!vis[it]){
                  vis[it]=true;
                  q.push({it,node});
              }
              else if(it!=par) return true;
          }
      }
      return false;
      
  }
  
    bool isCycle(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
        
        
    }
};