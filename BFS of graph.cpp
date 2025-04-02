class Solution {
  public:
  
  void solve(int node,vector<vector<int>> &adj,vector<int> &list,vector<bool> vis){
      vis[node]=true;
      queue<int> q;
      q.push(node);
     
      while(!q.empty()){
          int it=q.front();
          q.pop();
          list.push_back(it);
          for(auto n:adj[it]){
              if(!vis[n]){
                  vis[n]=true;
                  q.push(n);
              }
          }
      }
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int> list;
        vector<bool> vis(n,false);
        
        solve(0,adj,list,vis);
        return list;
    }
};