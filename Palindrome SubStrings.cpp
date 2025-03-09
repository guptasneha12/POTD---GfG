class Solution {
  public:
  
  int solve(int left,int right,string &s){
      int cnt=0;
      while(left>=0 && right<s.size()){
          if(s[left]==s[right]){
              cnt++;
              left--;
              right++;
          }else break;
      }
      return cnt;
  }
  
    int countPS(string &s) {
        int n=s.size();
        int oddcnt=0;
        int evencnt=0;
        // for odd
        for(int i=0;i<n;i++){
            oddcnt+=solve(i-1,i+1,s);
        }
        // for even
        for(int i=1;i<n;i++){
            evencnt+=solve(i-1,i,s);
        }
        return oddcnt+evencnt;
        
    }
};