class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int etime=0;
        while(!q.empty()){
            etime++;
            int l=q.size();
            while(l--){
            vector<int> f=q.front();
            q.pop();
            int i=f[0];
            int j=f[1];
            for(auto& it:dir){
                int x=i+it[0];
                int y=j+it[1];
                if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1){
                    mat[x][y]=2;
                    q.push({x,y});
                }
            }
            }
            
        }
        
        // check for remaining fresh oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) return -1;
            }
        }
        return max(0,etime-1);
    }
};