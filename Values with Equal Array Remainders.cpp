class Solution {
  public:
    int sameMod(vector<int> &arr) {
        // code here
        int n=arr.size();
        int g=0;
        // find gcd of diff of numbers
        for(int i=1;i<n;i++){
            g=__gcd(g,abs(arr[i]-arr[0]));
        }
        // if nums are same then infinite count exist
        if(g==0) return -1;
        // find all divisors of gcd
        int cnt=0;
        for(int i=1;i*i<=g;i++){
            if(g%i==0){
                cnt++;
                // for unique pair
                if(i!=g/i){
                    cnt++;
                }
        }
        
    }
    return cnt;
    }
};