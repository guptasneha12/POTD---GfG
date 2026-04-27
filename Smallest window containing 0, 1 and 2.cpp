class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n=s.size();
        bool zero=false,one=false,two=false;
        int zi,oi,ti;
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero=true;
                zi=i;
            }
            else if(s[i]=='1'){
                one=true;
                oi=i;
            }
            else if(s[i]=='2'){
                two=true;
                ti=i;
            }
            if(one && two && zero){
                res=min(res,max({zi,oi,ti})-min({zi,oi,ti}));
            }
        }
        if(res==INT_MAX) return -1;
        else return res+1;
    }
};
