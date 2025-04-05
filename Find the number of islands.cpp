class Solution {
  public:
  
  void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>> &vis){
      int r=grid.size();
      int c=grid[0].size();
      vis[row][col]=true;
      vector<int> nr={-1, -1, -1, 0, 0, 1, 1, 1};
      vector<int> nc={-1, 0, 1, -1, 1, -1, 0, 1};
      for(int i=0;i<8;i++){
          int nrow=row+nr[i];
          int ncol=col+nc[i];
          if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && grid[nrow][ncol]=='L' && !vis[nrow][ncol]){
              dfs(nrow,ncol,grid,vis);
          }
      }
  }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    ++cnt;
                }
            }
        }
         return cnt;
        
    }
};