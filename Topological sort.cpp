class Solution {
  public:
  
  void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,stack<int> &st){
      vis[node]=true;
      for(auto& it:adj[node]){
          if(!vis[it]){
              dfs(it,adj,vis,st);
          }
      }
      st.push(node);
  }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // using dfs
        stack<int> st;
        vector<bool> vis(V,false);
        vector<vector<int>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int> res;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            res.push_back(i);
        }
        return res;
    }
};