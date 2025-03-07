class Solution {
  public:
  int solve(string &s,int low,int high,vector<vector<int>> &dp){
      if(low>high) return 0;
      // if only 1 ele is present
      if(low==high) return 1;
      if(dp[low][high]!=-1) return dp[low][high];
      if(s[low]==s[high]){
         return dp[low][high]=solve(s,low+1,high-1,dp)+2;
      }
      return dp[low][high]=max(solve(s,low+1,high,dp),solve(s,low,high-1,dp));
  }
    int longestPalinSubseq(string &s) {
        int n=s.size();
        // create 2-D DP
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(s,0,n-1,dp);
    }
};