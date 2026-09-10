class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        if(y%x!=0) return 0; // lcm must be divisible by gcd
        int n=y/x;
        int cnt=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int j=n/i;
                if(__gcd(i,j)==1) cnt+=2; // for last line condition
            }
        }
        if(n==1) return 1;
        return cnt;
        
    }
};