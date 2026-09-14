class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(); // row
        int m=mat[0].size(); // col
        vector<vector<int>> temp=mat; // not to make changes in original mat
        // to traverse in all 4 directions
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<4;k++){
                        int ni=i+row[k];
                        int nj=j+col[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<m){
                            temp[ni][nj]=0;
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>> q;
        // store all 0th col elem in queue and apply multisource bfs
        for(int i=0;i<n;i++){
            if(temp[i][0]==1){
                q.push({{i,0},1});
            }
        }
        // apply BFS
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first.first;
            int j=it.first.second;
            // if we reach rightmost edge then return moves
            if(j==m-1) {
                return it.second;
            }
            for(int k=0;k<4;k++){
                int ni=i+row[k];
                int nj=j+col[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m && temp[ni][nj]==1 && vis[ni][nj]==-1){
                    vis[ni][nj]=1;
                    q.push({{ni,nj},it.second+1});
                }
            }
        }
        return -1; // if no moves exist;
    }
};