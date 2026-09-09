class Solution {
  public:
  int digitsum(int n){
      int sum=0;
      while(n>0){
          sum+=n%10;
          n=n/10;
      }
      return sum;
  }
    int findMax(int n) {
        // code Here
        string s=to_string(n);
        int ans=n;
        int bestsum=digitsum(n);
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') continue;
            string t=s;
            t[i]--; //decrease this num by 1
            for(int j=i+1;j<s.size();j++){
                t[j]='9';
            }
            int can=stoi(t);
            int sum=digitsum(can);
            if(sum>bestsum || (sum==bestsum && can>ans)){
                bestsum=sum;
                ans=can;
            }
            
        }

        
        return ans;
    }
};
