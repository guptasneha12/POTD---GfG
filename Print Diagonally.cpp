class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n=mat.size();
        vector<int> res;
        // total diagonal 2*n-1
        for(int i=0;i<2*n-1;i++){
            int row=(i<n)?0:i-n+1;
            int col=(i<n)?i:n-1;
            while(row<n && col>=0){
                res.push_back(mat[row][col]);
                row++;
                col--;
            }
        }
        return res;
        
    }
};