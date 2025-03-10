class Solution {
  public:
    int solve(int i,int j,string str1,string str2,vector<vector<int>> &dp){
      // base case
      // when any of the strings ends
      if(i<0) return j+1;
      if(j<0) return i+1;
      
      if(dp[i][j]!=-1) return dp[i][j];
      if(str1[i]==str2[j]) return dp[i][j]=solve(i-1,j-1,str1,str2,dp);
      
      return dp[i][j]=1+min(solve(i,j-1,str1,str2,dp),min(solve(i-1,j,str1,str2,dp),solve(i-1,j-1,str1,str2,dp)));;
  }
  
  
    int editDistance(string str1, string str2) {
       int n=str1.size();
       int m=str2.size();
       vector<vector<int>> dp(n,vector<int>(m,-1));
       return solve(n-1,m-1,str1,str2,dp);
    }
};