class Solution {
  public:
  int solve(int start,int end,vector<int> &arr,vector<vector<int>> &dp){
      // base case
      if(end-start==1) return 0;    // if only 1 element is present
      if(dp[start][end]!=-1) return dp[start][end];
      int ans=INT_MAX;
      for(int i=start+1;i<end;i++){
          int left=solve(start,i,arr,dp);
          int right=solve(i,end,arr,dp);
          ans=min(ans,left+right+arr[start]*arr[i]*arr[end]);
      }
      return dp[start][end]=ans;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,arr,dp);
    }
};