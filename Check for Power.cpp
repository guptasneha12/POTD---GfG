class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        
        // BRUTE FORCE
        // if(x==1) return (y==1);
        // int p=1;
        // while(p<y){
        //     p*=x;
        // }
        // return (p==y);
        
        
        if(x==1) return (y==1);
        if(y==1) return true;
        double res= log(y)/log(x);
        return fabs(res - round(res)) < 1e-10;
    }
};