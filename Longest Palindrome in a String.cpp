class Solution {
  public:
  int length(int start,int end,string &s){
      int len=0;
      int n=s.size();
      while(start>=0 && end<n){
          if(s[start]==s[end]){
              len+=2;
              start--;
              end++;
          } else break;
      }
      return len;
  }
    string longestPalindrome(string &s) {
        int n=s.size();
        int start=0;
        int maxi=1;
        
        // for odd
        // take only left and right ele of single element
        for(int i=0;i<n;i++){
            int len=1+length(i-1,i+1,s);
            if(len>maxi){
                maxi=len;
                start=i-len/2;
            }
        }
        
        // for even
        // take lwft and right ele of two pair of elements
        for(int i=1;i<n;i++){
            int len=length(i-1,i,s);
            if(len>maxi){
                maxi=len;
                start=i-len/2;
            }
        }
        
        return s.substr(start,maxi);
        
        
    }
};